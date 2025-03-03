#include<cstdio>

#include<algorithm>

using namespace std;

typedef long long ll;

int n;

ll a[10100], b[10100];

ll atot = 0, btot = 0;

int main()

{

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)

	{

		scanf("%lld", &a[i]);

		atot += a[i];

	}

	for (int i = 1; i <= n; i++)

	{

		scanf("%lld", &b[i]);

		btot += b[i];

	}

	if (atot > btot) { printf("No\n"); return 0; }

	int p = 1;

	for (int i = 1; i <= n; i++)

	{

		if (a[i] > b[i])

		{

			while (p <= n && (b[p] - a[p]) / 2 <= 0) p++;

			if (p > n)

			{

				printf("No\n"); return 0;

			}

			ll t = min(a[i] - b[i], (b[p] - a[p]) / 2);

			b[i] += t; a[p] += (2 * t);

			i--;

			continue;

		}

	}

	bool flag = false;

	for (int i = 1; i <= n; i++)

	{

		if (a[i] > b[i]) { flag = true; break; }

	}

	if (flag) printf("No\n");

	else printf("Yes\n");

	return 0;

}
