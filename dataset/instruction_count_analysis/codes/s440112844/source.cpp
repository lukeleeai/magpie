//いまだに厳密なところは考察できてない

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

	ll tmp[100001];

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



	int N = getint();

	ll LR[100000];

	rep(i, N) LR[i] = getint() + ((ll)getint() << 32);

	pakuri_sort(N, LR);



	int r1[100000];

	int r2 = 1e9;

	const int m = (1 << 31) - 1;



	r1[0] = LR[0] >> 32;

	rep1(i, N - 1) r1[i] = min(r1[i - 1], (int)(LR[i] >> 32));

	int kotae = (LR[N - 1] >> 32) - (LR[N - 1] & m) + max(-1, r1[N - 2] - (int)(LR[N - 2] & m));



	int lm = (int)(LR[N - 1] & m);

	for (int i = N - 2; i >= 1; i--) {

		chmin(r2, (int)(LR[i + 1] >> 32));

		chmax(kotae, (int)((LR[i] >> 32) - (LR[i] & m) + max(-1, min(r1[i - 1], r2) - lm)));

		chmax(kotae, max(-1, r1[i] - (int)(LR[i] & m)) + max(-1, (int)(r2 - lm)));

	}

	chmin(r2, (int)(LR[1] >> 32));

	chmax(kotae, (int)((LR[0] >> 32) - (LR[0] & m) + max(-1, r2 - lm)));

	chmax(kotae, max(-1, r1[0] - (int)(LR[0] & m)) + max(-1, (int)(r2 - lm)));



	printf("%d", kotae + 2);



	Would you please return 0;

}