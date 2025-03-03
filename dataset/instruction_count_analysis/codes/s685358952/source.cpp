#include <iostream>

#include <cstdio>

using namespace std;

#define N 500005

#define mod 998244353

#define ll long long

ll Pow(ll a, ll b)

{

	ll ans = 1;

	while (b)

	{

		if (b & 1)

			ans = ans * a % mod;

		a = a * a % mod;

		b >>= 1;

	}

	return ans;

}

int n, m, ans;

int fac[N], inv[N];

void Init(int n)

{

	fac[0] = 1;

	for (int i = 1; i <= n; i++)

		fac[i] = 1ll * fac[i - 1] * i % mod;

	inv[n] = Pow(fac[n], mod - 2);

	for (int i = n - 1; i >= 0; i--)

		inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;

}

int C(int n, int m)

{

	if (n < 0 || m < 0 || m > n)

		return 0;

	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;

}

int main()

{

	scanf("%d%d", &n, &m);

	if (n < m) swap(n, m);

	Init(n);

	for (int k = 0; k <= m; ++k)

	{

		ans += 1ll * Pow(-1, k) * C(n, k) % mod * C(m, k) % mod * fac[k] % mod * Pow(m + 1, n - k) % mod * Pow(n + 1, m - k) % mod;

		ans = (ans % mod + mod) % mod;

	}

	printf("%d\n", ans);

}
