#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#define ll long long

using namespace std;

inline int read()

{

	int x = 0, f = 1; char ch = getchar();

	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}

	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}

	return x * f;

}

const int N = 5e5 + 1000,mod = 998244353;

int n,m,mx,mn;

ll ans,jc[N],jcinv[N],inv[N];

ll ksm(ll x,int y){ll res = 1; for(;y;y >>= 1,x = x * x % mod) if(y & 1) res = res * x % mod; return res;}

ll C(int x,int y){if(y < 0 || y > x) return 0; return jc[x] * jcinv[y] % mod * jcinv[x - y] % mod;}

int main()

{

	n = read(); m = read(); mx = max(m,n); mn = min(m,n);

	jc[0] = jc[1] = inv[0] = inv[1] = jcinv[0] = jcinv[1] = 1;

	for(int i = 2;i <= mx;i ++)

	{

		jc[i] = jc[i - 1] * i % mod;

		inv[i] = (mod - mod / i) * inv[mod % i] % mod;

		jcinv[i] = jcinv[i - 1] * inv[i] % mod;

	}

	for(int i = 0;i <= mn;i ++)

	{

		if(i & 1) ans = (ans + mod - C(n,i) * C(m,i) % mod * ksm(m + 1,n - i) % mod * ksm(n + 1,m - i) % mod * jc[i] % mod) % mod;

		else ans = (ans + C(n,i) * C(m,i) % mod * ksm(m + 1,n - i) % mod * ksm(n + 1,m - i) % mod * jc[i] % mod) % mod;

	}

	cout << ans << "\n";

	return 0;

}
