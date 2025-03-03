#include "stdc++.h"

using namespace std;



typedef long long ll;

const int maxn = 200005, maxm = 200005;



inline int gi()

{

	char c = getchar();

	while (c < '0' || c > '9') c = getchar();

	int sum = 0;

	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();

	return sum;

}



#define pb push_back



int n, m, d[maxn];



struct edge

{

	int to, next;

} e[maxm * 2];

int h[maxn], tot = 1;

int w[maxm], col[maxn], fa[maxn], fe[maxn];

vector<int> vec[maxn];



inline void add(int u, int v)

{

	e[++tot] = (edge) {v, h[u]}; h[u] = tot;

	e[++tot] = (edge) {u, h[v]}; h[v] = tot;

}



void dfs(int u)

{

	for (int v : vec[u]) {

		w[fe[v]] = d[v];

		if (col[v] == -1) col[v] = col[u] ^ 1, dfs(v);

	}

}



int main()

{

	n = gi(); m = gi();

	for (int i = 1; i <= n; ++i) d[i] = gi();

	for (int i = 1; i <= m; ++i) add(gi(), gi());

	fill(w + 1, w + m + 1, 1e9);



	d[0] = 2e9;

	for (int u = 1; u <= n; ++u) {

		int p = h[u] >> 1, mn = e[h[u]].to;

		for (int i = h[u], v; v = e[i].to, i; i = e[i].next)

			if (d[v] < d[mn] || (d[v] == d[mn] && v < mn)) mn = v, p = i >> 1;

		if (d[mn] > d[u]) return puts("-1"), 0;

		fe[u] = p; fa[u] = mn; vec[mn].pb(u);

	}

	

	fill(col + 1, col + n + 1, -1);

	for (int i = 1; i <= n; ++i) if (fa[fa[i]] == i && col[i] == -1) col[i] = 0, dfs(i); 

	for (int i = 1; i <= n; ++i) putchar(col[i] == 0 ? 'B' : 'W');

	puts("");

	for (int i = 1; i <= m; ++i) printf("%d\n", w[i]);

	

	return 0;

}
