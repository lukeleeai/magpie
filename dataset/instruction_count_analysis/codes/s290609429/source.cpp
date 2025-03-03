#include <iostream>

#include <vector>

using namespace std;

constexpr int MOD = 998244353;



int main() {

	int n, s;

	scanf("%d %d", &n, &s);

	vector<int> a(n);

	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);



	vector<vector<int>> dp(3, vector<int>(s + 1));

	dp[0][0] = 1;

	for (int i = 0; i < n; ++i) {

		vector<vector<int>> next(3, vector<int>(s + 1));

		for (int j = 0; j <= s; ++j) {

			(next[0][j] += dp[0][j]) %= MOD;

			(next[1][j] += (dp[0][j] + dp[1][j]) % MOD) %= MOD;

			(next[2][j] += ((dp[0][j] + dp[1][j]) % MOD + dp[2][j]) % MOD) %= MOD;

			if (j + a[i] <= s) {

				(next[1][j + a[i]] += (dp[0][j] + dp[1][j]) % MOD) %= MOD;

				(next[2][j + a[i]] += (dp[0][j] + dp[1][j]) % MOD) %= MOD;

			}

		}

		dp = next;

	}

	printf("%d", dp[2][s]);

	return 0;

}