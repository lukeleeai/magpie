#include "stdc++.h"

using namespace std;



#define chmin(x, y) (x = min(x, y))



int n;

int a[10000];

int dp[2][5010][2];



int main()

{

	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++){

		scanf("%d", a + i);

	}



	for (int i = 1; i <= n / 2; i++){

		dp[0][i][0] = dp[0][i][1] = 1e9;

	}

	for (int i = 0; i < n; i++){

		auto &src = dp[i & 1], &dst = dp[~i & 1];

		for (int j = 0; j <= n / 2; j++){

			dst[j][0] = dst[j][1] = 1e9;

		}

		for (int j = 0; j <= n / 2; j++){

			chmin(dst[j + 1][0], src[j][0]);

			chmin(dst[j + 1][1], src[j][0] + a[i]);

			chmin(dst[j][1], src[j][1]);

			chmin(dst[j][0], src[j][1] + a[i]);

		}

	}



	int res = min(dp[n & 1][n / 2][0], dp[n & 1][n / 2][1]);

	printf("%d\n", res);

}