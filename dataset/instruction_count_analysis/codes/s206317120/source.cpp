#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

//#include<vector>

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



void pakuripair_sort(int N, int A[], int B[]) {

	const int b = 8;

	int tmp[200001], tmp2[200001];

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



int X[200001], Y[100001], K[200001];

int x[200001], y[200001];

int Find(int A) {

	if (Y[A] < 0) return A;

	return Y[A] = Find(Y[A]);

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	rep(i, N) {

		X[i] = getint();

		Y[i] = getint();

		K[i] = i;

	}

	pakuripair_sort(N, X, K);

	rep(i, N - 1) {

		X[i] = X[i + 1] - X[i];

		x[i] = K[i];

		y[i] = K[i + 1];

		K[i] = i;

	}

	K[N - 1] = N - 1;

	pakuripair_sort(N, Y, K);

	for (int i = N - 1; i < N + N - 2; i++) {

		X[i] = Y[i - N + 2] - Y[i - N + 1];

		x[i] = K[i - N + 1];

		y[i] = K[i - N + 2];

	}

	rep(i, N + N - 2) K[i] = i;



	pakuripair_sort(N + N - 2, X, K);



	rep(i, N) Y[i] = -1;

	ll kotae = 0;

	rep(i, N + N - 2) {

		int a = Find(x[K[i]]);

		int b = Find(y[K[i]]);

		if (a != b) {

			if (Y[a] > Y[b]) swap(a, b);

			Y[a] += Y[b];

			Y[b] = a;

			kotae += X[i];

		}

	}



	printf("%lld", kotae);



	Would you please return 0;

}