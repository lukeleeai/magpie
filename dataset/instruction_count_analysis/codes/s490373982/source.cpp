#include <cstdio>

#include <algorithm>

using namespace std;

void reader(int *x) {

	int k = getchar_unlocked(); *x = k - '0';

	while (1) {

		k = getchar_unlocked();

		if (k < '0' || k > '9') break;

		*x = ((*x) << 1) + ((*x) << 3) + k - '0';

	}

}

int d, n, q, a[200009], x;

int main() {

	while (reader(&d), d) {

		reader(&n); reader(&q);

		for (int i = 1; i < n; i++) reader(&a[i]);

		sort(a, a + n);

		for (int i = 0; i < n; i++) a[i + n] = a[i] + d; a[n * 2] = a[0] + d * 2;

		long long ret = 0;

		while (q--) {

			reader(&x);

			int ptr = lower_bound(a, a + n * 2, x) - a;

			ret += min(a[ptr] - x, x - a[ptr + n - 1] + d);

		}

		printf("%lld\n", ret);

	}

	return 0;

}