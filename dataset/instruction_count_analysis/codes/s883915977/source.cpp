#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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

const int IMAX = 1001;

ll fac[IMAX + 1], ifac[IMAX + 1];

ll dp[2][1001];



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	fac[0] = 1;

	rep1(i, IMAX) fac[i] = fac[i - 1] * i % mod;

	ifac[IMAX] = modpow(fac[IMAX], mod - 2);

	for (int i = IMAX; i > 0; i--) ifac[i - 1] = ifac[i] * i % mod;



	int N, A, B, C, D;

	scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);

	dp[1][0] = fac[N];

	for (int i = A; i <= B; i++) {

		rep(j, N + 1) dp[0][j] = (dp[1][j] %= mod);

		int d = min(D, N / i);

		ll tmp = modpow(ifac[i], d) * ifac[d] % mod;

		for (int j = d; j >= C; j--) {

			for (int k = 0; k + i * j <= N; k++) {

				dp[1][k + i * j] += dp[0][k] * tmp % mod;

			}

			tmp = tmp * fac[i] % mod * j % mod;

		}

	}

	printf("%lld", dp[1][N] % mod);



	Would you please return 0;

}