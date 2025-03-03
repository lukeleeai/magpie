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



const int N(18), maxn(1 << 17), Mod(1e9 + 7);

inline void Add(int &x, int y) { x = (x + y) % Mod; }

int bin[N], fac[maxn], inv[maxn], n, m, ans, f[N][maxn], cnt[maxn], A[N];

inline int C(int n, int m) { return n < m ? 0 : 1ll * fac[n] * inv[m] % Mod * inv[n - m] % Mod; }

int fastpow(int x, int y)

{

	int ans = 1;

	for (; y; y >>= 1, x = 1ll * x * x % Mod)

		if (y & 1) ans = 1ll * ans * x % Mod;

	return ans;

}



int main()

{

	n = read(), m = read(), cnt[0] = bin[0] = fac[0] = inv[0] = 1;

	for (int i = 1; i <= n; i++) bin[i] = bin[i - 1] << 1;

	for (int i = 1; i <= bin[n]; i++) fac[i] = 1ll * fac[i - 1] * i % Mod;

	inv[bin[n]] = fastpow(fac[bin[n]], Mod - 2);

	for (int i = bin[n] - 1; i; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % Mod;

	for (int i = 1; i <= bin[n]; i++) cnt[i] = (i & 1) ? Mod - cnt[i >> 1] : cnt[i >> 1];

	for (int i = 1; i <= m; i++) A[i] = read(); std::sort(A + 1, A + m + 1);

	f[m + 1][0] = 1;

	for (int i = m; i; i--) for (int S = 0; S < bin[n]; S++) if (f[i + 1][S])

	{

		Add(f[i][S], f[i + 1][S]); int t = (bin[n] - 1) ^ S;

		for (int j = 0; j < n; j++) if (!(S & bin[j]))

			Add(f[i][S | bin[j]], 1ll * C(t - A[i] + 1, bin[j] - 1) *

					f[i + 1][S] % Mod * fac[bin[j]] % Mod);

	}

	for (int i = 0; i < bin[n]; i++)

		Add(ans, 1ll * f[1][i] * fac[bin[n] - 1 - i] % Mod * cnt[i] % Mod);

	ans = 1ll * ans * bin[n] % Mod; printf("%d\n", ans);

	return 0;

}

//fdsffffdsfgsg