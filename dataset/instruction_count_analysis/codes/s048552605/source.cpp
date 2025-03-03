#include <stdio.h>

using namespace std;

const int MAXN = 2e5 + 1;

int n, m, i, j, k, z;

long a[MAXN], b[MAXN];

signed main()

{

    scanf("%d %d %d", &n, &m, &k);

	for (i = 1; i <= n; ++i)

		scanf("%d", &a[i]), a[i] += a[i - 1];

	for (i = 1; i <= m; ++i)

		scanf("%d", &b[i]), b[i] += b[i - 1];

	z = 0, i = 0, j = m;

	while (a[i] <= k && i <= n)

	{

		while (b[j] > k - a[i])

			--j;

		if (i + j > z)

			z = i + j;

		++i;

	}

	printf("%d", z);

}