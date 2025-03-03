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

	if (ci - cn + 16 > cm) {

		int A = getcha() - '0';

		while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

		return A;

	}

	else {

		int A = *ci++ - '0';

		while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

		return A;

	}

}



int P[100001];

int Find(int A) {

	if (P[A] < 0) return A;

	return P[A] = Find(P[A]);

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), M = getint();

	rep1(i, N) P[i] = -1;

	for (int i = 1; i < 2 * M; i += 2) {

		int a = Find(getint());

		int b = Find(getint());

		getint();

		if (a == b) continue;

		if (P[a] > P[b]) swap(a, b);

		P[a] += P[b];

		P[b] = a;

	}



	int kotae = 0;

	rep1(i, N) {

		if (P[i] < 0) kotae++;

	}

	printf("%d", kotae);



	Would you please return 0;

}