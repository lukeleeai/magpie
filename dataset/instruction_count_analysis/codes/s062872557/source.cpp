#pragma GCC optimize ("O2")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<cstdio>

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



int A[100000];

char kotae[800000], * it = kotae;

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

		while ((ct = *ci++) >= '0') tmp = tmp * 10 + ct - '0';

	}

	return tmp;

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N, K, kari;

	N = getint();

	K = getint();



	int k = N - K;



	if (k <= K) {

		rep(i, k) A[i] = getint();

		rep(i, K - k) {

			if (ci - owa > 0) {

				memcpy(cn, owa, CL);

				ci -= CM;

				fread(cn + CL, 1, CM, stdin);

			}

			ll tmp = *(ll*)ci;

			if ((tmp & ma0) ^ ma0) {

				ci += (__builtin_ctzll((tmp & ma0) ^ ma0) + 4 >> 3);

			}

			else {

				ci += 8;

				while ((ct = *ci++) >= '0') tmp = tmp * 10 + ct - '0';

			}

		}

		rep(i, k) {

			kari = getint();

			if (kari > A[i]) {

				*it++ = 'Y';

				*it++ = 'e';

				*it++ = 's';

				*it++ = '\n';

			}

			else {

				*it++ = 'N';

				*it++ = 'o';

				*it++ = '\n';

			}

		}

	}

	else if (K == 1) {

		int mae = getint();

		rep(i, k) {

			kari = getint();

			if (kari > mae) {

				*it++ = 'Y';

				*it++ = 'e';

				*it++ = 's';

				*it++ = '\n';

			}

			else {

				*it++ = 'N';

				*it++ = 'o';

				*it++ = '\n';

			}

			mae = kari;

		}

	}

	else {

		rep(i, K) A[i] = getint();

		int kazu = k / K;

		int amari = k % K;

		rep(j, kazu) rep(i, K) {

			kari = getint();

			if (kari > A[i]) {

				*it++ = 'Y';

				*it++ = 'e';

				*it++ = 's';

				*it++ = '\n';

			}

			else {

				*it++ = 'N';

				*it++ = 'o';

				*it++ = '\n';

			}

			A[i] = kari;

		}

		rep(i, amari) {

			kari = getint();

			if (kari > A[i]) {

				*it++ = 'Y';

				*it++ = 'e';

				*it++ = 's';

				*it++ = '\n';

			}

			else {

				*it++ = 'N';

				*it++ = 'o';

				*it++ = '\n';

			}

		}

	}



	fwrite(kotae, 1, it - kotae, stdout);





	Would you please return 0;

}