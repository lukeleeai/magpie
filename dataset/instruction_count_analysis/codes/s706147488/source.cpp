#include "stdc++.h"

using namespace std;



namespace TYC

{

	typedef long long ll;

	const int N = 1e5 + 5;



	int n, m, A[N], B[N], C[N], Fa[N], P[N], Vis[N];

	ll F[N], Sum[N];

	vector<int> E[N], T[N];



	bool cmp(const int a, const int b) { return C[a] < C[b]; }



	int find(const int a) { return a == Fa[a] ? a : Fa[a] = find(Fa[a]); }



	void dfs(const int u)

	{

		Sum[u] = B[u];

		for (int v : T[u])

		{

			dfs(v);

			Sum[u] += Sum[v];

		}

		if (!T[u].size())

			F[u] = C[u] + B[u];

		else 

		{

			F[u] = LLONG_MAX;

			for (int v : T[u])

				F[u] = min(F[u], max(F[v], (ll)C[u]) + Sum[u] - Sum[v]); 

		}

	}



	void work()

	{

		scanf("%d%d", &n, &m);

		for (int i = 1; i <= n; i++)

		{

			scanf("%d%d", &A[i], &B[i]);

			C[i] = max(A[i] - B[i], 0);

			P[i] = Fa[i] = i;

		}

		for (int i = 1, u, v; i <= m; i++)

		{

			scanf("%d%d", &u, &v);

			E[u].push_back(v);

			E[v].push_back(u);

		}

		sort(P + 1, P + 1 + n, cmp);

		for (int i = 1; i <= n; i++)

		{

			int u = P[i], f;

			Vis[u] = 1;

			for (int v : E[u])

				if (Vis[v] && (f = find(v))	!= u)

				{

					Fa[f] = u;

					T[u].push_back(f);

				}

		}

		dfs(P[n]);

		printf("%lld\n", F[P[n]]);

	}

}



int main()

{

	TYC::work();

	return 0;

}