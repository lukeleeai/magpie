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



const int MAX = 100000;

class shuturyoku_unko {

public:

	char C[MAX * 5];

	constexpr shuturyoku_unko() : C() {

		rep(i, MAX) {

			int X = i;

			rep(j, 5) {

				C[i * 5 + 4 - j] = '0' + X % 10;

				X /= 10;

			}

		}

	}

};

constexpr shuturyoku_unko f;



const int dm = 1 << 17;

char *dn = cn, * di = dn, * owad = dn + dm - 20;

void putint(ll A) {

	if (owad < di) {

		fwrite(dn, 1, di - dn, stdout);

		di = dn;

	}

	int dig = 1;

	if (A >= 100000) {

		if (A >= 1000000000) dig = 5;

		else if (A >= 100000000) dig = 4;

		else if (A >= 10000000) dig = 3;

		else if (A >= 1000000) dig = 2;

		memcpy(di + dig, f.C + A % 100000 * 5, 5);

		A /= 100000;

		memcpy(di, f.C + A * 5 + 5 - dig, dig);

		di += 5 + dig;

	}

	else {

		if (A >= 10000) dig = 5;

		else if (A >= 1000) dig = 4;

		else if (A >= 100) dig = 3;

		else if (A >= 10) dig = 2;

		memcpy(di, f.C + A * 5 + 5 - dig, dig);

		di += dig;

	}

	*di++ = ' ';

}



int A[200001];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();



	int kei = 0;

	rep(i, N) {

		A[i] = getint();

		kei ^= A[i];

	}

	rep(i, N) putint(kei ^ A[i]);



	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}