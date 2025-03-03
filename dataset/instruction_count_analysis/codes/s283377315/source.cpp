#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

//#include<vector>

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

	int pn = 1;

	if (ci - cn + 16 > cm) {

		if ((ct = getcha()) == '-') { pn = -1; ct = getcha(); }

		A = ct - '0';

		while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';;

		return pn * A;

	}

	else {

		if ((ct = *ci++) == '-') { pn = -1; ct = *ci++; }

		A = ct - '0';

		while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';;

		return pn * A;

	}

}



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	int s1 = 0;

	ll kotae1 = 0;

	int s2 = 0;

	ll kotae2 = 0;

	int a = 0;

	rep(i, N / 2) {

		a = getint();

		s1 += a;

		s2 += a;

		if (s1 <= 0) {

			kotae1 += 1 - s1;

			s1 = 1;

		}

		if (s2 >= 0) {

			kotae2 += s2 + 1;

			s2 = -1;

		}

		a = getint();

		s1 += a;

		s2 += a;

		if (s2 <= 0) {

			kotae2 += 1 - s2;

			s2 = 1;

		}

		if (s1 >= 0) {

			kotae1 += s1 + 1;

			s1 = -1;

		}

	}

	if (N & 1) {

		a = getint();

		s1 += a;

		s2 += a;

		if (s1 <= 0) {

			kotae1 += 1 - s1;

			s1 = 1;

		}

		if (s2 >= 0) {

			kotae2 += s2 + 1;

			s2 = -1;

		}

	}

	printf("%lld", min(kotae1, kotae2));



	Would you please return 0;

}