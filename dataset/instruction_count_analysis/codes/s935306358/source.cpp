#include <cstdio>

#include <cstring>

#include <iostream>

using namespace std;



const int maxn = 2005;

const int P = 924844033;

int n, k, fact[maxn], dp[2][maxn][2][2];



void update(int &a, int b) {

	a += b;

	(a >= P) && (a -= P);

	(a < 0) && (a += P);

}



int main() {

	scanf("%d %d", &n, &k);

	fact[0] = 1;

	for (int i = 1; i <= 2000; i++) {

		fact[i] = 1ll * fact[i - 1] * i % P;

	}

 	int cur = 0, nxt = 1;

 	dp[0][0][1][0] = 1;

	for (int x = 1; x <= k; x++) {

		for (int j = x; j <= n; j += k) {

			memset(dp[nxt], 0, sizeof(dp[nxt]));

			for (int i = 0; i <= n; i++) {

				for (int v0 = 0; v0 < 2; v0++) {

					for (int v1 = 0; v1 < 2; v1++) {

						if (dp[cur][i][v0][v1]) {

							if (j + k > n) {

								update(dp[nxt][i][1][0], dp[cur][i][v0][v1]);

								if (v0 == 0) {

									update(dp[nxt][i + 1][1][0], dp[cur][i][v0][v1]);

								}

							} else {

								update(dp[nxt][i][v1][0], dp[cur][i][v0][v1]);

								if (v0 == 0) {

									update(dp[nxt][i + 1][v1][0], dp[cur][i][v0][v1]);

								}

								update(dp[nxt][i + 1][v1][1], dp[cur][i][v0][v1]);

							}

						}

					}

				}

			}

			swap(cur, nxt);

		}

	}

	int ans = 0;

	for (int i = 0; i <= n; i++) {

		int temp = 0;

		for (int v0 = 0; v0 < 2; v0++) {

			for (int v1 = 0; v1 < 2; v1++) {

				update(temp, dp[cur][i][v0][v1]);

			}

		}

		temp = 1ll * temp * fact[n - i] % P;

		if (i & 1) {

			update(ans, -temp);

		} else {

			update(ans, temp);

		}

	}

	printf("%d\n", ans);

	return 0;//

}