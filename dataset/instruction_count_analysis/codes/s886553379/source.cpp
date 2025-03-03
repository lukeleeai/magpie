#pragma GCC optimize ("O3")

#pragma GCC target ("avx2")

//#include"stdc++.h"

#include<cstdio>

#include<cstring>

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



unsigned char D[252004];

bool E[252004];

int Q[252004];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int n = N + 2;

	rep1(i, N) {

		int ij = n * i + 1;

		unsigned char kari = min(i - 1, N - i);

		unsigned char kari2 = 3;



		rep(j, kari) {

			D[ij++] = kari2++;

		}

		rep(j, N - kari - kari) {

			D[ij++] = kari + 3;

		}

		rep(j, kari) {

			D[ij++] = --kari2;

		}

	}



	int kotae = 0;

	rep(k, N * N) {

		int ij = getint();

		ij += (ij - 1) / N * 2 + N + 2;



		kotae += D[ij];

		E[ij] = 1;



		int p = 0, q = 0;

		Q[p++] = ij;



		while (p > q) {

			int ij = Q[q++];

			int d =	D[ij] - E[ij] + 1;



			if (D[ij - n] > d) {

				D[ij - n] = d;

				Q[p++] = ij - n;

			}

			if (D[ij + n] > d) {

				D[ij + n] = d;

				Q[p++] = ij + n;

			}

			if (D[ij - 1] > d) {

				D[ij - 1] = d;

				Q[p++] = ij - 1;

			}

			if (D[ij + 1] > d) {

				D[ij + 1] = d;

				Q[p++] = ij + 1;

			}

		}

	}



	printf("%d\n", kotae - 3 * N * N);







	Would you please return 0;

}