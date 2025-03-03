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



const int dm = 1 << 21;

char dn[dm], * di = dn, dt;

inline void putint(ll X) {

	int keta = 0;

	char C[20];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	*di++ = '\n';

}



int N;

ll D[100001];

int E[200001], Ed[200001], E2[200001], H[100001];

void dfs(int A, ll B) {

	*(D + A) = B;

	for (int i = H[A]; i; i = E2[i]) if (!(*(D + E[i]))) dfs(E[i], B + Ed[i]);

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int k = 1;

	rep(i, N - 1) {

		int a = getint();

		int b = getint();

		int c = getint();

		E[k] = b;

		Ed[k] = c;

		E2[k] = H[a];

		H[a] = k++;

		E[k] = a;

		Ed[k] = c;

		E2[k] = H[b];

		H[b] = k++;

	}

	int Q = getint();

	int K = getint();

	dfs(K, 1);

	rep(i, Q) {

		int x = getint();

		int y = getint();

		putint(*(D + x) + *(D + y) - 2);

	}



	fwrite_unlocked(dn, 1, di - dn, stdout);



	Would you please return 0;

}