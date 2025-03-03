#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

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



//えびちゃんの気持ちが分かってきた気がしたが

char cn[2400000], * ci = cn, * di = cn, ct, buf[8];

const ll ma0 = 1157442765409226768;

const ll ma1 = 1085102592571150095;

const ll ma2 = 71777214294589695;

const ll ma3 = 281470681808895;

const ll ma4 = 4294967295;

inline int getint() {

	memcpy(buf, ci, 8);

	ll tmp = *(ll*)buf;

	int dig = 68 - __builtin_ctzll((tmp & ma0) ^ ma0);

	tmp = (tmp << dig) & ma1;

	tmp = tmp * 10 + (tmp >> 8) & ma2;

	tmp = tmp * 100 + (tmp >> 16) & ma3;

	tmp = tmp * 10000 + (tmp >> 32) & ma4;

	ci += (64 - dig >> 3) + 1;

	return tmp;

}



inline void putint(ll X) {

	if (X == 0) {

		*di++ = '0';

		*di++ = '\n';

		return;

	}

	int keta = 0;

	char C[20];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	*di++ = '\n';

}



int A[200000];

int B[200010];



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	fread(cn, 1, 1400100, stdin);



	int N = getint();

	ll kotae = 0;

	rep(i, N) kotae += B[(A[i] = getint())]++;

	rep(i, N) putint(kotae - B[A[i]] + 1);

	fwrite(cn, 1, di - cn, stdout);



	Would you please return 0;

}