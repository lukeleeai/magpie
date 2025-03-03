#include <cstdio>

#include <algorithm>

#include <vector>

#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)



inline int read()

{

	int data = 0, w = 1; char ch = getchar();

	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();

	if (ch == '-') w = -1, ch = getchar();

	while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();

	return data * w;

}



const int N(305);

int n, K, M, C[N][N], f[N][N], s[N][N];



int main()

{

	n = read(), K = read(), M = read();

	for (int i = 0; i <= n; i++) C[i][0] = 1;

	for (int i = 1; i <= n; i++)

		for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;

	for (int i = K; ~i; i--) f[1][i] = 1, s[1][i] = (f[1][i] + s[1][i + 1]) % M;

	for (int i = 2; i <= n + 1; i++)

	{

		for (int j = K; ~j; j--)

		{

			for (int k = 1; k < i; k++)

				f[i][j] = (f[i][j] + 1ll * f[i - k][j] * C[i - 2][k - 1] % M * s[k][j + 1]) % M;

			s[i][j] = (f[i][j] + s[i][j + 1]) % M;

		}

	}

	printf("%d\n", f[n + 1][0]);

	return 0;

}
