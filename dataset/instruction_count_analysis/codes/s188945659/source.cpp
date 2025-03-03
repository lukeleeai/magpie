#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<queue>

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



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();



	int A[100000];

	rep(i, N) A[i] = getint() ^ ((i & 1) << 30);



	const int b = 8;

	int tmp[100001];

	int kazu[1 << b] = {}, kazu2[1 << b] = {}, kazu3[1 << b] = {}, kazu4[1 << b] = {};

	rep(i, N) kazu[A[i] & ((1 << b) - 1)]++;

	rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];

	for (int i = N - 1; i >= 0; i--) tmp[--kazu[A[i] & ((1 << b) - 1)]] = A[i];

	rep(i, N) kazu2[tmp[i] >> b & ((1 << b) - 1)]++;

	rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];

	for (int i = N - 1; i >= 0; i--) A[--kazu2[tmp[i] >> b & ((1 << b) - 1)]] = tmp[i];

	rep(i, N) kazu3[A[i] >> 2 * b & ((1 << b) - 1)]++;

	rep(i, (1 << b) - 1) kazu3[i + 1] += kazu3[i];

	for (int i = N - 1; i >= 0; i--) tmp[--kazu3[A[i] >> 2 * b & ((1 << b) - 1)]] = A[i];

	rep(i, N) kazu4[tmp[i] >> 24 & ((1 << 6) - 1)]++;

	rep(i, (1 << 6) - 1) kazu4[i + 1] += kazu4[i];

	for (int i = N - 1; i >= 0; i--) A[--kazu4[tmp[i] >> 24 & ((1 << 6) - 1)]] = tmp[i];



	int kotae = 0;

	for (int i = 0; i < N; i += 2) {

		kotae += A[i] >> 30 & 1;

	}

	printf("%d\n", kotae);



	Would you please return 0;

}