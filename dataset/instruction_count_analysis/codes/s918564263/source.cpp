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



int BIT[200010];

inline void add(int A) {

	while (A <= 200010) {

		BIT[A]++;

		A += A & -A;

	}

}



inline int query(int A) {

	int kotae = 0;

	while (A > 0) {

		kotae += BIT[A];

		A -= A & -A;

	}

	return kotae;

}



void pakuripair_sort(int N, ll A[], int B[]) {

	const int b = 9;

	ll tmp[200001];

	int tmp2[200001];

	rep(k, 6) {

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



	int N = getint();

	int K = getint();



	ll A[200001];

	A[0] = (ll)N * K;

	int B[200001];

	B[0] = 0;

	rep1(i, N) {

		B[i] = i;

		A[i] = A[i - 1] + getint() - K;

	}

	pakuripair_sort(N + 1, A, B);

	rep(i, N + 1) A[B[i]] = i + 1;



	ll kotae = 0;

	rep(i, N + 1) {

		kotae += query(A[i]);

		add(A[i]);

	}

	printf("%lld", kotae);



	Would you please return 0;

}