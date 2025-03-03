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





	int X = getint(), K = getint();

	int r[100002];

	rep1(i, K) r[i] = getint();

	r[0] = 0;

	r[K + 1] = 2e9;



	int L = 0;

	int R = X;

	int takasa = 0;

	int katamuki = -1;

	int *ri = r;



	int Q = getint();

	rep(i, Q) {

		int t = getint(), a = getint();

		

		while (t > *(ri + 1)) {

			takasa += katamuki * (*(ri + 1) - *ri);

			if (katamuki < 0) {

				L -= min(0, takasa + L);

				R -= min(0, takasa + R);

			}

			else {

				L -= max(0, takasa + L - X);

				R -= max(0, takasa + R - X);

			}

			ri++;

			katamuki *= -1;

		}

		chmax(a, L);

		chmin(a, R);

		a += takasa + katamuki * (t - *ri);

		chmax(a, 0);

		chmin(a, X);

		putint(a);

	}



	fwrite(dn, 1, di - dn, stdout);



	Would you please return 0;

}