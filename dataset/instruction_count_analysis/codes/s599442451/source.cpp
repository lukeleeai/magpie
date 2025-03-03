#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

#include<cstring>

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



int C[300000], D[300000];

void pakuripair_sort(int N, int A[], int B[]) {

	const int b = 8;

	rep(k, 4) {

		int kazu[1 << b] = {}, kazu2[1 << b] = {};

		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];

		for (int i = N - 1; i >= 0; i--) {

			C[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];

			D[kazu[A[i] >> k * b & ((1 << b) - 1)]] = B[i];

		}

		k++;

		rep(i, N) kazu2[C[i] >> k * b & ((1 << b) - 1)]++;

		rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];

		for (int i = N - 1; i >= 0; i--) {

			A[--kazu2[C[i] >> k * b & ((1 << b) - 1)]] = C[i];

			B[kazu2[C[i] >> k * b & ((1 << b) - 1)]] = D[i];

		}

	}

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int A[300000], B[300000], A0[100000];

	ll S[100001];

	S[0] = 0;

	ll kari = 0;

	int saishou = 1e9;

	int saidai = 0;

	rep(i, 3 * N) {

		A[i] = getint();

		B[i] = i;

	}

	rep(i, N) S[0] += A[i];

	for (int i = N; i < 2 * N; i++) A0[i - N] = A[i];

	for (int i = 2 * N; i < 3 * N; i++) kari += A[i];

	

	pakuripair_sort(3 * N, A, B);

	rep(i, 3 * N) C[B[i]] = i;



	memset(B, 0, sizeof(B));

	rep(i, N) {

		B[C[i]] = 1;

		chmin(saishou, C[i]);

	}



	rep(i, N) {

		if (saishou < C[i + N]) {

			B[C[i + N]] = 1;

			while (!B[saishou]) saishou++;

			B[saishou] = 0;

			S[i + 1] = S[i] + A0[i] - A[saishou];

		}

		else S[i + 1] = S[i];

	}



	memset(B, 0, sizeof(B));

	for (int i = 2 * N; i < 3 * N; i++) {

		B[C[i]] = 1;

		chmax(saidai, C[i]);

	}



	ll kotae = S[N] - kari;

	for (int i = N - 1; i >= 0; i--) {

		if (saidai > C[i + N]) {

			B[C[i + N]] = 1;

			while (!B[saidai]) saidai--;

			B[saidai] = 0;

			kari += A0[i] - A[saidai];

		}

		chmax(kotae, S[i] - kari);

	}



	printf("%lld", kotae);



	Would you please return 0;

}