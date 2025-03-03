#pragma GCC optimize ("Ofast")

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



//const int CM = 130000, CL = 12;

//char cn[CM + CL], * ci = cn + CM + CL, * owa = cn + CM, ct;

char cn[2200010], * ci = cn, ct;



const ll ma0 = 1157442765409226768;

const ll ma1 = 1085102592571150095;

const ll ma2 = 71777214294589695;

const ll ma3 = 281470681808895;

const ll ma4 = 4294967295;

inline int getint() {

	ll tmp = *(ll*)ci;



	//うーん

	ll u_n = ((tmp & ma0) ^ ma0);

	if (!u_n) {

		ci += 8;

		while (*ci++ >= '0');

		return 1000000000;

	}

	int dig = 68 - __builtin_ctzll(u_n);

	tmp = tmp << dig & ma1;

	tmp = tmp * 10 + (tmp >> 8) & ma2;

	tmp = tmp * 100 + (tmp >> 16) & ma3;

	tmp = tmp * 10000 + (tmp >> 32) & ma4;

	ci += (72 - dig >> 3);

	return tmp;

}



int B[200000];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);



	fread(cn, 1, 2200000, stdin);

	int N = getint();



	ll kotae = 0;

	rep(i, N) {

		int a = getint();

		if (i + a < N) B[i + a]++;

		if (i - a >= 0) kotae += B[i - a];

	}

	printf("%lld", kotae);



	Would you please return 0;

}