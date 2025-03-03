#include <iostream>

#include <iomanip>

#include <cstring>

#include <cmath>

#include <cstdio>

#include <queue>

#include <algorithm>

using namespace std;

int read() {

	char c = getchar();

	int res = 0;

	while (c < '0' || c > '9') c = getchar();

	while (c >= '0' && c <= '9') res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();

	return res;

}

int n, p, K, f[155][155], g[305][155][155];

void Solve1()

{

	K /= 2;

	f[0][0] = 1;

	for (int i = 1; i <= (n + 1) / 2; i++)

	{

		for (int j = 0; j <= K; j++)

			f[i][0] = (f[i][0] + f[i - 1][j]) % p;

		for (int j = 0; j < K; j++)

			f[i][j + 1] = (f[i][j + 1] + f[i - 1][j]) % p;

	}

	int ans1 = 0, ans2 = 0;

	for (int i = 0; i <= K; i++)

		ans1 = (ans1 + f[n / 2][i]) % p;

	for (int i = 0; i <= K; i++)

		ans2 = (ans2 + f[(n + 1) / 2][i]) % p;

	printf("%lld\n", 1ll * ans1 * ans2 % p);

}

void Solve2()

{

	int last = 0;

	g[0][0][0] = 1;

	for (int i = 2; i - K <= n; i += 2)

	{

		for (int j = 0; j <= n; j++)

			for (int k = 0; k <= K + 1; k++)

				g[i][0][0] = (g[i][0][0] + g[i - 2][j][k]) % p;

		if (i <= n)

		{

			for (int j = 0; j <= n; j++)

				for (int k = 0; k <= K + 1; k++)

					g[i][j + 1][0] = (g[i][j + 1][0] + g[i - 2][j][k]) % p;

		}

		if (i - K >= 1)

		{

			for (int j = 0; j <= n; j++)

			{

				for (int k = 1; k <= K; k++)

					g[i][0][k + 1] = (g[i][0][k + 1] + g[i - 2][j][k]) % p;

				g[i][0][0] = (g[i][0][0] + g[i - 2][j][0]) % p;

			}

		}

		if (i <= n && i - K >= 1)

		{

			for (int j = 0; j <= n; j++)

				for (int k = 0; max(k, j + 1) <= K; k++)

					g[i][j + 1][max(k + 1, j + 2)] = (g[i][j + 1][max(k + 1, j + 2)] + g[i - 2][j][k]) % p;

		}

		last = i;

	}

	int ans = 0;

	for (int j = 0; j <= n; j++)

		for (int k = 0; k <= K + 1; k++) ans = (ans + g[last][j][k]) % p;

	printf("%d\n", ans);

}

int main()

{

	n = read(), K = read(), p = read();

	if (!(K & 1))

		Solve1();

	else

		Solve2();

}
