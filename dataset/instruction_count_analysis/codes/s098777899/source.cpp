#pragma GCC optimize ("Ofast")

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



int K[200001];

int zentai, N;

ll kotae[200001];

int C[200001];

int E[400001], ne[400001], he[200001];

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

char dn[2400000], * di = dn;

inline void putint(ll X) {

	if (X == 0) {

		*di++ = '0';

		*di++ = '\n';

		return;

	}

	int keta = 0;

	char C[15];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	*di++ = '\n';

}



void dfs(int p, int mae) {

	int k = K[C[p]] + zentai;

	int k0 = k;

	for (int to = he[p]; to; to = ne[to]) {

		if (mae != E[to]) {

			dfs(E[to], p);

			int sa = K[C[p]] + zentai - k;

			kotae[C[p]] -= ll(sa) * (sa + 1) >> 1;

			k += sa;

		}

	}

	zentai++;

	K[C[p]] = k0 - zentai;

}





int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	N = getint();

	rep1(i, N) C[i] = getint();

	int k = 1;

	rep(i, N - 1) {

		int a = getint(), b = getint();



		E[k] =b;

		ne[k] = he[a];

		he[a] = k++;

		E[k] = a;

		ne[k] = he[b];

		he[b] = k++;

	}



	dfs(1, -1);

	ll n = ll(N) * (N + 1) / 2;

	rep1(i, N) {

		int sa = K[i] + zentai;

		putint(n + kotae[i] - (ll(sa) * (sa + 1) >> 1));

	}

	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}