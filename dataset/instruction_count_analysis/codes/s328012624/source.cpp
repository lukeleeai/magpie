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



ll dp[100002];

int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = getint(), M = getint();

	if (M > N / 2) printf("0");

	else {

		rep(i, M) {

			dp[getint() + 1] = 1;

		}



		dp[0] = 0;

		dp[1] = 1;

		const ll mod = 1e9 + 7;

		int meyasu = 0;

		rep1(i, N) {

			if (!dp[i + 1]) {

				dp[i + 1] = dp[i] + dp[i - 1];

				meyasu++;

				if (meyasu >= 30) {

					dp[i] %= mod;

					dp[i + 1] %= mod;

					meyasu = 0;

				}

			}

			else dp[i + 1] = 0;

		}

		printf("%lld", dp[N + 1] % mod);

	}



	Would you please return 0;

}