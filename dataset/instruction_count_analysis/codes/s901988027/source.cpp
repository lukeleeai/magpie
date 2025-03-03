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

ll tmp[100001];

void pakuri_sort(int N, int A[]) {

	const int b = 8;

	rep(k, 4) {

		int kazu[1 << b] = {}, kazu2[1 << b] = {};

		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;

		for (int i = (1 << b) - 2; i >= 0; i--) kazu[i] += kazu[i + 1];

		for (int i = N - 1; i >= 0; i--) tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];

		k++;

		rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;

		for (int i = (1 << b) - 2; i >= 0; i--) kazu2[i] += kazu2[i + 1];

		for (int i = N - 1; i >= 0; i--) A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];

	}

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), M = getint(), V = getint(), P = getint();

	int A[100001];

	rep(i, N) A[i] = getint();

	pakuri_sort(N, A);

	tmp[P - 1] = 0;

	for (int i = P - 1; i < N; i++) tmp[i + 1] = tmp[i] + A[i];



	int L = P - 1, R = N;

	while (L + 1 < R) {

		int m = (L + R) / 2;

		int a = A[m] + M;

		if (P > V) {

			if (a >= A[P - 1]) L = m;

			else R = m;

		}

		else if (a < A[P - 1]) R = m;

		else {

			ll kari = ll(N - m - 1 - V + P) * M;

			kari -= tmp[m];

			kari += ll(m - P + 1) * a;



			if (0 <= kari) L = m;

			else R = m;

		}

	}



	printf("%d", R);





	Would you please return 0;

}