#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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



const int mod = 1e9 + 7;

ll modpow(ll A, ll B) {

	ll kotae = 1;

	while (B > 0) {

		if (B & 1) kotae = kotae * A % mod;

		A = A * A % mod;

		B >>= 1;

	}

	return kotae;

}

const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}

const int n = 100000;

class nanika {

	int fac[100001], inv[100001];

public:

	constexpr nanika() : fac(), inv() {

		fac[0] = 1;

		rep1(i, n) fac[i] = ll(fac[i - 1]) * i % mod;

		ll ifac = 1;

		ll A = fac[n];

		ll B = mod - 2;

		while (B > 0) {

			if (B & 1) ifac = ifac * A % mod;

			A = A * A % mod;

			B >>= 1;

		}

		for (int i = n; i > 0; i--) {

			inv[i] = fac[i - 1] * ifac % mod;

			ifac = ifac * i % mod;

		}

	}

	int operator[](int n) {

		return inv[n];

	}

	int getfac(int n) {

		return fac[n];

	}

} test;



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int kei = 0;

	ll kotae = 0;

	int mae = getint();

	rep1(i, N - 1) {

		int tugi = getint();

		ll X = tugi - mae;

		kei = (kei + test[i]) % mod;

		kotae += kei * X % mod;

		mae = tugi;

	}



	printf("%lld\n", kotae % mod * test.getfac(N - 1) % mod);





	Would you please return 0;

}
