#include <cstdio>

#include <vector>

using namespace std;

int n, m, a, b, cnt, col[100009]; vector<int> g[100009];

bool dfs(int pos) {

	bool ret = true; cnt++;

	for (int i : g[pos]) {

		if (col[i] == col[pos]) ret = false;

		if (col[i] == 0) {

			col[i] = 3 - col[pos];

			if (!dfs(i)) ret = false;

		}

	}

	return ret;

}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {

		scanf("%d %d", &a, &b); a--, b--;

		g[a].push_back(b);

		g[b].push_back(a);

	}

	int c0 = 0, c1 = 0, c2 = 0;

	for (int i = 0; i < n; i++) {

		if (col[i] == 0) {

			col[i] = 1; cnt = 0;

			bool res = dfs(i);

			if (cnt == 1) c0++;

			else if (!res) c1++;

			else c2++;

		}

	}

	printf("%lld\n", 1LL * (c1 + c2) * (c1 + c2) + 1LL * c2 * c2 + 1LL * n * n - 1LL * (n - c0) * (n - c0));

	return 0;

}