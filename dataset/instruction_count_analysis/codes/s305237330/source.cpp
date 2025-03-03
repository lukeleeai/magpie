#include<iostream>

#include<cstring>

#include<algorithm>

using namespace std;



#define MAX_N 500000

#define INF 2000000000



int dp[2][MAX_N][2];//dp[????????????][???????????§??§A?????????????????????][??´???]

int n, a[MAX_N];



int main() {

	cin >> n;

	for (int i = 1; i < n; i++) { cin >> a[i]; }

	memset(dp, 127, sizeof(dp));

	dp[0][0][0] = 0;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (dp[0][j][0] < INF) {

				dp[1][j + 1][0] = min(dp[1][j + 1][0], dp[0][j][0]);

				dp[1][j + 1][1] = min(dp[1][j + 1][1], dp[0][j][0] + a[i + 1]);

			}

			if (dp[0][j][1] < INF) {

				dp[1][j][1] = min(dp[1][j][1], dp[0][j][1]);

				dp[1][j][0] = min(dp[1][j][0], dp[0][j][1] + a[i + 1]);

			}

		}

		for (int j = 0; j <= n; j++) {

			dp[0][j][0] = dp[1][j][0];

			dp[0][j][1] = dp[1][j][1];

			dp[1][j][0] = INF;

			dp[1][j][1] = INF;

		}

	}

	cout << min(dp[0][n / 2][0], dp[0][n / 2][1]) << endl;

	return 0;

}