#pragma GCC optimize ("O3")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

#include<cstring>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef __int128 lll;

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



//こんなクソコードを生み出してしまうなんて趣味は罪ね



const int mod = 1e9 + 7;

const int IMAX = 200000;

const int D[9] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000 };

class unko {

public:

	int f[IMAX + 1];

	//働いてない？

	constexpr unko() : f() {

		f[0] = 1;

		rep1(i, IMAX) f[i] = ll(f[i - 1]) * 2 % mod;

	}

} f;



void pakuri_sort(int N, ull A[]) {

	const int b = 8;

	ull tmp[200001];

	rep(k, 8) {

		int kazu[1 << b] = {}, kazu2[1 << b] = {};

		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];

		for (int i = N - 1; i >= 0; i--) tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];

		k++;

		rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];

		for (int i = N - 1; i >= 0; i--) A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];

	}

}



const int CM = 1 << 17, CL = 22;

char cn[CM + CL], * ci = cn + CM + CL, * owa = cn + CM, ct;

const ll ma0 = 1157442765409226768;

const ll ma1 = 1085102592571150095;

const ll ma2 = 71777214294589695;

const ll ma3 = 281470681808895;

const ll ma4 = 4294967295;

inline ll getint() {

	if (ci - owa > 0) {

		memcpy(cn, owa, CL);

		ci -= CM;

		fread(cn + CL, 1, CM, stdin);

	}

	int pn = 1;

	if (*ci == '-') {

		pn = -pn;

		ci++;

	}

	ll tmp = *(ll*)ci;

	int dig = ((tmp & ma0) ^ ma0) ? 68 - __builtin_ctzll((tmp & ma0) ^ ma0) : 0;

	tmp = tmp << dig & ma1;

	tmp = tmp * 10 + (tmp >> 8) & ma2;

	tmp = tmp * 100 + (tmp >> 16) & ma3;

	tmp = tmp * 10000 + (tmp >> 32) & ma4;

	ci += (64 - dig >> 3);

	//ll tmp2 = *(ll*)ci;

	//dig = ((tmp2 & ma0) ^ ma0) ? 68 - __builtin_ctzll((tmp2 & ma0) ^ ma0) : 0;

	//tmp2 = dig == 64 ? 0 : tmp2 << dig & ma1;

	//tmp2 = tmp2 * 10 + (tmp2 >> 8) & ma2;

	//tmp2 = tmp2 * 100 + (tmp2 >> 16) & ma3;

	//tmp2 = tmp2 * 10000 + (tmp2 >> 32) & ma4;

	//int d = (64 - dig >> 3); 

	//tmp = tmp * D[d] + tmp2;

	//ci += d;

	while ((ct = *ci++) >= '0') tmp = tmp * 10 + ct - '0';

	return pn * tmp;

}



const ull ma = (1ull << 52) - 1;

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	ull AB[200001];

	int a0 = 0, b0 = 0;

	int ab00 = 0;

	int n = 0;

	rep(i, N) {

		ll a = getint(), b = getint();



		if (a == 0 && b == 0) {

			ab00++;

			continue;

		}

		if (a == 0) {

			a0++;

			continue;

		}

		if (b == 0) {

			b0++;

			continue;

		}



		if (a < 0) {

			a = -a;

			b = -b;

		}

		bool p = (b > 0);

		if (!p) {

			b = -b;

			swap(a, b);

		}



		ull tmp = 0;

		rep(i, 3) {

			tmp *= 3;

			if (b) {

				int k = __builtin_clzll(a) - __builtin_clzll(b);

				if (k > 0) a <<= k;

				else b <<= -k;

				if (a > b) {

					b <<= 1;

					k--;

				}

				double d = double(b) / a;

				ull tmp1 = *(ull*)& d;

				ull c = tmp1 & ma | (1ull << 52);

				lll sa = (lll(b) << 52) - lll(a) * c;

				while (sa >= 0) {

					sa -= a;

					c++;

				}

				while (sa < 0) {

					sa += a;

					c--;

				}

				tmp += ull(k + 63) << 53 | c;

				b = sa;

			}

		}



		if (p) AB[n++] = tmp << 1 | 1ull;

		else AB[n++] = tmp << 1;

	}

	pakuri_sort(n, AB);



	ll kotae = 1;

	ull mae = AB[0] >> 1;

	int k1 = 0, k2 = 0;

	rep(i, n) {

		if (mae != AB[i] >> 1) {

			kotae = kotae * (f.f[k1] + f.f[k2] - 1) % mod;

			k1 = 0;

			k2 = 0;

			mae = AB[i] >> 1;

		}

		if (AB[i] & 1ull) k1++;

		else k2++;

	}

	kotae = kotae * (f.f[k1] + f.f[k2] - 1) % mod;



	kotae = kotae * (f.f[a0] + f.f[b0] - 1) % mod;



	printf("%lld\n", (kotae - 1 + ab00 + mod) % mod);



	Would you please return 0;

}