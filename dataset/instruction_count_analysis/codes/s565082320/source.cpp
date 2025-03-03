#include <iostream>

#include <vector>

using namespace std;

constexpr long long MOD = 998244353;



int main() {

	int n, s; cin >> n >> s;

	vector<int> a(n);

	for (int i = 0; i < n; ++i) cin >> a[i];



	vector<vector<long long>> dp(3, vector<long long>(s + 3003));

	dp[0][0] = 1;

	for (int i = 0; i < n; ++i) {

		vector<vector<long long>> next(3, vector<long long>(s + 3003));

		for (int j = 0; j <= s; ++j) {

			(next[0][j] += dp[0][j]) %= MOD;

			(next[1][j] += dp[0][j] + dp[1][j]) %= MOD;

			(next[1][j + a[i]] += dp[0][j] + dp[1][j]) %= MOD;

			(next[2][j] += dp[0][j] + dp[1][j] + dp[2][j]) %= MOD;

			(next[2][j + a[i]] += dp[0][j] + dp[1][j]) %= MOD;

		}

		dp = next;

	}

	cout << dp[2][s];

	return 0;

}