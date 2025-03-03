#include <cstdio>



signed main() {

	int n, k;

	scanf("%d%d", &n, &k);

	if (k > (n - 2) * (n - 1) / 2) {

		puts("-1\n");

	} else {

		printf("%d\n", n * (n - 1) / 2 - k);

		for (int i = 1; i <= n - 1; ++i) {

			printf("%d %d\n", i, n);

		}

		int c = (n - 2) * (n - 1) / 2 - k;

		for (int i = 1; i <= n - 2; ++i) {

			for (int j = i + 1; j <= n - 1; ++j) {

				if (c > 0) {

					printf("%d %d\n", i, j);

					--c;

				} else {

					return 0;

				}

			}

		}

	}

}
