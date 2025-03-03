#include "stdc++.h"

using namespace std;

int k;

int main()

{

	cin >> k;

	if (k <= 500)

	{

		cout << k << endl;

		for (int i = 1; i <= k; i++, cout << endl)

			for (int j = 1; j <= k; j++)

			{

				printf("%d", i);

				if (j != k)putchar(' ');

			}

	}

	else

	{

		int n = ((k + 3) / 4) * 2;

		cout << n << endl;

		for (int i = 1; i <= n; i++, cout << endl)

			for (int j = 1; j <= n; j++)

			{

				int res = (i + j) % n + (i & 1 ? 0 : n) + 1;

				if (res > k) res -= n;

				printf("%d", res);

				if (j != k)putchar(' ');

			}

	}

	return 0;

}