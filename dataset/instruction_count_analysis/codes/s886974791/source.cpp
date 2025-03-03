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



const ll mod = 1e9 + 7;

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

	ll A[300000];

	rep(i, N) cin >> A[i];



	int kazu[60] = {};

	rep(i, N) {

		rep(j, 60) {

			kazu[j] += A[i] >> j & 1;

		}

	}



	ll kotae[60] = {};

	rep(i, N) {

		rep(j, 60) {

			kazu[j] -= A[i] >> j & 1;

		}



		rep(j, 60) {

			if (A[i] >> j & 1) {

				kotae[j] += N - 1 - kazu[j];

			}

			else {

				kotae[j] += kazu[j];

			}

		}



		rep(j, 60) {

			kazu[j] += A[i] >> j & 1;

		}

	}



	ll ans = 0;

	rep(i, 60) {

		kotae[i] %= mod;

		ll tmp = (1ll << i) % mod;

		ans += kotae[i] * tmp % mod;

	}

	ans %= mod;

	co(ans * modpow(2, mod - 2) % mod);





	Would you please return 0;

}