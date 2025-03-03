#include<cstdio>

#include<algorithm>

using namespace std;

int n, m;

char p[101000], q[101000];

int gcd(int a, int b) {

	return b ? gcd(b, a%b) : a;

}

int main() {

	int i;

	scanf("%d%d", &n, &m);

	scanf("%s%s", p, q);

	int g = gcd(n, m);

	for (i = 0; i < n; i++) {

		if (i % (n / g) == 0) {

			if (p[i] != q[i / (n / g) * (m / g)]) {

				puts("-1");

				return 0;

			}

		}

	}

	printf("%lld\n", 1ll * n*m / g);

}
