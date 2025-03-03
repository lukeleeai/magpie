#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

#include"stdc++.h"

//#include<cstdio>

//#include<algorithm>

//#include<vector>

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



int N, M;

int K[100001];

int to[200001], ne[200001], he[100001], num[200001];

vector<int> S1[100001], S2[100001];

int dame[100001];

bool memo[100001];



int dfs(int v, int prev) {

	if (memo[v]) {

		ll ret = 1;

		if (prev) {

			int k = K[v] - num[prev];

			ret = (ll)S1[v][k - 1] * S2[v][k + 1] % M;

		}

		else ret = S1[v][K[v]];

		if (dame[v] && dame[v] != prev) {

			ll tmp = dfs(to[dame[v]], dame[v] ^ 1);

			int k = K[v] - num[dame[v]];

			for (int i = k; i <= K[v]; i++) {

				S1[v][i] = S1[v][i] * tmp % M;

			}

			for (int i = k; i > 0; i--) {

				S2[v][i] = S2[v][i] * tmp % M;

			}

			ret *= tmp;

			dame[v] = 0;

		}

		return (ret + 1) % M;

	}

	memo[v] = true;

	dame[v] = prev;

	ll ret = 1;

	int k = 1;

	for (int i = he[v]; i; i = ne[i]) {

		int tmp = 1;

		if (i != prev) {

			tmp = dfs(to[i], i ^ 1);

			ret = ret * tmp % M;

		}

		S1[v][k] = ret;

		S2[v][k++] = tmp;

	}

	for (int i = k - 1; i > 0; i--) {

		S2[v][i] = ((ll)S2[v][i] * S2[v][i + 1]) % M;

	}

	return ret + 1;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	cin >> N >> M;



	int k = 2;

	rep1(i, N - 1) {

		int x, y;

		cin >> x >> y;



		num[k] = K[x];

		to[k] = y;

		ne[k] = he[x];

		he[x] = k++;

		num[k] = K[y];

		to[k] = x;

		ne[k] = he[y];

		he[y] = k++;

		K[x]++;

		K[y]++;

	}

	rep1(i, N) {

		S1[i].resize(K[i] + 2);

		S2[i].resize(K[i] + 2);

		S1[i][0] = 1;

		S2[i][K[i] + 1] = 1;

	}



	rep1(j, N) {

		ll kotae = (dfs(j, 0) - 1 + M) % M;

		co(kotae);

	}





	Would you please return 0;

}