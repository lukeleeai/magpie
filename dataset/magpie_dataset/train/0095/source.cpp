#include <iostream>

#include <algorithm>

using namespace std;

int D, N, a[111], e[111], r[111], dp[111][111];

int main() {

	while (cin >> D >> N, D | N) {

		for (int i = 0; i < N; i++) cin >> a[i] >> e[i] >> r[i];

		int maxr = *max_element(r, r + N);

		for (int i = 0; i <= D; i++) fill(dp[i], dp[i] + maxr + 1, 999999999);

		dp[0][0] = 0;

		for (int i = 0; i < D; i++) {

			for (int j = 0; j <= maxr; j++) {

				for (int k = 0; k < N; k++) {

					if (j < r[k]) continue;

					int p = min(j + e[k], maxr), q = min(i + a[k], D);

					dp[q][p] = min(dp[q][p], dp[i][j] + 1);

				}

			}

		}

		int ret = *min_element(dp[D], dp[D] + maxr + 1);

		if (ret == 999999999) cout << "NA" << endl;

		else cout << ret << endl;

	}

}