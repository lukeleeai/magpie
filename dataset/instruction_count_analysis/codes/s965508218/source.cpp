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

#define Would

#define you

#define please



int N;

vector<int> V[100001];

int D[100001];

ll mod = 1e9 + 7;



pair<ll, ll> dfs(int A) {

	if (D[A]) return mp(0, 1);

	D[A] = 1;

	ll kuro = 1;

	ll siro = 1;

	for (int i : V[A]) {

		auto k = dfs(i);

		kuro = (kuro * k.second) % mod;

		siro = (siro * (k.first + k.second)) % mod;

	}

	return mp(kuro, siro);

}







int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	cin >> N;

	rep(i, N - 1) {

		int x, y;

		cin >> x >> y;

		V[x].pb(y);

		V[y].pb(x);

	}



	auto M = dfs(1);

	co((M.first + M.second) % mod);



	Would you please return 0;

}