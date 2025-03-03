#include "stdc++.h"

using namespace std;



namespace TYC

{

	typedef long long ll;

	const int N = 205;



	int n, m, s, t, ecnt, Head[N], dep[N], cur[N], R[N][N];

	struct edge { int to, next, w; } E[N * N];

	vector<int> A[N][N], P[N];



	inline void add(const int u, const int v, const int w)

	{

		E[++ecnt] = (edge){v, Head[u], w};

		Head[u] = ecnt;

		E[++ecnt] = (edge){u, Head[v], 0};

		Head[v] = ecnt;

	}	



	bool bfs()

	{

		static queue<int> Q;

		memset(dep, 0, sizeof(int[t + 1]));

		memcpy(cur, Head, sizeof(int[t + 1]));

		dep[s] = 1;

		Q.push(s);

		while (!Q.empty())

		{

			int u = Q.front();

			Q.pop();

			for (int i = Head[u], v; i; i = E[i].next)

				if (E[i].w && !dep[v = E[i].to])

					dep[v] = dep[u] + 1, Q.push(v);

		}

		return dep[t];

	}



	int dfs(const int u, const int mn)

	{

		if (u == t || !mn)

			return mn;

		int v, w, used = 0;

		for (int &i = cur[u]; i; i = E[i].next)

			if (E[i].w && dep[v = E[i].to] == dep[u] + 1)

			{

				w = dfs(v, min(E[i].w, mn - used));

				used += w;

				E[i].w -= w;

				E[i ^ 1].w += w;

				if (used == mn)

					return used;

			}

		if (!used)

			dep[u] = -1;

		return used;

	}



	void work()

	{

		scanf("%d%d", &n, &m);

		for (int i = 1, x; i <= n; i++)

			for (int j = 1; j <= m; j++)

			{

				scanf("%d", &x);

				A[i][(x - 1) / m + 1].push_back(x);

			}

		s = n << 1 | 1, t = s + 1;

		for (int k = 1; k <= m; k++)

		{

			ecnt = 1;

			memset(Head, 0, sizeof(int[t + 1]));

			for (int i = 1; i <= n; i++)

			{

				add(s, i, 1);

				add(i + n, t, 1);

				for (int j = 1; j <= n; j++)

					if (A[i][j].size())

						add(i, j + n, 1);

			}

			while (bfs())

				dfs(s, 0x3f3f3f3f);

			for (int u = 1; u <= n; u++)

				for (int i = Head[u], v; i; i = E[i].next)

					if (!E[i].w && (v = E[i].to - n) <= n)

					{

						R[u][k] = A[u][v].back();

						P[k].push_back(A[u][v].back());

						A[u][v].pop_back();

					}

			sort(P[k].begin(), P[k].end());

		}

		for (int i = 1; i <= n; i++, puts(""))

			for (int j = 1; j <= m; j++)

				printf("%d ", R[i][j]);

		for (int i = 1; i <= n; i++, puts(""))

			for (int j = 1; j <= m; j++)

				printf("%d ", P[j][i - 1]);

	}

}



int main()

{

	TYC::work();

	return 0;

}