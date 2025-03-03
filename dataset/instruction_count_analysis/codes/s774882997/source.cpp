#include <cstdio>

int n, a[100010];

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);

	int ans = 1, pre = a[1], how = 0;

	for (int i = 2; i <= n; ++ i) {

		if (a[i] == pre) {

			continue ;

		}

		if (a[i] < pre) {

			if (how == 1) {

				++ ans;

				pre = a[i];

				how = 0;

			} else {

				how = -1;

				pre = a[i];

			}

		}

		if (a[i] > pre) {

			if (how == -1) {

				++ ans;

				pre = a[i];

				how = 0;

			} else {

				how = 1;

				pre = a[i];

			}

		}

	}

	printf("%d\n", ans);

	return 0;

}