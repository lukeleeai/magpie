#pragma GCC optimize ("O3")

#pragma GCC target ("avx")

//#include"stdc++.h"

#include<cstdio>

#include<algorithm>

#include<vector>

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





int main() {

	//cin.tie(0);

	//ios::sync_with_stdio(false);





	int N = 0;

	char c;

	while ((c = getchar_unlocked()) >= '0') N = N * 10 + c - '0';



	int dp[3000] = {};

	dp[0] = 1;

	const int mod = 1e9 + 7;

	rep(i, N - 1) {

		if (getchar_unlocked() == '<') {

			int k = 0;

			int tmp = dp[0];

			dp[0] = 0;

			rep(j, i + 1) {

				k += tmp;

				if (k >= mod) k -= mod;

				tmp = dp[j + 1];

				dp[j + 1] = k;

			}

		}

		else {

			int k = 0;

			for (int j = i; j >= 0; j--) {

				k += dp[j];

				if (k >= mod) k -= mod;

				dp[j] = k;

			}

		}

	}

	ll kotae = 0;

	rep(i, N) kotae += dp[i];

	printf("%lld", kotae % mod);



	Would you please return 0;

}