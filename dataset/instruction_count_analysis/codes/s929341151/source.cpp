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

ll XY[200000], tmp[200000];

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





	int N = getint();

	int saidai = 0;

	int saishou = 1e9;

	int saidai2 = 0;

	int saishou2 = 1e9;

	rep(i, N) {

		int x = getint();

		int y = getint();

		if (x > y) swap(x, y);

		chmax(saidai, y);

		chmax(saidai2, x);

		chmin(saishou, x);

		chmin(saishou2, y);

		XY[i] = ((ll)y << 32) + x;

	}

	ll kotae = 1ll * (saidai - saishou2) * (saidai2 - saishou);



	pakuri_sort(N, XY);



	int m = (1 << 31) - 1;

	int saishou3 = 1e9;

	ll haba = saidai - saishou;

	rep(i, N) {

		int x = XY[i] & m;

		int y = XY[i] >> 32;

		if (saishou3 < x) break;

		chmin(kotae, haba * (saidai2 - x));

		chmin(saishou3, y);

		chmax(saidai2, y);

	}

	chmin(kotae, haba* (saidai2 - saishou3));

	printf("%lld", kotae);



	Would you please return 0;

}