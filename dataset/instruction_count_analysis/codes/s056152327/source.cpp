#include <stdio.h>

#include <algorithm>

long long p = 1000000000;

long long l, r, m, t, k;

long long n, x, y, z, w;

long long a[200000];

int main() {

	l = p * p * (-1);

	r = p * p + 1;

	scanf("%lld%lld", &n, &k);

	for (int i = 0; i < n; i++) {

		scanf("%lld", a + i);

		if (a[i] < 0)x++;

		if (a[i] == 0)y++;

		if (a[i] > 0)z++;

	}

	std::sort(a, a + n);

	while (r - l > 1) {

		m = (r + l) / 2;

		t = 0;

		if (m == 0) {

			t = x * z;

		}

		if (m > 0) {

			t = x * z + (x + z) * y + y * (y - 1) / 2;

			w = n - 1;

			for (long long i = x + y; i < n; i++) {

				while (a[w] * a[i] >= m)w--;

				if (w > i)t += w - i;

				else break;

			}

			w = 0;

			for (long long i = x - 1; i >= 0; i--) {

				while (a[w] * a[i] >= m)w++;

				if (w < i)t += i - w;

				else break;

			}

		}

		if (m < 0) {

			w = x - 1;

			for (long long i = n - 1; i >= x + y; i--) {

				while (w >= 0 && a[w] * a[i] >= m)w--;

				if (w >= 0)t += w + 1;

			}

		}

		if (t < k)l = m;

		else r = m;

	}

	printf("%lld\n", l);

}
