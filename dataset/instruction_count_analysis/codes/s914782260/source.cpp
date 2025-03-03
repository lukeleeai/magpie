#include"stdc++.h"

#define MOD 1000000007

#define INF 0x3f3f3f3f

#define INFL 0x3f3f3f3f3f3f3f3f

#define EPS (1e-10)

#define rep(i,n)for(int i=0;i<(n);i++)

using namespace std;

typedef long long ll;

typedef pair<int, int>P;

#define prv(i)((i+n-1)%n)

#define nxt(i)((i+1)%n)



int b[100000];

int n; string s;



bool bfs(int a, int m, int c) {

	memset(b, -1, sizeof(b));

	b[prv(0)] = a; b[0] = m; b[nxt(0)] = c;

	queue<int>que; que.push(prv(0)); que.push(nxt(0));

	while (!que.empty()) {

		int p = que.front(); que.pop();

		if (b[p]) {//本当

			if (~b[prv(p)] && !~b[nxt(p)]) {

				if (s[p] == 'o')b[nxt(p)] = b[prv(p)];

				else b[nxt(p)] = !b[prv(p)];

				que.push(nxt(p));

			}

			if (~b[nxt(p)] && !~b[prv(p)]) {

				if (s[p] == 'o')b[prv(p)] = b[nxt(p)];

				else b[prv(p)] = !b[nxt(p)];

				que.push(prv(p));

			}

		}

		else {//うそ

			if (~b[prv(p)] && !~b[nxt(p)]) {

				if (s[p] == 'o')b[nxt(p)] = !b[prv(p)];

				else b[nxt(p)] = b[prv(p)];

				que.push(nxt(p));

			}

			if (~b[nxt(p)] && !~b[prv(p)]) {

				if (s[p] == 'o')b[prv(p)] = !b[nxt(p)];

				else b[prv(p)] = b[nxt(p)];

				que.push(prv(p));

			}

		}

	}

	rep(i, n) {

		if (b[i]) {

			if (!((s[i] == 'o'&&b[prv(i)] == b[nxt(i)]) || (s[i] == 'x'&&b[prv(i)] != b[nxt(i)])))return false;

		}

		else {

			if (!((s[i] == 'o'&&b[prv(i)] != b[nxt(i)]) || (s[i] == 'x'&&b[prv(i)] == b[nxt(i)])))return false;

		}

	}

	return true;

}

signed main() {

	cin >> n >> s;

	rep(i, 2)rep(j, 2)rep(k, 2) {

		if (bfs(i, j, k)) {

			rep(t, n) {

				if (b[t])printf("S");

				else printf("W");

			}

			printf("\n"); return 0;

		}

	}

	puts("-1");

}