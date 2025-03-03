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



void pakuri_sort(int N, ll A[]) {

	const int b = 8;

	ll tmp[200001];

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





	int R = getint(), C = getint(), N = getint();

	int RC3 = R + C + R;

	int RC4 = R + C + R + C;

	ll A[200000];

	int k = 0;

	rep(i, N) {

		int x = getint(), y = getint();

		int mae = k;

		ll k2 = ll(i) << 32;

		if (y == 0) A[k++] = k2 + x;

		else if (x == R) A[k++] = k2 + y + R;

		else if (y == C) A[k++] = k2 - x + RC3;

		else if (x == 0) A[k++] = k2 - y + RC4;

		x = getint();

		y = getint();

		if (y == 0) A[k++] = k2 + x;

		else if (x == R) A[k++] = k2 + y + R;

		else if (y == C) A[k++] = k2 - x + RC3;

		else if (x == 0) A[k++] = k2 - y + RC4;

		if (mae + 2 != k) k = mae;

	}



	pakuri_sort(k, A);



	int kazu = 0;

	int B[200000] = {};

	int OK = 1;

	rep(i, k) {

		int j = A[i] >> 32;

		if (B[j]) {

			if (B[j] != kazu--) OK = 0;

		}

		else B[j] = ++kazu;

	}



	if (OK) printf("YES\n");

	else printf("NO\n");



	Would you please return 0;

}