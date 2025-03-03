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



int to[200001], ne[200001], he[100001];

bool d[100001], D[100001];

void dfs(int A, int prev, bool B) {

	D[A] = B;

	for (int i = he[A]; i; i = ne[i]) {

		if (prev != to[i]) dfs(to[i], A, B ^ d[i >> 1]);

	}

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int k = 2;

	rep1(i, N - 1) {

		int x = getint();

		int y = getint();

		bool z = getint() & 1;

		to[k] = y;

		ne[k] = he[x];

		he[x] = k++;

		to[k] = x;

		ne[k] = he[y];

		he[y] = k++;

		d[i] = z;

	}



	dfs(1, 0, 0);

	const int dm = 1 << 18;

	char dn[dm], * di = dn;

	rep1(i, N) {

		*di++ = '0' + D[i];

		*di++ = '\n';

	}

	fwrite_unlocked(dn, di - dn, 1, stdout);



	Would you please return 0;

}