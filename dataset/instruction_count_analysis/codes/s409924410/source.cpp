#pragma GCC optimize ("O3")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<cstdio>

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

const int IMAX = 200010;

ll modpow(ll A, ll B) {

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

	int fac[IMAX + 1], ifac[IMAX + 1];

	unko() : fac(), ifac() {

		fac[0] = 1;

		rep1(i, IMAX) fac[i] = ll(fac[i - 1]) * i % mod;

		ifac[IMAX] = modpow(fac[IMAX], mod - 2);

		for (int i = IMAX; i > 0; i--) ifac[i - 1] = ll(ifac[i]) * i % mod;

	}

} f;



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N, M, K;

	scanf("%d %d %d", &N, &M, &K);



	if (M == 1) {

		if (K == N - 1) printf("1");

		else printf("0");



		return 0;

	}

	if (N == 1) {

		printf("%d", M);

		return 0;

	}



	ll kotae = 0;

	ll tmp = ll(M) * f.fac[N - 1] % mod * modpow(M - 1, N - K - 1) % mod;

	for (int k = K; k >= 0; k--) {

		kotae += tmp * f.ifac[k] % mod * f.ifac[N - 1 - k] % mod;

		tmp = tmp * (M - 1) % mod;

	}



	printf("%lld", kotae % mod);







	Would you please return 0;

}