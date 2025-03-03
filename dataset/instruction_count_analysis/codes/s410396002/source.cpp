#include <cstdio>

const int MOD = 1000000007;

int N, M, e[15][15], emask[15][32768];

long long f[8192];

long long A(int u, int v)

{

	long long W = 1;

	int zero = u - v, nonzero = v | 3 << N - 2;

	for (int i = 0; i < N; i++)

	{

		if (zero >> i & 1)

			W = (W << emask[i][nonzero]) % MOD;

		if (nonzero >> i & 1)

			W = W * ((1 << emask[i][zero]) - 1) % MOD;

	}

	return W;

}

long long B(int u, int v)

{

	long long W = 1;

	int zero = u - v | 3 << N - 2, nonzero = v;

	for (int i = 0; i < N; i++)

	{

		if (zero >> i & 1)

			W = (W << emask[i][nonzero]) % MOD;

		if (nonzero >> i & 1)

			W = (W << emask[i][nonzero]) % MOD * ((1 << emask[i][zero]) - 1) % MOD;

	}

	return W;

}

int main()

{

	scanf("%d%d", &N, &M);

	long long BA = 1;

	for (int i = 1, u, v; i <= M; i++)

	{

		scanf("%d%d", &u, &v);

		e[N - u][N - v] = 1;

		BA = (BA << 1) % MOD;

	}

	for (int i = 0; i < N; i++)

		for (int j = 0; j < 1 << N; j++)

			for (int k = 0; k < N; k++)

				if ((j >> k & 1) && e[i][k])

					emask[i][j]++;

	for (int i = 0; i < 1 << N - 2; i++)

	{

		f[i] = B(i, i);

		for (int j = 0; j < i; j = ((j | ~i) + 1) & i)

			f[i] = (f[i] + f[j] * A(i, j) + B(i, j)) % MOD;

	}

	printf("%lld\n", (BA - f[(1 << N - 2) - 1] + MOD) % MOD);

	return 0;

}
