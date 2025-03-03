#include <stdio.h>

#include <math.h>

#include <algorithm>

using namespace std;

const int N = 100005;

int a[N];

double b[N];

int main()

{

	int n, maxa = -1;

	int ans;

	scanf("%d",&n);

	for (int i = 1; i <= n; i++)

		scanf("%d", &a[i]);

	sort(a + 1, a + 1 + n);

	double mid = 1.0 * a[n] / 2, minb = 1000000009.0;

	for (int i = 1; i < n; i++) 

	{

		if (fabs(mid - (1.0 * a[n] - 1.0 * a[i])) < minb)

		{

			ans = a[i];

			minb = fabs(mid - (1.0 * a[n] - 1.0 * a[i]));

		}

	}

	printf("%d %d\n", a[n], ans);

}
