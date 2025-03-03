#include"stdc++.h"

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



const int cm = 1 << 18;

char cn[cm], *ci = cn + cm, ct;

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



const int dm = 1 << 19;

char dn[dm], *di = dn;



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);



	fread(cn, 1, cm, stdin);

	ci = cn;

	int S[100000], T[100000];

	*S = 0;

	*T = 0;

	char C;

	int k = 0;

	while ((C = *ci++) != '\n') { 

		k++;

		*(S + k) = *(S + k - 1) + C - '@';

		if (*(S + k) > 2) *(S + k) -= 3;

	}

	k = 0;

	while ((C = *ci++) != '\n') {

		k++;

		*(T + k) = *(T + k - 1) + C - '@';

		if (*(T + k) > 2) *(T + k) -= 3;

	}



	int Q = getint();

	char n[3] = { 'N', 'O', '\n' };

	char y[4] = { 'Y', 'E', 'S', '\n' };

	rep(i, Q) {

		int a = getint();

		int b = getint();

		int c = getint();

		int d = getint();



		int kotae = *(S + b) - *(S + a - 1) - *(T + d) + *(T + c - 1) + 6;

		while (kotae > 2) kotae -= 3;



		if (kotae == 0) {

			memcpy(di, y, 4);

			di += 4;

		}

		else {

			memcpy(di, n, 3);

			di += 3;

		}

	}



	fwrite(dn, di - dn, 1, stdout);

	

	Would you please return 0;

}