#include "stdc++.h"

using namespace std;



namespace TYC

{

	typedef long long ll;

	const int N = 8005, M = 205, MAXN = 1 << 15 | 5, mod = 998244353, INV2 = (mod + 1) >> 1;



	int F[M][N], Fac[N], Inv[N], A[MAXN], B[MAXN], w[MAXN], rev[MAXN];



	inline int qpow(int x, int tim)

	{

		int ans = 1;

		for (; tim; tim >>= 1, x = (ll)x * x % mod)

			if (tim & 1)

				ans = (ll)ans * x % mod;

		return ans;

	}



	void init(const int n)

	{

		for (int i = 0; i < n; i++)

			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));

		w[0] = 1, w[1] = qpow(3, (mod - 1) / n);

		for (int i = 2; i < n; i++)

			w[i] = (ll)w[i - 1] * w[1] % mod;

	}



	void NTT(int *a, const int n, const int type)

	{

		for (int i = 0; i < n; i++)

			if (i < rev[i])

				swap(a[i], a[rev[i]]);

		if (type)

			reverse(w + 1, w + n);

		for (int len = 1; len < n; len <<= 1)

			for (int i = 0; i < n; i += len << 1)

				for (int k = 0; k < len; k++)

				{

					int x = a[i + k], y = (ll)w[n / (len << 1) * k] * a[i + len + k] % mod;

					a[i + k] = (x + y) % mod;

					a[i + len + k] = (x - y + mod) % mod;

				}

		if (type)

		{

			reverse(w + 1, w + n);

			for (int i = 0, t = qpow(n, mod - 2); i < n; i++)

				a[i] = (ll)a[i] * t % mod;

		}

	}



	inline int C(const int x, const int y)

	{ return x < y ? 0 : (ll)Fac[x] * Inv[x - y] % mod * Inv[y] % mod; }



	void work()

	{

		int n, m;

		scanf("%d%d", &n, &m);

		int t = max(n++, m) + 2;

		Fac[0] = 1;

		for (int i = 1; i <= t; i++)

			Fac[i] = (ll)Fac[i - 1] * i % mod;

		Inv[t] = qpow(Fac[t], mod - 2);

		for (int i = t; i; i--)

			Inv[i - 1] = (ll)Inv[i] * i % mod;



		int len;

		for (len = 1; len < (n << 1); len <<= 1);

		init(len);

		F[0][0] = 1;

		for (int j = 1; j <= m; j++)

		{

			for (int i = 0; i < n; i++)

			{

				A[i] = (ll)F[j - 1][i] * Inv[i] % mod;	

				B[i] = Inv[i + 2];

			}

			B[0] = 0;

			memset(A + n, 0, sizeof(int[len - n]));

			memset(B + n, 0, sizeof(int[len - n]));

			NTT(A, len, 0);

			NTT(B, len, 0);

			for (int i = 0; i < len; i++)

				A[i] = (ll)A[i] * B[i] % mod;

			NTT(A, len, 1);

			for (int i = 0; i < n; i++)

				F[j][i] = (((ll)i * (i + 1) / 2 + 1) % mod * F[j - 1][i] % mod + (ll)A[i] * Fac[i + 2] % mod) % mod;

		}

		int ans = 0;

		for (int i = 0; i < n; i++)

			ans = (ans + (ll)F[m][i] * C(n - 1, i)) % mod;

		printf("%d\n", ans);

	}

}



int main()

{

	TYC::work();

	return 0;

}