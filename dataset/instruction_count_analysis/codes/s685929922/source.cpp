#include<cstdio>

#include<algorithm>

using namespace std;

int D[5010][5010], n, Mod, C[5010];

void Make(int t) {

	int i, j;

	for (i = 0; i <= n / (t+1); i++) {

		for (j = t * i; j <= n-t; j++) {

			D[i + 1][j + t] = (D[i + 1][j + t] + D[i][j]) % Mod;

		}

	}

}

int main() {

	int i, j;

	scanf("%d%d", &n, &Mod);

	D[0][0] = 1;

	for (i = 2; i <= n; i++) {

		C[min(i - 2, n + 1 - i)]++;

	}

	for (i = n / 2; i >= 0; i--) {

		for (j = 0; j < C[i]; j++) {

			Make(i);

		}

	}

	int res = 0;

	for (i = 0; i < n; i++) {

		for (j = 0; j <= n; j++) {

			res = (res + (long long)max(n - i - j, 0) * D[i][j]) % Mod;

		}

	}

	printf("%d\n", res);

}