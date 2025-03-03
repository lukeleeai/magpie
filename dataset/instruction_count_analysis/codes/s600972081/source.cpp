#include "stdc++.h"

#define range(i, a, b) for(int i = (a); i < (b); i++)

#define rep(i, a) range(i, 0, a)

using namespace std;

const int INF = 1000000000;



int main() {

	int d, n;

	while (cin >> d >> n, d) {

		int a[n], e[n], r[n];

		rep (i, n) cin >> a[i] >> e[i] >> r[i];

		//耐久値、経験値

		int dp[d + 1][101];

		rep (i, d + 1) rep (j, 101) dp[i][j] = INF;

		dp[d][0] = 0;

		for (int i = d; i >= 0; i--) rep (j, 101) {

			if (dp[i][j] == INF) continue;

			rep (k, n) {

				if (r[k] > j) continue;

				//a[i] -> 減る耐久値, e[i] -> 得る経験値

				dp[max(0, i - a[k])][min(100, j + e[k])] = min(dp[max(0, i - a[k])][min(100, j + e[k])],

																											 dp[i][j] + 1);

			}

		}

		int ans = INF;

		rep (i, 101) ans = min(ans, dp[0][i]);

		cout << (ans == INF ? "NA" : to_string(ans)) << endl;

	}

	return 0;

}
