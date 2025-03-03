// Shuffle and Swap

// * frank_c1

// * 2017 / 12 / 27



#include "stdc++.h"

using namespace std;

typedef long long LL;



LL pow_mod(LL b, LL p, LL k) {

	LL ret = 1;

	for (; p; p >>= 1) {

		if (p & 1) ret = ret * b % k;

		b = b * b % k;

	} return ret;

}



const int maxn = 10005;

const int mo = 998244353;

char a[maxn], b[maxn];

LL fac[maxn], ivf[maxn];

LL f[2][maxn];



inline LL C(int n, int m) {

	return fac[n] * ivf[m] % mo * ivf[n - m] % mo;

}



int main() {

	scanf("%s%s", a + 1, b + 1);

	int n = strlen(a + 1), p = 0, q = 0; 

	for (int i = 1; i <= n; ++i) {

		p += (a[i] == '1' && a[i] == b[i]); q += (a[i] != b[i]);

	} q >>= 1;

	fac[0] = ivf[0] = 1;

	for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mo;

	ivf[n] = pow_mod(fac[n], mo - 2, mo);

	for (int i = n - 1; i >= 1; --i) ivf[i] = ivf[i + 1] * (i + 1) % mo;

	int now = 0, lst = 0; LL ret = 0;

	for (int i = 0; i <= p; ++i) {

		now = lst ^ 1;

		memset(f[now], 0, sizeof(f[now]));

		if (!i) f[now][0] = 1;

		for (int j = 0; j <= q; ++j) {

			if (i) f[now][j] += f[lst][j] * i * j;

			if (j) f[now][j] += f[now][j - 1] * j * j;

			f[now][j] %= mo;

		}

		(ret += f[now][q] * C(p, i) % mo * C(p + q, i + q) % mo * fac[p - i] % mo * fac[p - i]) %= mo;

		lst = now;

	}

	return printf("%lld\n", ret), 0;

}