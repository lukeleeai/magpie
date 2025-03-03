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



//みなさん天才的ですよね



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

	int dig = 68 - __builtin_ctzll((tmp & ma0) ^ ma0);

	tmp = tmp << dig & ma1;

	tmp = tmp * 10 + (tmp >> 8) & ma2;

	tmp = tmp * 100 + (tmp >> 16) & ma3;

	tmp = tmp * 10000 + (tmp >> 32) & ma4;

	ci += 72 - dig >> 3;

	return tmp;



}

int KH[300001], KW[300001];

int h[300001], w[300001];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int H = getint(), W = getint(), M = getint();



	rep(i, M) {

		KH[h[i] = getint()]++;

		KW[w[i] = getint()]++;

	}



	int saidaih = -1, hh = 0;

	rep1(i, H) {

		if (saidaih < KH[i]) {

			saidaih = KH[i];

			hh = 1;

		}

		else if (saidaih == KH[i]) hh++;

	}

	int saidaiw = -1, ww = 0;

	rep1(i, W) {

		if (saidaiw < KW[i]) {

			saidaiw = KW[i];

			ww = 1;

		}

		else if (saidaiw == KW[i]) ww++;

	}



	ll are = ll(hh) * ww;



	int kazu = 0;

	rep(i, M) {

		kazu += (KH[h[i]] == saidaih && KW[w[i]] == saidaiw);

	}



	printf("%d\n", saidaih + saidaiw - (kazu == are));



	Would you please return 0;

}