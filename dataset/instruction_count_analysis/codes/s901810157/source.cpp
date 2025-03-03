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



int N;

int C[200001];

int E[400001];

int next[400001];

int H[200001];

void dfs(int p, int prev, int c) {

	C[p] = c + C[p];

	for (int i = H[p]; i; i = next[i]) {

		if (E[i] != prev) dfs(E[i], p, C[p]);

	}

}



const int cm = 1 << 17;

char cn[cm], * ci = cn + cm, ct;

inline char getcha() {

	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }

	return *ci++;

}

inline int getint() {

	int A = 0;

	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

	return A;

}



const int dm = 1 << 21;

char dn[dm], * di = dn;

inline void putint(int X) {

	if (X == 0) {

		*di++ = '0';

		*di++ = '\n';

		return;

	}

	int keta = 0;

	char C[10];

	while (X) {

		*(C + keta) = '0' + X % 10;

		X /= 10;

		keta++;

	}

	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));

	*di++ = ' ';

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), Q = getint();

	int k = 1;

	rep(i, N - 1) {

		int a = getint(), b = getint();

		E[k] = b;

		next[k] = H[a];

		H[a] = k++;

		E[k] = a;

		next[k] = H[b];

		H[b] = k++;

	}

	rep(i, Q) {

		int p = getint(), x = getint();

		C[p] += x;

	}

	dfs(1, 0, 0);



	rep1(i, N) putint(C[i]);



	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}