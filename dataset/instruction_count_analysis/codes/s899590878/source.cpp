#include "stdc++.h"

using namespace std;

int n, A, a[51];

long long f[2][51][2510];

int main() {

	cin >> n >> A;

	for (int i = 1; i <= n; ++ i) cin >> a[i];

	f[0][0][0] = 1;

	for (int i = 1; i <= n; ++ i) {

		memset(f[i & 1], 0, sizeof(f[i & 1]));

		for (int j = 0; j <= i; ++ j) {

			for (int k = 0; k <= 2500; ++ k) {

				f[i & 1][j][k] = ((k - a[i] >= 0 && j > 0) ? f[i & 1 ^ 1][j - 1][k - a[i]] : 0) + f[(i & 1) ^ 1][j][k];

			}

		}

	}

	long long ans = 0;

	for (int i = 1; i <= n; ++ i) {

		ans += f[n & 1][i][i * A];

	}

	cout << ans << endl;

	return 0;

}