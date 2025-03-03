#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

#include"stdc++.h"

using namespace std;

typedef long long ll;

#define rep(i, n) for(int i = 0; i < (n); i++)

#define rep1(i, n) for(int i = 1; i <= (n); i++)

#define co(x) cout << (x) << "\n"

#define cosp(x) cout << (x) << " "

#define ce(x) cerr << (x) << "\n"

#define cesp(x) cerr << (x) << " "

#define pb push_back

#define mp make_pair

#define chmin(x, y) x = min(x, y)

#define chmax(x, y) x = max(x, y)

#define Would

#define you

#define please



ll dp[1 << 20];



vector<int> V[51];

vector<pair<int, int>> E[51];

void dfs(int p, vector<int> v, int mae) {

	V[p] = v;

	for (auto pr : E[p]) {

		int to = pr.first;

		if (mae != to) {

			v.pb(pr.second);

			dfs(to, v, p);

			v.pop_back();

		}

	}

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	rep(i, N - 1) {

		int a, b;

		cin >> a >> b;

		E[a].pb(mp(b, i));

		E[b].pb(mp(a, i));

	}



	vector<int> kari;

	dfs(1, kari, 0);



	int M;

	cin >> M;

	int list[51] = {};

	rep(i, M) {

		int u, v;

		cin >> u >> v;



		for (int j : V[u]) list[j] ^= 1 << i;

		for (int j : V[v]) list[j] ^= 1 << i;

	}



	dp[0] = 1;

	rep(i, N - 1) {

		for (int j = (1 << M) - 1; j >= 0; j--) {

			dp[j | list[i]] += dp[j];

		}

	}



	co(dp[(1 << M) - 1]);





	Would you please return 0;

}