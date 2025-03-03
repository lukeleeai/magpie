#include <cmath>

#include <cstdio>

#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int n, m, c[155], p[155][15], v[155][15], dp[155][15][79];

int main() {

	while (scanf("%d%d", &n, &m), n) {

		for (int i = 0; i < n; i++) {

			scanf("%d", &c[i]);

			for (int j = 0; j < c[i]; j++) scanf("%d%d", &p[i][j], &v[i][j]);

		}

		for (int i = 1; i < n; i++) {

			for (int j = 0; j < c[i]; j++) {

				for (int k = 0; k <= m; k++) {

					dp[i][j][k] = 999999999;

					for (int l = 0; l < c[i - 1]; l++) {

						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][l][k] + abs(p[i][j] - p[i - 1][l]) * (v[i][j] + v[i - 1][l]));

					}

					if (k == 0) continue;

					if (i == 1) {

						dp[i][j][k] = 0;

						continue;

					}

					for (int l = 0; l < c[i - 2]; l++) {

						dp[i][j][k] = min(dp[i][j][k], dp[i - 2][l][k - 1] + abs(p[i][j] - p[i - 2][l]) * (v[i][j] + v[i - 2][l]));

					}

				}

			}

		}

		int ret = 999999999;

		for (int i = 0; i < c[n - 1]; i++) ret = min(ret, dp[n - 1][i][m]);

		if (m >= 1) for (int i = 0; i < c[n - 2]; i++) ret = min(ret, dp[n - 2][i][m - 1]);

		printf("%d\n", ret);

	}

	return 0;

}