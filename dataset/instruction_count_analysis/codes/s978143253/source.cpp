#include <cstdio>

#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int n, m, c[1009], s[1000009];

int main() {

	while (scanf("%d%d", &n, &m), n) {

		for (int i = 1; i <= n; i++) scanf("%d", &c[i]);

		sort(c, c + n);

		int b = 0;

		for (int i = 0; i <= n; i++) {

			for (int j = i; j <= n && c[i] + c[j] <= m; j++) {

				s[b++] = c[i] + c[j];

			}

		}

		sort(s, s + b);

		int r = b - 1, ret = 0;

		for (int i = 0; i < b && i <= r; i++) {

			while (r > 0 && s[i] + s[r] > m) r--;

			ret = max(ret, s[i] + s[r]);

		}

		printf("%d\n", ret);

	}

	return 0;

}