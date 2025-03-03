#include "stdc++.h"

using namespace std;

const int maxx = 2e5 + 7;

const int Mod = 1e9 + 7;

typedef long long ll;

ll n;

int a, b;

ll fac[maxx], inv[maxx];



ll qwe(ll x, int y) {

	ll res = 1ll;

	while(y) {

		if(y & 1) res = res * x % Mod; 

		x = x * x % Mod;

		y >>= 1; 

	}

	return res;

}



ll Com(ll n, ll m) {

	ll res = 1ll;

	for(ll i = n; i >= n - m + 1; i--) res = res * i % Mod;

	return res * inv[m] % Mod;

}



int main() {

	fac[0] = inv[0] = 1; 

	for(int i = 1; i <= maxx; i++) fac[i] = fac[i - 1] * i % Mod;

	inv[maxx] = qwe(fac[maxx], Mod - 2);

	for(int i = maxx - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % Mod;

	scanf("%lld %d %d", &n, &a, &b);

	ll ans = qwe(2, n) - 1;

	ans = (ans - Com(n, a) + Mod) % Mod;

	ans = (ans - Com(n, b) + Mod) % Mod;

	printf("%lld\n", ans);

	return 0;

}