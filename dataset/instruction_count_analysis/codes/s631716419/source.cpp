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

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



const int dm = 1 << 21;

char dn[dm], * di = dn, dt;

inline void putint(int X) {

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



int tmp[200001], tmp2[200001], tmp3[200001];

void pakuri_sort2(int N, int A[], int B[]) {

	const int b = 8;

	rep(k, 4) {

		int kazu[1 << b] = {}, kazu2[1 << b] = {};

		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];

		for (int i = N - 1; i >= 0; i--) {

			tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];

			tmp2[kazu[A[i] >> k * b & ((1 << b) - 1)]] = B[i];

		}

		k++;

		rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];

		for (int i = N - 1; i >= 0; i--) {

			A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];

			B[kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp2[i];

		}

	}

}

void pakuri_sort3(int N, int A[], int B[], int C[]) {

	const int b = 8;

	rep(k, 4) {

		int kazu[1 << b] = {}, kazu2[1 << b] = {};

		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];

		for (int i = N - 1; i >= 0; i--) {

			tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];

			tmp2[kazu[A[i] >> k * b & ((1 << b) - 1)]] = B[i];

			tmp3[kazu[A[i] >> k * b & ((1 << b) - 1)]] = C[i];

		}

		k++;

		rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];

		for (int i = N - 1; i >= 0; i--) {

			A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];

			B[kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp2[i];

			C[kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp3[i];

		}

	}

}



int S[200002], T[200002], X[200002];

int D[200002];

int P[200002];

int kotae[200002] = {};

int ima;

int Find(int A) {

	if (D[A] >= T[ima] - X[ima]) return A - 1;

	if (P[A]) return P[A] = Find(P[A] + 1);

	else {

		kotae[A] = X[ima];

		return P[A] = Find(A + 1);

	}

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), Q = getint();

	rep1(i, N) {

		S[i] = getint();

		T[i] = getint();

		X[i] = getint();

	}

	pakuri_sort3(N, X + 1, S + 1, T + 1);

	rep1(i, N) tmp3[i] = S[i] - X[i] + 1000000000;

	rep1(i, N) S[i] = i;

	pakuri_sort2(N, tmp3 + 1, S + 1);



	rep1(i, Q) D[i] = getint();

	D[Q + 1] = 2e9;



	int k = 1;

	rep1(i, N) {

		while (D[k] < tmp3[i] - 1000000000) k++;

		tmp[S[i]] = k;

	}



	for (ima = 1; ima <= N; ima++) Find(tmp[ima]);



	rep1(i, Q) {

		if (kotae[i] == 0) {

			*di++ = '-';

			*di++ = '1';

			*di++ = '\n';

		}

		else putint(kotae[i]);

	}



	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}