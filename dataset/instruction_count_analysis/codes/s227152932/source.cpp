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



int D[100001];

int to[200001], ne[200001], he[100001];

void dfsA(int A, int d) {

	D[A] = d;

	for (int t = he[A]; t; t = ne[t]) {

		if (!D[to[t]]) dfsA(to[t], d + 1);

	}

}



int saidai = -1;

void dfsT(int A, int d) {

	chmax(saidai, D[A]);

	D[A] = 0;

	for (int t = he[A]; t; t = ne[t]) {

		if (D[to[t]] > d + 1) dfsT(to[t], d + 1);

	}

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int u = getint(), v = getint();

	int k = 1;

	rep(i, N - 1) {

		int a = getint(), b = getint();

		to[k] = b;

		ne[k] = he[a];

		he[a] = k++;

		to[k] = a;

		ne[k] = he[b];

		he[b] = k++;

	}

	dfsA(v, 1);

	dfsT(u, 1);

	if (saidai - 2 <= 0) printf("0");

	else printf("%d", saidai - 2);



	Would you please return 0;

}