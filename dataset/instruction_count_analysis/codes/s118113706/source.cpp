#include "stdc++.h"

using namespace std;



const int maxn = 1100;

const int maxm = 220000;



int u[maxm], v[maxm];

vector<int> g[maxn];

bool chk[maxn][maxn];

int root;

bool vis[maxn];



namespace SCC {

	const int N = 1100;

	int T, qn;

	int q[N], vis[N];

	vector<int> adj[N], radj[N];

	

	void dfs(int u) {

		vis[u] = 1;

		for (int v : adj[u]) {

			if (!vis[v]) dfs(v);

		}

		q[++qn] = u;

	}

	

	void rdfs(int u) {

		vis[u] = T;

		for (int v : radj[u]) {

			if (!vis[v]) rdfs(v);

		}

	}

	

	void SCC(int n) {

		memset(vis, 0, sizeof(int) * (n + 1));

		qn = 0;

		for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);

		memset(vis, 0, sizeof(int) * (n + 1));

		for (int i = n; i > 0; i--) if (!vis[q[i]]) ++T, rdfs(q[i]);

	}

};



inline void dfs(int u) {

	vis[u] = true;

	for(auto v : g[u]) {

		if(vis[v]) {

			if(u == root) chk[root][v] = false;

			continue;

		}

		dfs(v);

		if(u == root) chk[root][v] &= true;

		else chk[root][v] = false;

	}

}



int main() {

	ios::sync_with_stdio(0);

	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;

	for(int i = 0; i < m; ++ i) {

		cin >> u[i] >> v[i];

		g[u[i]].push_back(v[i]);

		SCC::adj[u[i]].push_back(v[i]);

		SCC::radj[v[i]].push_back(u[i]);

	}

	// get SCC

	SCC::SCC(n);

	// check the u -> v edge is the unique way.

	for(int i = 1; i <= n; ++ i) for(int j = 1; j <= n; ++ j) chk[i][j] = true;

	for(int step = 0; step < 2; ++ step) {

		for(int i = 1; i <= n; ++ i) {

			root = i;

			if(step) reverse(g[i].begin(), g[i].end());

			memset(vis, false, sizeof vis);

			dfs(i);

		}

	}

	for(int i = 0; i < m; ++ i) {

		int flag = SCC::vis[u[i]] == SCC::vis[v[i]];

		if(chk[u[i]][v[i]] == flag) cout << "diff\n";

		else cout << "same\n";

	}

	return 0;

}
