#include"stdc++.h"

using namespace std;



const int N = 1e5 + 10;

int n, L, q;

int a[N];

int f[N][33];



inline int read() {

	int s = 0, f = 1;

	char ch;

	for(; ch < '0' || ch > '9'; ch = getchar())	if(ch == '-')	f = -1;

	for(; ch >= '0' && ch <= '9'; ch = getchar())	s = (s << 1) + (s << 3) + ch - '0';

	return s * f;

}



int main() {

	n = read();

	for(int i = 1; i <= n; ++i) a[i] = read();

	L = read(), q = read();

	for(int i = 1; i <= n; ++i) {

		int x = upper_bound(a + 1, a + n + 1, a[i] + L) - a - 1;

		if(a[i] + L >= a[n])	f[i][0] = n;

		else	f[i][0] = x;

	}

	for(int j = 1; j <= 30; ++j)

		for(int i = 1; i <= n; ++i)

			f[i][j] = f[f[i][j - 1]][j - 1];

	while(q--) {

		int l = read(), r = read();

		if(l > r)	swap(l, r);

		int cnt = l, ans = 0;

		for(int i = 30; i >= 0; --i) {

			if(f[cnt][i] < r) {

				ans += (1 << i);

				cnt = f[cnt][i];

			}

		}

		printf("%d\n", ans + 1);

	}

	return 0;

}