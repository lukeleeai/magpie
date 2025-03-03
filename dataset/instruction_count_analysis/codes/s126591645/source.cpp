#include "stdc++.h"

#define N 202

#define M 100000

using namespace std;



typedef unsigned ui;



ui n, m, s, t;

ui dis[N], cur[N];



struct edge { ui p, v; int c, f; } es[M]; ui eh[N], ec;

void eclr() { memset(eh, 0xff, sizeof(eh)); ec = 0; }

void adde(ui u, ui v, int c) {

	es[ec] = { eh[u], v, c, 0 }; eh[u] = ec++;

	es[ec] = { eh[v], u, 0, 0 }; eh[v] = ec++;

}



bool bfs() {

	static bool vis[N];

	memset(vis, 0, sizeof(vis));

	dis[s] = 0; vis[s] = 1;

	queue<ui> q; q.push(s);

	while (!q.empty()) {

		ui u = q.front(); q.pop();

		for (ui ei = eh[u]; ~ei; ei = es[ei].p) {

			edge& e = es[ei]; ui v = e.v;

			if (vis[v] || e.c <= e.f) continue;

			vis[v] = 1; dis[v] = dis[u] + 1; q.push(v);

		}

	}

	return vis[t];

}



int dfs(ui u, int a) {

	if (u == t || a == 0) return a;

	int sum = 0, f;

	for (ui& ei = cur[u]; ~ei; ei = es[ei].p) {

		edge& e = es[ei]; ui v = e.v;

		if (dis[u] + 1 != dis[v] || (f = dfs(v, min(a, e.c - e.f))) <= 0)

			continue;

		e.f += f; es[ei ^ 1].f -= f;

		sum += f; a -= f;

		if (!a) break;

	}

	return sum;

}



int dinic() {

	int sum = 0;

	while (bfs()) {

		memcpy(cur, eh, sizeof(eh));

		sum += dfs(s, 1 << 30);

	}

	return sum;

}



char g[N][N];



int main(void) {

	ios::sync_with_stdio(0); cin.tie(0);

#ifdef _DEBUG

	ifstream cin("1.in");

#endif

	ui n, m; cin >> n >> m;

	

	for (ui i = 0; i != n; ++i) cin >> g[i];

	ui sx, sy, tx, ty; s = 200, t = 201;

	eclr();

	for (ui i = 0; i != n; ++i)

		for (ui j = 0; j != m; ++j) {

			if (g[i][j] == 'S') { sx = i; sy = j; }

			else if (g[i][j] == 'T') { tx = i; ty = j; }

			else if (g[i][j] == 'o') { adde(i, 100 + j, 1); adde(100 + j, i, 1); }

		}



	adde(s, sx, 500);

	adde(s, sy + 100, 500);

	adde(tx, t, 500);

	adde(ty + 100, t, 500);



	if (sx == tx|| sy == ty) cout << -1 << endl;

	else cout << dinic() << endl;



	return 0;

}