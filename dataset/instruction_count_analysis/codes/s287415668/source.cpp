#include<iostream>

#include<algorithm>

#include<vector>

using namespace std;

int n, a[100000], dp[5005][2];

int main() {

	cin >> n; for (int i = 0; i < n - 1; i++)cin >> a[i];

	for (int i = 0; i < 5005; i++) { dp[i][0] = 999999999; dp[i][1] = 999999999; }

	dp[n / 2][0] = 0; dp[n / 2][1] = 0;

	for (int i = n - 1; i >= 0; i--) {

		for (int j = 0; j <= n / 2; j++) {

			dp[j][0] = min(dp[j][0], dp[j][1] + a[i]);

			dp[j][1] = min(dp[j + 1][1], dp[j + 1][0] + a[i]);

		}

	}

	cout << min(dp[0][0], dp[0][1]) << endl;

	return 0;

}