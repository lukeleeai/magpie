#include "stdc++.h"

using namespace std;

using graph = vector<vector<int>>;



class LCA {

	using pii = pair<int, int>;

	const int n;

	vector<int> depth, dde, par, heavy, head;

	int dfs(int v, int prev, const graph& G) {

		par[v] = prev;

		int ma = 0, res = 1;

		for (auto to : G[v]) if (to != prev) {

			depth[to] = depth[v] + 1;

			int size = dfs(to, v, G);

			res += size;

			if (size > ma) {

				ma = size;

				heavy[v] = to;

			}

		}

		return res;

	}

public:

	LCA(const graph& G, int rt = 0)

		: n(G.size()), depth(n), dde(n), par(n), heavy(n, -1), head(n) {

		dfs(rt, -1, G);

		queue<int> q;

		q.push(rt);

		head[rt] = rt;

		while (!q.empty()) {

			int v = q.front(); q.pop();

			while (v != -1) {

				for (auto to : G[v]) if (to != par[v] && to != heavy[v]) {

					q.push(to);

					dde[to] = dde[v] + 1;

					head[to] = to;

				}

				if (heavy[v] != -1) {

					dde[heavy[v]] = dde[v];

					head[heavy[v]] = head[v];

				}

				v = heavy[v];

			}

		}

	}

	int calc(int u, int v) {

		if (dde[u] > dde[v]) swap(u, v);

		while (dde[u] < dde[v]) v = par[head[v]];

		while (head[u] != head[v]) u = par[head[u]], v = par[head[v]];

		return depth[u] < depth[v] ? u : v;

	}

	int dist(int a, int b) {

		return depth[a] + depth[b] - depth[calc(a, b)] * 2;

	}

};



int main()

{

	ios::sync_with_stdio(false), cin.tie(0);

	int n;

	cin >> n;

	graph G(n);

	for (int i = 0; i < n; i++) {

		int k;

		cin >> k;

		for (int j = 0; j < k; j++) {

			int c;

			cin >> c;

			G[i].push_back(c);

			G[c].push_back(i);

		}

	}

	LCA lca(G);

	int q;

	cin >> q;

	while (q--) {

		int u, v;

		cin >> u >> v;

		printf("%d\n", lca.calc(u, v));

	}

	return 0;

}


