#include "stdc++.h"

using namespace std;

#define maxn 100005

#define INF 99999999

int n, root, Ans, ans, C[maxn], mark[maxn];

int degree[maxn], dp1[maxn], dp2[maxn];

int val[maxn];



int read()

{

	int x = 0, k = 1;

	char c; c = getchar();

	while(c < '0' || c > '9') { if(c == '-') k = -1; c = getchar(); }

	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();

	return x * k;

}



struct edge

{

    int cnp, to[maxn * 2], last[maxn * 2], head[maxn];

    edge() { cnp = 1; }

    void add(int u, int v)

    {

        to[cnp] = v, last[cnp] = head[u], head[u] = cnp ++;

        to[cnp] = u, last[cnp] = head[v], head[v] = cnp ++;

    }

}E1;



void dfs(int u, int fa)

{

	mark[u] = C[u];

	for(int i = E1.head[u]; i; i = E1.last[i])

	{

		int v = E1.to[i];

		if(v == fa) continue;

		dfs(v, u);

		if(!mark[v]) ++ degree[u], ++ degree[v];

		mark[u] &= mark[v];

	}

}



void dfs2(int u, int fa)

{

	int mx1 = 0, mx2 = 0; bool flag = 0;

	Ans += degree[u];

	if((degree[u] + C[u]) & 1) val[u] = 0;

	else val[u] = 2, ++ Ans;

	for(int i = E1.head[u]; i; i = E1.last[i])

	{

		int v = E1.to[i];

		if(v == fa || mark[v]) continue;

		flag = 1; dfs2(v, u);

		ans = max(ans, max(dp1[v] + mx2 + val[u], dp2[v] + mx1 + val[u]));

		mx1 = max(dp1[v], mx1), mx2 = max(dp2[v], mx2);

	}

	dp1[u] = mx1 + val[u], dp2[u] = flag ? mx2 + val[u] : -INF;

}



int main()

{

	n = read();

	for(int i = 1; i < n; i ++)

	{

		int x = read(), y = read();

		E1.add(x, y);

	}

	for(int i = 1; i <= n; i ++)

	{

		char c; cin >> c;

		if(c == 'B') C[i] = 1;

		else root = i; 

	}

	if(!root) { puts("0"); return 0; }

	dfs(root, 0); dfs2(root, 0);

	printf("%d\n", Ans - ans);

	return 0;

}