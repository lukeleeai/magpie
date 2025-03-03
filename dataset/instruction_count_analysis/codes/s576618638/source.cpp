#include <cstdio>



int main() {

	int n, m, d;

	scanf("%d%d%d", &n, &m, &d);

	double t;

	if (d == 0) t = n;

	else t = (n - d) << 1;

	t *= m - 1;

	t /= n;

	t /= n;

	printf("%.10lf\n", t);

	return 0;

}