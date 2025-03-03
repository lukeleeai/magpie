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



const int mod = 1e9 + 7;

const int IMAX = 100000;

constexpr ll modpow(ll A, ll B) {

	ll kotae = 1;

	while (B > 0) {

		if (B & 1) kotae = kotae * A % mod;

		A = A * A % mod;

		B >>= 1;

	}

	return kotae;

}

class unko {

public:

	int fac[IMAX + 1], ifac[IMAX + 1], inv[IMAX + 1];

	constexpr unko() : fac(), ifac(), inv() {

		fac[0] = 1;

		rep1(i, IMAX) fac[i] = ll(fac[i - 1]) * i % mod;

		ifac[IMAX] = modpow(fac[IMAX], mod - 2);

		for (int i = IMAX; i > 0; i--) ifac[i - 1] = ll(ifac[i]) * i % mod;

		inv[0] = 1;

		rep1(i, IMAX) inv[i] = ll(ifac[i]) * fac[i - 1] % mod;

	}

	int comb(int A, int B) {

		return ll(fac[A]) * ifac[B] % mod * ifac[A - B] % mod;

	}

} f;



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);





	int N, K;

	cin >> N >> K;



	int A[100000];

	rep(i, N) cin >> A[i];

	sort(A, A + N);



	ll kotae = 0;

	for (int i = K - 1; i < N; i++) {

		kotae += (ll)f.comb(i, K - 1) * A[i] % mod;

	}

	kotae %= mod;

	for (int i = N - K; i >= 0; i--) {

		kotae -= (ll)f.comb(N - i - 1, K - 1) * A[i] % mod;

	}

	kotae %= mod;



	co((kotae + mod) % mod);



	Would you please return 0;

}