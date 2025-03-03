#include "stdc++.h"

using namespace std;



typedef long long ll;

const int maxn = 2e5 + 5, mod = 998244353;



inline int gi()

{

	char c = getchar();

	while (c < '0' || c > '9') c = getchar();

	int sum = 0;

	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();

	return sum;

}



inline void inc(int &a, int b) {a += b; if (a >= mod) a -= mod;}



int n, rt, len, fa[maxn], ch[maxn];



struct edge

{

	int to, next;

} e[maxn * 2];

int h[maxn], tot;

int md[maxn], f[maxn][3][3], g[3][3];



inline void add(int u, int v)

{

	e[++tot] = (edge) {v, h[u]}; h[u] = tot;

	e[++tot] = (edge) {u, h[v]}; h[v] = tot;

}



void dfs1(int u, int d)

{

	if (d > len) rt = u, len = d;

	md[u] = d;

	for (int i = h[u], v; v = e[i].to, i; i = e[i].next)

		if (v != fa[u]) fa[v] = u, dfs1(v, d + 1), md[u] = max(md[u], md[v]);

}



void dfs2(int u, int d)

{

	(md[u] == d ? f[u][1][1] : f[u][0][0]) = 1;

	for (int i = h[u], v; v = e[i].to, i; i = e[i].next)

		if (v != fa[u]) {

			fa[v] = u; dfs2(v, d + 1);

			memset(g, 0, sizeof(g));

			for (int a = 0; a <= 2; ++a)

				for (int b = 0; b <= 2; ++b)

					if (f[u][a][b])

						for (int c = 0; c <= 2; ++c)

							for (int d = 0; d <= 2; ++d)

								if (f[v][c][d])

									for (int t = -1; t <= 1; ++t)

										inc(g[min(2, a + (md[v] == md[u] && t == 1) * c)][min(2, b + (md[v] == md[u] && t == -1) * d)], (ll)f[u][a][b] * f[v][c][d] % mod);

			memcpy(f[u], g, sizeof(f[u]));

		}

}



int main()

{

	n = gi();

	for (int i = 1; i < n; ++i) add(gi(), gi());



	dfs1(1, 0);

	fa[rt] = 0; len = 0; dfs1(rt, 0);

	for (int i = 0, x = rt; x; x = fa[x]) ch[i++] = x;



	if (~len & 1) {

		int x = ch[len >> 1];

		fa[x] = 0, dfs1(x, 0);

		dfs2(x, 0);

		printf("%lld\n", (ll)f[x][1][1] * (mod + 1) / 2 % mod);

	}

	else {

		int x = ch[len >> 1], y = ch[len + 1 >> 1];

		fa[x] = y; fa[y] = x;

		dfs1(x, 0); dfs2(x, 0);

		dfs1(y, 0); dfs2(y, 0);

		printf("%lld\n", ((ll)f[x][1][0] + f[x][1][1] + f[x][1][2]) * ((ll)f[y][1][0] + f[y][1][1] + f[y][1][2]) % mod);

	}

	

	return 0;

}


