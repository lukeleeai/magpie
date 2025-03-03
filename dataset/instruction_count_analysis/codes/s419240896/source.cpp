#include <stdio.h>



constexpr int kN = int(1E3 + 10);



long long int gcd(long long int a, long long int b) {return b == 0 ? a : gcd(b, a % b);}



long long int a[kN], b[kN];



int main() {

	int n;

	long long int l = 1, r = 1, tmp, nl, nr, nnl, nnr;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%lld%lld", &a[i], &b[i]);

	for (int i = 1; i <= n; i++) {

		tmp = gcd(l, r);

		if (l / tmp == a[i] && r / tmp == b[i]) continue;

			nl = ((l - 1) / a[i] + 1) * a[i];

			nr = nl / a[i] * b[i];

			nnr = ((r - 1) / b[i] + 1) * b[i];

			nnl = nnr / b[i] * a[i];

			if (nl >= l && nr >= r) {

				if (nnl >= l && nnr >= r) {

					if (nl < nnl) {

						l = nl;

						r = nr;

					}

					else {

						l = nnl;

						r = nnr;

					}

				}

				else {

					l = nl;

					r = nr;

				}

			}

			else {

				l = nnl;

				r = nnr;

			}

	}

	printf("%lld\n", l + r);

}
