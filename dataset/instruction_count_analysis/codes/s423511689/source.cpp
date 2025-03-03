#include <cstdio>

#include <algorithm>

using namespace std;

int n, a[10009], dp[5009][2];

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) scanf("%d", &a[i]);

	for (int i = 0; i <= n >> 1; i++) dp[i][0] = dp[i][1] = 999999999;

	dp[0][0] = dp[1][1] = 0;

	for (int i = 0; i < n - 1; i++) {

		for (int j = n >> 1; j >= 0; j--) {

			dp[j][0] = min(dp[j][0], dp[j][1] + a[i]);

			dp[j][1] = (j ? min(dp[j - 1][1], dp[j - 1][0] + a[i]) : 999999999);

		}

	}

	printf("%d\n", dp[n >> 1][0]);

	return 0;

}