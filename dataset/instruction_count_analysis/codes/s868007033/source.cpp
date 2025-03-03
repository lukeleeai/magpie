#include "stdc++.h"

using namespace std;



typedef long long ll;

const int maxn = 2e5;

int n, a[maxn + 3], b[maxn + 3], nxt[maxn + 3];

int k, p, c[maxn + 3], vis[maxn + 3], sz, ans[maxn + 3];

ll m;



void solve(int x) {

	for (int i = 1; i <= maxn; i++) {

		b[i] = 0;

	}

	for (int i = x; i <= n; i++) {

		if (!b[a[i]]) {

			ans[++sz] = a[i];

			b[a[i]] = sz;

		} else {

			int t = sz;

			sz = b[a[i]] - 1;

			for (int j = b[a[i]]; j <= t; j++) {

				b[ans[j]] = 0, ans[j] = 0;

			}

		}

	}

	for (int i = 1; i <= sz; i++) {

		printf("%d%c", ans[i], " \n"[i == sz]);

	}

}



int main() {

	scanf("%d %lld", &n, &m);

	for (int i = 1; i <= n; i++) {

		scanf("%d", &a[i]);

	}

	if (m == 1) {

		solve(1);

		return 0;

	}

	for (int i = n; i; i--) {

		b[a[i]] = i;

	}

	for (int i = n; i; i--) {

		nxt[i] = b[a[i]];

		b[a[i]] = i;

		if (nxt[i] > i) {

			nxt[i] = nxt[nxt[i] + 1];

		}

	}

	c[1] = 1;

	vis[1] = 1;

	for (int i = 2; i <= n + 2; i++) {

		if (c[i - 1] == n + 1) {

			c[i] = 1;

		} else {

			c[i] = nxt[c[i - 1]] + 1;

		}

		if (m == i) {

			solve(i);

			return 0;

		}

		if (vis[c[i]]) {

			k = i - vis[c[i]];

			p = vis[c[i]];

			solve(c[(m - p) % k + p]);

			return 0;

		}

		vis[c[i]] = i;

	}

	return 0;

}