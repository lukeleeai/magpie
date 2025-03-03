#include "stdc++.h"

#define ll long long

using namespace std;

const int N = 3e5 + 5, mod = 998244353;

int fac[N];

int fp(int a, int p) {

	if (!p) return 1;

	int t = fp(a, p >> 1);

	t = (t * 1ll * t) % mod;

	if (p & 1) t = (t * 1ll * a) % mod;

	return t;

}

ll ncr(int n, int r) {

	return ((fac[n] * 1ll * fp(fac[r], mod - 2)) % mod * 1ll * fp(fac[n - r], mod - 2)) % mod;

}

int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	fac[0] = 1;

	for (int i = 1; i < N; i++)

		fac[i] = (fac[i - 1] * 1ll * i) % mod;

	int n, a, b;

	ll k;

	int ans = 0;

	cin >> n >> a >> b >> k;

	for (int i = 0; i <= n; i++) {

		ll x = i * 1ll * a;

		if (x > k || (k - x) % b) continue;

		ll y = (k - x) / b;

		if (y > n) continue;

		ans = (ans + (ncr(n, i) * 1ll * ncr(n, y)) % mod) % mod;

	}

	cout << ans << endl;

	return 0;

}


