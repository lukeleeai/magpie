#include "stdc++.h"

using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

typedef long long ll;



int N;

vector< pair<int, int> > E[101010];



class LCA

{

public:

	int NV;

	int logNV;

	vector<int> D;

	vector<long long> L;

	vector<vector<int> > P;



	LCA(int N)

	{

		NV = N;

		logNV = 0;

		while (NV > (1LL << logNV)) logNV++;

		D = vector<int>(NV);

		L = vector<long long>(NV);

		P = vector<vector<int> >(logNV, vector<int>(NV));

	}



	void init()

	{

		dfs(0, -1, 0, 0);

		build();

	}



	void dfs(int v, int par, int d, long long l)

	{

		D[v] = d;

		P[0][v] = par;

		L[v] = l;



		for (int i = 0; i < (int)E[v].size(); i++) {

			int w = E[v][i].first;

			int lc = E[v][i].second;

			if (w == par) continue;

			dfs(w, v, d + 1, lc + l);

		}

	}



	void build() {

		for (int k = 0; k + 1 < logNV; k++) {

			for (int v = 0; v < NV; v++) {

				if (P[k][v] < 0) P[k + 1][v] = -1;

				else P[k + 1][v] = P[k][P[k][v]];

			}

		}

	}



	int query(int u, int v) {

		if (D[u] > D[v]) swap(u, v);

		for (int k = 0; k < logNV; k++) {

			if ((D[v] - D[u]) >> k & 1)

				v = P[k][v];

		}

		if (u == v) return u;



		for (int k = logNV - 1; k >= 0; k--) {

			if (P[k][u] != P[k][v]) {

				u = P[k][u];

				v = P[k][v];

			}

		}

		return P[0][u];

	}

};



int main()

{

	cin.tie(0);

	ios::sync_with_stdio(false);



	while (cin >> N)

	{

		if (N == 1)

		{

			cout << 0 << endl;

			continue;

		}

		rep(i, 0, N) E[i].clear();

		rep(i, 1, N)

		{

			int p; cin >> p; p--;

			E[p].push_back( make_pair(i, 1) );

			E[i].push_back( make_pair(p, 1) );

		}



		LCA lca(N);

		lca.init();



		ll ans = 0;



		queue<int> que;

		que.push(0);

		int prev = -1;

		while (!que.empty())

		{

			int p = que.front(); que.pop();

			for (auto _p : E[p])

			{

				int pp = _p.first;

				if (lca.L[p] < lca.L[pp]) que.push(pp);

			}



			if (0 <= prev)

			{

				ans += (ll)(lca.L[p] + lca.L[prev] - 2 * lca.L[lca.query(p, prev)]);

			}

			prev = p;

		}

		cout << ans << endl;

	}

}