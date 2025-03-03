#include "stdc++.h"

#define SZ(x) ((int)x.size())

#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;

typedef long double ld;

int n, m;

int a[15], used[15], res;

char s[15][15];

void f(int cur) {

	if(cur == n + 1) {

		bool usedMiddle = 0;

		for(int i=1; i<=m; i++) used[i] = 0;

		for(int i=1; i<=m; i++) {

			if(used[i]) continue;

			bool found = 0;

			for(int j=i+1; j<=m; j++) {

				if(used[j]) continue;

				bool flag = 1;

				for(int k=1; k<=n; k++)

					if(s[k][i] != s[a[k]][j] || s[a[k]][i] != s[k][j])

						{ flag = 0; break; }

				if(flag) {

					used[i] = used[j] = 1;

					found = 1;

					break;

				}

			}

			if(!found) {

				if(m % 2 == 0) return;

				if(usedMiddle) return;

				bool flag = 1;

				for(int k=1; k<=n; k++)

					if(s[k][i] != s[a[k]][i])

						{ flag = 0; break; }

				if(!flag) return;

				used[i] = 1;

				usedMiddle = 1;

			}

		}

		res = 1;

		return;

	}

	if(a[cur] != 0) {

		f(cur + 1);

		return;

	}

	for(int i=cur+1; i<=n; i++) {

		if(a[i] != 0) continue;

		a[cur] = i;

		a[i] = cur;

		f(cur + 1);

		a[cur] = a[i] = 0;

	}

}

int main() {

	scanf("%d%d", &n, &m);

	for(int i=1; i<=n; i++)

		scanf("%s", &s[i][1]);

	if(n & 1) {

		for(int i=1; i<=n; i++) {

			a[i] = i;

			f(1);

			a[i] = 0;

		}

	} else f(1);

	puts(res ? "YES" : "NO");

	return 0;

}