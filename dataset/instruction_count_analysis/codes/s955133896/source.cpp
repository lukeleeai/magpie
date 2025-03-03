#include <cstdio>

const long long MOD = 998244353;

const int MAXN = 300010;

long long fac[MAXN], ifac[MAXN];

long long exGCD(long long a, long long b, long long& x, long long& y) {

	if (b == 0) {

		x = 1;

		y = 0;

		return a;

	}

	long long g = exGCD(b, a % b, x, y);

	long long temp = x;

	x = y;

	y = temp - a / b * y;

	return g;

}

int inverse(long long a) {

	long long x, y;

	exGCD(a, MOD, x, y);

	return (x % MOD + MOD) % MOD;

}

long long C(long long n, long long m) {

	return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;

}

int main() {

	long long n, a, b, k;

	scanf("%lld%lld%lld%lld", &n, &a, &b, &k);

	fac[0] = 1;

	for (int i = 1; i <= n; ++i) {

		fac[i] = fac[i - 1] * i % MOD;

	}

	ifac[n] = inverse(fac[n]);

	for (int i = n; i >= 1; --i) {

		ifac[i - 1] = ifac[i] * i % MOD;

	}

	long long ans = 0;

	for (int i = 0; i <= n && i * a <= k; ++i) {

		if ((k - i * a) % b == 0 && (k - i * a) / b <= n) {

			ans = (ans + C(n, i) * C(n, (k - i * a) / b) % MOD) % MOD;

		}

	}

	printf("%lld\n", ans);

	return 0;

}