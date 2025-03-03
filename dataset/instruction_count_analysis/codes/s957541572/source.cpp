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



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int M = 0;

	while ((ct = getcha()) >= '0') M = M * 10 + ct - '0';

	ll nagasa = 0;

	ll ketawa = 0;

	rep(i, M) {

		if (ci - cn + 20 > cm) {

			int d = getcha() - '0';

			getcha();

			ll A = 0;

			while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';

			ketawa += d * A;

			nagasa += A;

		}

		else {

			int d = *ci++ - '0';

			ci++;

			ll A = 0;

			while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';

			ketawa += d * A;

			nagasa += A;

		}

	}



	ll kotae = nagasa - 1;

	kotae += (ketawa - 1) / 9;



	printf("%lld", kotae);





	Would you please return 0;

}