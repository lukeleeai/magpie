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



const ll mod = 998244353;

ll modpow(ll A, ll B) {

	ll kotae = 1;

	while (B > 0) {

		if (B & 1) kotae = kotae * A % mod;

		A = A * A % mod;

		B >>= 1;

	}

	return kotae;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N;

	cin >> N;

	int D[200000];

	rep(i, N) cin >> D[i];



	//ちくしょー

	if (D[0] != 0) {

		co(0);

		return 0;

	}



	sort(D, D + N);

	int saidai = D[N - 1];

	int kazu[200001] = {};

	rep(i, N) kazu[D[i]]++;



	ll kotae = 1;



	if (kazu[0] != 1) {

		co(0);

		return 0;

	}

	if (saidai > N - 1) {

		co(0);

		return 0;

	}



	int mae = 1;

	rep1(i, saidai) {

		if (kazu[i] == 0) kotae = 0;

		rep(j, kazu[i]) kotae = kotae * mae % mod;

		mae = kazu[i];

	}



	co(kotae);



	Would you please return 0;

}