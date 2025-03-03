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



int tmp[100001], tmp2[100001];

void pakuri_sort(int N, int A[]) {

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



void pakuripair_sort(int N, int A[], int B[]) {

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



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), M = getint();



	int A[100000];

	rep(i, N) A[i] = getint();

	pakuri_sort(N, A);



	int B[100000], C[100000];

	rep(i, M) {

		B[i] = getint();

		C[i] = getint();

	}

	pakuripair_sort(M, C, B);



	ll kotae = 0;

	int kazu = 0;

	for (int i = M - 1; i >= 0; i--) {

		int makkusu = min(B[i], N - kazu);

		rep(j, makkusu) kotae += max(A[kazu++], C[i]);

	}



	for (int i = kazu; i < N; i++) kotae += A[i];



	printf("%lld", kotae);



	Would you please return 0;

}