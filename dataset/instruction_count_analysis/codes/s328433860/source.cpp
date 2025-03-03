#pragma GCC optimize ("Ofast")

#pragma GCC target ("avx2")

#include"stdc++.h"

#include<cstdio>

#include<algorithm>

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



int K[200001];

int zentai, N;

ll kotae[200001];

int C[200001];

vector<int> E[200001];



void dfs(int p, int mae) {





	int k = K[C[p]] + zentai;

	int k0 = k;



	for (int to : E[p]) {

		if (mae != to) {

			dfs(to, p);

			int sa = K[C[p]] + zentai - k;

			kotae[C[p]] -= ll(sa) * (sa + 1) / 2;

			k += sa;

		}

	}



	zentai++;

	K[C[p]] = k0 - zentai;

}





int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	cin >> N;

	rep1(i, N) cin >> C[i];

	rep(i, N - 1) {

		int a, b;

		cin >> a >> b;



		E[a].pb(b);

		E[b].pb(a);

	}



	dfs(1, -1);

	ll n = ll(N) * (N + 1) / 2;

	rep1(i, N) {

		int sa = K[i] + zentai;

		co(n + kotae[i] - ll(sa) * (sa + 1) / 2);

	}



	Would you please return 0;

}