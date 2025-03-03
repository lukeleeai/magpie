#include <cstdio>

#include <algorithm>

#include <queue>

#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)



const int N(2010);

struct edge { int next, to; } e[N];

int head[N], e_num, n, A[N], vis[N], G[N][N], deg[N];

inline void add_edge(int from, int to)

{

	e[++e_num] = (edge) {head[from], to};

	head[from] = e_num;

}



void dfs(int x)

{

	for (int i = vis[x] = 1; i <= n; i++) if (!vis[i] && G[x][i])

		++deg[i], add_edge(x, i), dfs(i);

}



void TopSort()

{

	std::priority_queue<int> Q;

	for (int i = 1; i <= n; i++) if (!deg[i]) Q.push(i);

	while (!Q.empty())

	{

		int x = Q.top(); Q.pop(); printf("%d ", A[x]);

		for (int i = head[x]; i; i = e[i].next) Q.push(e[i].to);

	}

}



int main()

{

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%d", A + i);

	std::sort(A + 1, A + n + 1);

	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++)

		if (std::__gcd(A[i], A[j]) != 1) G[i][j] = G[j][i] = 1;

	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);

	TopSort();

	return 0;

}

//fdgdg