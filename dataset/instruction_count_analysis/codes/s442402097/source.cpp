#include <cstdio>

#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

const int mod = 1000000009;

int W, N, cnt, pre[79], dp[79], x[33], v[64][79][79]; long long H, y[33];

int main() {

	while (scanf("%d%lld%d", &W, &H, &N), W) {

		for (int i = 1; i <= N; i++) scanf("%d%lld", &x[i], &y[i]), x[i]--;

		y[0] = 1, y[N + 1] = H; x[N + 1] = 0;

		for (int i = 0; i <= N + 1; i++) {

			for (int j = i + 1; j <= N + 1; j++) {

				if (y[i] > y[j]) {

					swap(x[i], x[j]);

					swap(y[i], y[j]);

				}

			}

		}

		for (int i = 0; i < W; i++) {

			for (int j = 0; j < W; j++) {

				if (-1 <= i - j && i - j <= 1) v[0][i][j] = 1;

				else v[0][i][j] = 0;

			}

		}

		for (int i = 0; i < 60; i++) {

			for (int j = 0; j < W; j++) {

				for (int k = 0; k < W; k++) {

					v[i + 1][j][k] = 0;

					for (int l = 0; l < W; l++) {

						v[i + 1][j][k] = (v[i + 1][j][k] + 1LL * v[i][j][l] * v[i][l][k]) % mod;

					}

				}

			}

		}

		fill(pre, pre + W, 0); pre[0] = 1;

		for (int i = 1; i <= N + 1; i++) {

			long long b = y[i] - y[i - 1];

			for (int j = 0; j <= 60; j++) {

				if (b & (1LL << j)) {

					for (int k = 0; k < W; k++) {

						for (int l = 0; l < W; l++) {

							dp[l] = (dp[l] + 1LL * pre[k] * v[j][k][l]) % mod;

						}

					}

					for (int j = 0; j < W; j++) pre[j] = dp[j], dp[j] = 0;

				}

			}

			pre[x[i]] = 0;

		}

		printf("Case %d: ", ++cnt);

		if (W == 1) printf("%d\n", N == 0 ? 1 : 0);

		else printf("%d\n", pre[W - 1]);

	}

	return 0;

}