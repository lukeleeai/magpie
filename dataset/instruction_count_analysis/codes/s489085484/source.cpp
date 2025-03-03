#include <cstdio>

#include <vector>

const long long MOD = 1000000007;

int N, M, sg[16], c0[15], c1[15], e[16][16];

std::vector < int > V[16];

long long O = 0;

long long DFS(int k)

{

	if (k <= 2)

	{

		static long long H[15];

		static int T[15];

		H[0] = 1;

		for (int i = 1; H[i - 1] && i <= N - 1; i++)

			H[i] = H[i - 1] * ((1 << c0[i - 1]) - 1) * ((1 << c1[i - 1]) - 1) % MOD;

		T[N - 1] = 0;

		for (int i = N - 2; ~i; i--)

			T[i] = T[i + 1] + c0[i + 1] + c1[i + 1];

		long long O = 0;

		for (int i = 0; i <= N - 1 && H[i]; i++)

			O = (O + (H[i] << T[i])) % MOD;

		return O;

	}

	static int cnt[16];

	for (int i = 0; i <= N; i++)

		cnt[i] = 0;

	for (int i : V[k])

		cnt[sg[i]]++;

	static long long H[16], T[16];

	H[0] = 1;

	for (int i = 1; i <= N; i++)

		H[i] = H[i - 1] * ((1 << cnt[i - 1]) - 1) % MOD;

	T[N] = 1;

	for (int i = N - 1; ~i; i--)

		T[i] = (T[i + 1] << cnt[i + 1]) % MOD;

	long long U[16], O = 0;

	for (int i = 0; i <= N; i++)

		U[i] = H[i] * T[i] % MOD;

	for (int i = 0; i <= N; i++)

		if (U[i])

		{

			if (e[1][k])

				c0[i]++;

			if (e[2][k])

				c1[i]++;

			sg[k] = i;

			O = (O + U[i] * DFS(k - 1)) % MOD;

			if (e[1][k])

				c0[i]--;

			if (e[2][k])

				c1[i]--;

		}

	return O;

}

int main()

{

	scanf("%d%d", &N, &M);

	long long BASE = 1;

	for (int i = 1, u, v; i <= M; i++)

	{

		scanf("%d%d", &u, &v);

		BASE = BASE * 2 % MOD;

		if (u != 1 || v != 2)

		{

			V[u].push_back(v);

			e[u][v] = 1;

		}

	}

	printf("%lld\n", (BASE - DFS(N) + MOD) % MOD);

}
