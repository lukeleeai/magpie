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



//当時の自分の方が天才っぽい

int D[100001];

int P[100001];

int to[100001], ne[100001], he[100001];

int sagasu(int A) {

	if (D[A]) return D[A];

	int ret = 1;

	for (int i = he[A]; i; i = ne[i]) {

		int u = to[i];

		int kari = sagasu(u) + 1;

		if (ret < kari) {

			ret = kari;

			P[A] = u;

		}

	}

	return D[A] = ret;

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



const int dm = 1 << 20;

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

	*di++ = '\n';

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), M = getint();

	rep1(i, N + M - 1) {

		int a = getint(), b = getint();

		to[i] = a;

		ne[i] = he[b];

		he[b] = i;

	}



	rep1(i, N) {

		sagasu(i);

		putint(P[i]);

	}

	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}