#include "stdc++.h"

using namespace std;



typedef long long ll;

const int maxn = 200005;



inline int gi()

{

	char c = getchar();

	while (c < '0' || c > '9') c = getchar();

	int sum = 0;

	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();

	return sum;

}



int n, m;

char S[maxn];



struct edge

{

	int to, next;

} e[maxn * 2];

int h[maxn], deg[maxn][2], vis[maxn], tot;

int s, t, q[maxn];



void add(int u, int v)

{

	e[++tot] = (edge) {v, h[u]}; h[u] = tot;

	e[++tot] = (edge) {u, h[v]}; h[v] = tot;

	++deg[u][S[v] - 'A']; ++deg[v][S[u] - 'A'];

}



int topo()

{

	for (int i = 1; i <= n; ++i)

		if (!deg[i][0] || !deg[i][1]) q[++t] = i, vis[i] = 1;

	int cnt = 0;

	while (s < t) {

		int u = q[++s];

		++cnt;

		for (int i = h[u], v; v = e[i].to, i; i = e[i].next)

			if (!vis[v] && !(--deg[v][S[u] - 'A'])) vis[q[++t] = v] = 1;

	}

	return cnt;

}



int main()

{

	scanf("%d%d%s", &n, &m, S + 1);

	for (int i = 1; i <= m; ++i) add(gi(), gi());

	

	puts(topo() == n ? "No" : "Yes");

	

	return 0;

}
