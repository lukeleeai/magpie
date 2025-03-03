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



char S[100001], T[100001];



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int k = 0;

	while ((ct = getchar_unlocked()) >= 'A') {

		S[k + 1] = S[k] + ct - '@';

		if (S[k + 1] >= 3) S[k + 1] -= 3;

		k++;

	}

	k = 0;

	while ((ct = getchar_unlocked()) >= 'A') {

		T[k + 1] = T[k] + ct - '@';

		if (T[k + 1] >= 3) T[k + 1] -= 3;

		k++;

	}

	int Q = getint();

	rep(i, Q) {

		int a = getint() - 1;

		int b = getint();

		int c = getint() - 1;

		int d = getint();

		a = S[a] - S[b];

		if (a < 0) a += 3;

		c = T[c] - T[d];

		if (c < 0) c += 3;



		if (a != c) {

			*di++ = 'N';

			*di++ = 'O';

			*di++ = '\n';

		}

		else {

			*di++ = 'Y';

			*di++ = 'E';

			*di++ = 'S';

			*di++ = '\n';

		}

	}



	fwrite_unlocked(dn, di - dn, 1, stdout);



	Would you please return 0;

}