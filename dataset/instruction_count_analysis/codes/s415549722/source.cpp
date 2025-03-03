#pragma GCC optimize ("O3")

#pragma GCC target ("avx2")

//#include"stdc++.h"

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



const int mod = 998244353;

const int IMAX = 3000;

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

} f;



int dp[3001];

int A[3001], B[3001];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N, S;

	scanf("%d %d", &N, &S);



	rep(i, N) {

		int a;

		scanf("%d", &a);

		A[a]++;

	}



	ll k2 = modpow(2, mod - 2);

	dp[0] = modpow(2, N);

	int s = A[1];

	ll kotae1 = 0, kotae2 = 0;

	B[0] = 1;



	rep1(b, A[1]) {

		if (b > S) break;

		dp[b] = k2 * dp[b - 1] % mod * (A[1] - b + 1) % mod * f.inv[b] % mod;

	}

	kotae2 = dp[S];



	for (int a = 2; a <= S; a++) {

		if (A[a] == 1) {

			s = min(S - a - 1, s + a);

			if (S >= a) kotae1 += dp[S - a];

			for (int j = s; j >= a; j--) {

				dp[j] = (dp[j] + dp[j - a] * k2) % mod;

			}

		}

		else if (A[a]) {

			rep1(b, A[a]) {

				B[b] = k2 * B[b - 1] % mod * (A[a] - b + 1) % mod * f.inv[b] % mod;

			}



			s = min(S - a, s + a * A[a]);

			if (S >= a) {

				rep1(b, A[a]) {

					if (S - a * b < 0) break;

					kotae2 += ll(dp[S - a * b]) * B[b] % mod;

				}

			}

			for (int j = s; j >= a; j--) {

				ll tmp = dp[j];

				rep1(b, A[a]) {

					if (j - a * b < 0) break;

					tmp += ll(dp[j - a * b]) * B[b] % mod;

				}

				dp[j] = tmp % mod;

			}

		}

	}



	printf("%lld\n", (kotae1 % mod * k2 + kotae2) % mod);



	Would you please return 0;

}