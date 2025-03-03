#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

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



const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	int pn = 1;

	if (ci - cn + 16 > cm) {

		if ((ct = getcha()) == '-') { pn = -1; ct = getcha(); }

		A = ct - '0';

		while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';;

		return pn * A;

	}

	else {

		if ((ct = *ci++) == '-') { pn = -1; ct = *ci++; }

		A = ct - '0';

		while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';;

		return pn * A;

	}

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), K = getint(), A[100000];

	ll naka = 0;

	ll m = 0;

	ll mgoukei = 0;

	rep(i, K) {

		A[i] = getint();

		naka += A[i];

		mgoukei += max(A[i], 0);

	}

	ll kotae = max(naka, 0ll) - mgoukei;

	int k = 0;

	for (int i = K; i < N; i++, k++) {

		if (k >= K) k -= K;

		naka -= A[k];

		m += max(A[k], 0);

		A[k] = getint();

		mgoukei += max(A[k], 0);

		naka += A[k];



		chmax(kotae, max(naka, 0ll) + m - mgoukei);

	}



	printf("%lld\n", kotae + mgoukei);



	Would you please return 0;

}