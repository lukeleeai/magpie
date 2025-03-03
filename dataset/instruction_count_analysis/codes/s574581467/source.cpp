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



int A[50001];

bool OK = 1;

ll ans = 1;

const ll mod = 1e9 + 7;

const int ma = 31;



int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint();

	if (N & 1) {

		rep(i, N) {

			int a = getint();

			if (a & 1) {

				printf("0");

				return 0;

			}

			A[a / 2]++;

		}

		if (A[0] != 1) OK = 0;

		rep1(i, N / 2) {

			if (A[i] != 2) OK = 0;

			ans = ans << 1;

			if (!(i & ma)) ans %= mod;

		}

		if (OK) printf("%lld", ans % mod);

		else printf("0");

	}

	else {

		rep(i, N) {

			int a = getint();

			if (!(a & 1)) {

				printf("0");

				return 0;

			}

			A[a / 2]++;

		}

		rep(i, N / 2) {

			if (A[i] != 2) OK = 0;

			ans = ans << 1;

			if (!(i & ma)) ans %= mod;

		}

		if (OK) printf("%lld", ans % mod);

		else printf("0");

	}



	Would you please return 0;

}