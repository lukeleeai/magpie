#include <stdio.h>

int n;

int list[200001];

long long int abs(long long int x) { return x < 0 ? -x : x; }

int main() {

	while (scanf("%d", &n) != EOF) {

		long long int sum = 0;

		for (int i = 0; i < n; i++) {

			scanf("%d", &list[i]);

			sum += list[i];

		}

		long long int sumi = 0;

		long long int ans = 1e18;

		for (int i = 0; i < n - 1; i++) {

			sumi += list[i];

			long long int tmp = abs(sum - 2 * sumi);

			if (tmp < ans)  ans = tmp;

		}

		printf("%lld\n", ans);

	}

	return 0;

}
