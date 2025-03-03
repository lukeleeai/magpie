#pragma GCC optimize ("O2")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

#include<cstring>



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



const int CM = 1 << 17, CL = 12;

char cn[CM + CL], * ci = cn + CM + CL, * owa = cn + CM, ct;

const ll ma0 = 1157442765409226768;

const ll ma1 = 1085102592571150095;

const ll ma2 = 71777214294589695;

const ll ma3 = 281470681808895;

const ll ma4 = 4294967295;

inline int getint() {

	if (ci - owa > 0) {

		memcpy(cn, owa, CL);

		ci -= CM;

		fread(cn + CL, 1, CM, stdin);

	}

	ll tmp = *(ll*)ci;

	if ((tmp & ma0) ^ ma0) {

		int dig = 68 - __builtin_ctzll((tmp & ma0) ^ ma0);

		tmp = tmp << dig & ma1;

		tmp = tmp * 10 + (tmp >> 8) & ma2;

		tmp = tmp * 100 + (tmp >> 16) & ma3;

		tmp = tmp * 10000 + (tmp >> 32) & ma4;

		ci += (72 - dig >> 3);

	}

	else {

		tmp = tmp & ma1;

		tmp = tmp * 10 + (tmp >> 8) & ma2;

		tmp = tmp * 100 + (tmp >> 16) & ma3;

		tmp = tmp * 10000 + (tmp >> 32) & ma4;

		ci += 8;

		if ((ct = *ci++) >= '0') {

			tmp = tmp * 10 + ct - '0';

			if (*ci++ == '0') {

				tmp = tmp * 10;

				ci++;

			}

		}

	}

	return tmp;

}

const int mod = 1e9 + 7;

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);



	int N = getint();

	ll kei = 0;

	ll kei2 = 0;

	ll kei3 = 0;

	const ll ma = (1ll << 60) - 1;

	rep(i, N) {

		ll a = getint();

		kei += a;

		kei2 += a * a;

		kei3 += kei2 >> 60;

		kei2 &= ma;

	}

	kei %= mod;

	kei = kei * kei % mod;



	kei2 = kei2 % mod;

	kei3 %= mod;

	kei3 = kei3 * ((1ll << 60) % mod) % mod;

	kei = (kei - kei2 - kei3 + mod + mod) % mod;



	kei = kei * (mod / 2 + 1) % mod;



	printf("%d\n", kei);





	Would you please return 0;

}