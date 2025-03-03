#include "stdc++.h"

using namespace std;



namespace SCC {

	const int N = 110000;

	vector<int> con[N], rcon[N];

	int n, vis[N], visT;

	int id[N], idn;

	void init(int nn = 0) {

		n = nn, visT = idn = 0;

		for (int i = 1; i <= n; i++) con[i].clear(), rcon[i].clear();

	}

	void add_edge(int u, int v) {

		con[u].push_back(v);

		rcon[v].push_back(u);

	}

	void dfs(int u) {

		vis[u] = 1;

		for (int v : con[u]) if (!vis[v]) dfs(v);

		id[idn++] = u;

	}

	void rdfs(int u) {

		vis[u] = visT;

		for (int v : rcon[u]) if (!vis[v]) rdfs(v);

	}

	void SCC() {

		for (int i = 1; i <= n; i++) vis[i] = 0;

		for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);

		for (int i = 1; i <= n; i++) vis[i] = 0;

		for (int i = idn - 1; i >= 0; i--) if (!vis[id[i]]) visT++, rdfs(id[i]);

	}

};



const int N = 1100;

const int M = 220000;



vector<int> con[N];



struct Edge {

	int u, v;

	Edge(int u = 0, int v = 0) : u(u), v(v) {}

} E[M];



int adj[N][N];

int vis[N], visT;

int son[2][N][N];



inline bool Find(int u, int tar) {

	if (adj[u][tar] > 1) return true;

	return son[0][u][tar] != tar || son[1][u][tar] != tar;

}



void dfs(int u, int id, int rt, int __rt) {

	vis[u] = visT;

	son[id][__rt][u] = rt;

	for (int v : con[u]) if (vis[v] != visT) dfs(v, id, rt, __rt);

}



void init(int n) {

	for (int i = 1; i <= n; i++) {

		visT++;

		vis[i] = visT;

		for (int v : con[i]) if (vis[v] != visT) dfs(v, 0, v, i);

		reverse(con[i].begin(), con[i].end());

		visT++;

		vis[i] = visT;

		for (int v : con[i]) if (vis[v] != visT) dfs(v, 1, v, i);

	}

}



int main() {

	

	ios::sync_with_stdio(0);

	cin.tie(0), cout.tie(0);

	

	int n, m; cin >> n >> m;

	SCC::init(n + 10);

	for (int i = 0; i < m; i++) {

		int u, v; cin >> u >> v;

		E[i] = Edge(u, v);

		con[u].push_back(v);

		adj[u][v]++;

		SCC::add_edge(u, v);

	}

	SCC::SCC();

	

	init(n);

	

	for (int i = 0; i < m; i++) {

		auto a = SCC::vis[E[i].u], b = SCC::vis[E[i].v];

		if (a == b) {

			if (Find(E[i].u, E[i].v)) cout << "same\n";

			else cout << "diff\n";

		} else {

			if (Find(E[i].u, E[i].v)) cout << "diff\n";

			else cout << "same\n";

		}

	}

	

	return 0;

}