#include <cmath>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <algorithm>

using namespace std;

#define N 505

#define ll long long

#define inf 0x3f3f3f3f

void Read(int &p)

{

	p = 0;

	char c = getchar();

	for (; c < '0' || c > '9'; c = getchar());

	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';

}

int dp[N][N], n, mod, ans;

void Upd(int &x, int y){x = x + y >= mod ? x + y - mod : x + y;}

struct Node

{

	int d, l, r;

}A[N];

bool cmp(Node A, Node B)

{

	int a1 = A.d < n ? A.l - 1 : A.r;

	int a2 = A.d < n ? A.r : A.l - 1;

	int b1 = B.d < n ? B.l - 1: B.r;

	int b2 = B.d < n ? B.r : B.l - 1;

	return a1 != b1 ? a1 < b1 : a2 != b2 ? a2 < b2 : A.d > B.d;

}

int Solve(int k)

{

	memset(dp, 0, sizeof(dp));

	int sum = 0;

	dp[0][0] = 1;

	for (int i = 1; i <= 2 * n; i++)

	{

		for (int j = 0; j <= k; j++)

		{

			if (A[i].d >= n)

			{

				int c = A[i].r + 1 - (i - 1 - (sum - j));

				if (c > 0)

					Upd(dp[i][j], 1ll * dp[i - 1][j] * c % mod);

			}

			else

			{

				int c = A[i].r + 1 - (2 * n - A[i].d - 1 + k - j);

				if (c > 0)

					Upd(dp[i][j], 1ll * dp[i - 1][j] * c % mod);

				if (j)

				{

					c = A[i].l - (i - 1 - (sum - j + 1));

					if (c > 0)

						Upd(dp[i][j], 1ll * dp[i - 1][j - 1] * c % mod);

				}

			}

		}

		sum += A[i].d < n;

	}

	return dp[n << 1][k];

}

int main()

{

	Read(n), Read(mod);

	for (int i = 0; i < 2 * n; i++)

	{

		A[i + 1].d = i;

		if (i < n)

			A[i + 1].l = ceil(sqrt(n * n - i * i));

		A[i + 1].r = floor(sqrt(4 * n * n - i * i));

		A[i + 1].r = min(A[i + 1].r, 2 * n - 1);

	}

	sort(A + 1, A + 2 * n + 1, cmp);

	for (int i = 0; i <= n; i++)

	{

		if (i & 1)

			Upd(ans, mod - Solve(i));

		else

			Upd(ans, Solve(i));

	}

	printf("%d\n", ans);

}
