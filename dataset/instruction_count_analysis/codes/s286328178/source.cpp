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

const int dm = 1 << 21;

char dn[dm], * di = dn;



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int A[500001];

	A[0] = getint();

	int d[500000];

	rep(i, N) {

		d[i] = getint();

		A[i + 1] = min(A[i], abs(d[i] - A[i]));

	}

	int B = 1;

	for (int i = N - 1; i >= 0; i--) {

		A[i] = (A[i] >= B);

		if (B <= 1e9 && B * 2 > d[i]) B = B + d[i];

	}

	int Q = getint();

	rep(i, Q) {

		int q = getint() - 1;

		if (A[q]) {

			*di++ = 'Y';

			*di++ = 'E';

			*di++ = 'S';

			*di++ = '\n';

		}

		else {

			*di++ = 'N';

			*di++ = 'O';

			*di++ = '\n';

		}

	}



	fwrite_unlocked(dn, di - dn, 1, stdout);



	Would you please return 0;

}