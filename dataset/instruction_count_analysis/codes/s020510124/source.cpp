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



const int CM = 1400000;

char cn[CM], * ci = cn, ct;

const ll ma0 = 1157442765409226768;

const ll ma1 = 1085102592571150095;

const ll ma2 = 71777214294589695;

const ll ma3 = 281470681808895;

const ll ma4 = 4294967295;

inline int getint() {

	ll tmp = *(ll*)ci;

	int dig = 68 - __builtin_ctzll((tmp & ma0) ^ ma0);

	tmp = tmp << dig & ma1;

	tmp = tmp * 10 + (tmp >> 8) & ma2;

	tmp = tmp * 100 + (tmp >> 16) & ma3;

	tmp = tmp * 10000 + (tmp >> 32) & ma4;

	ci += (72 - dig >> 3);

	return tmp;

}

char* di = cn;

inline void putint(int X) {

	if (X < 10) {

		*di++ = X + '0';

		*di++ = '\n';

		return;

	}

	int keta = 0;

	char C[10];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	*di++ = '\n';

}



int A[200001];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);



	fread(cn, 1, CM, stdin);

	int N = getint();

	rep(i, N - 1) A[getint()]++;



	rep1(i, N) putint(A[i]);



	fwrite(cn, 1, di - cn, stdout);





	Would you please return 0;

}