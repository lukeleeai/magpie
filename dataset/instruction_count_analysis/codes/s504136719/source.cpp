#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

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

	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



const int dm = 1 << 21;

char dn[dm], * di = dn;

inline void putkotae(int X, int Y) {

	char C[12];

	rep(i, 6) {

		*(C + i) = '0' + Y % 10;

		Y /= 10;

	}

	rep(i, 6) {

		*(C + i + 6) = '0' + X % 10;

		X /= 10;

	}

	for (int i = 11; i >= 0; i--)* di++ = (*(C + i));

	*di++ = '\n';

}



ll tmp[100001];

void pakuri_sort(int N, ll A[]) {

	const int b = 8;

	rep(k, 4) {

		int kazu[1 << b] = {}, kazu2[1 << b] = {};

		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];

		for (int i = N - 1; i >= 0; i--) tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];

		k++;

		rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];

		for (int i = N - 1; i >= 0; i--) A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];

	}

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), M = getint();

	int P[100000], PK[100001] = {};

	ll S[100000];

	rep(i, M) {

		P[i] = getint();

		S[i] = ((ll)i << 32) + getint();

	}

	pakuri_sort(M, S);



	rep(i, M) {

		int j = S[i] >> 32;

		tmp[j] = ++PK[P[j]];

	}

	rep(i, M) putkotae(P[i], tmp[i]);



	fwrite_unlocked(dn, di - dn, 1, stdout);



	Would you please return 0;

}