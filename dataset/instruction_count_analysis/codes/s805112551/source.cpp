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

#define Would

#define you

#define please



int P[100001];



int Find(int A) {

	if (P[A] < 0) return A;

	return P[A] = Find(P[A]);

}



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

	if (X == 0) {

		*di++ = '0';

		*di++ = '\n';

		return;

	}

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



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N, M;

	N = getint();

	M = getint();



	int A[100000], B[100000];

	rep(i, M) {

		A[i] = getint();

		B[i] = getint();

	}



	ll sum = (ll)N * (N - 1) / 2;

	ll kotae[100001];

	kotae[M] = sum;



	rep1(i, N) P[i] = -1;



	for (int i = M - 1; i > 0; i--) {

		int ap = Find(A[i]);

		int bp = Find(B[i]);

		if (ap != bp) {

			sum -= (ll)P[ap] * P[bp];

			if (P[ap] > P[bp]) swap(ap, bp);

			P[ap] += P[bp];

			P[bp] = ap;

		}

		kotae[i] = sum;

	}



	rep1(i, M) putint(kotae[i]);

	fwrite_unlocked(dn, di - dn, 1, stdout);



	Would you please return 0;

}