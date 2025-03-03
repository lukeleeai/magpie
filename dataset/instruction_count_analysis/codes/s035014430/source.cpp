#include "stdc++.h"

using namespace std;



#define mp make_pair

#define pb push_back



typedef long long ll;

typedef pair<int, int> ii;

typedef pair<ll, ll> l4;





const int maxn = 2e5+1, mod = 1e9+7;

ll f[maxn], inv[maxn];

ll power(ll base, ll p)

{

  ll ret = 1;

  while (p)

    {

      if (p&1)

	ret = ret * base % mod;

      base = base * base % mod;

      p >>= 1;

    }

  return ret;

}

ll h, w, a, b;

ll cb(ll n, ll k)

{

  return f[n] * inv[k] % mod * inv[n-k] % mod;

}

inline void add(ll &a, ll b)

{

  a = a + b;

  if (a > mod)

    a %= mod;

}

int main()

{

  f[0] = 1;

  for (ll i = 1; i < maxn; ++i)

    f[i] = f[i-1] * i % mod;

  inv[maxn-1] = power(f[maxn-1], mod-2);

  for (ll i = maxn-1; i >= 1; --i)

    inv[i-1] = inv[i] * i % mod;

  scanf("%lld %lld %lld %lld", &h, &w, &a, &b);

  ll ret = 0;

  for (ll i = b+1; i <= w; ++i)

    add(ret, cb(h-a+i-2, h-a-1)*cb(a+w+1-i-2, a-1)%mod);

  printf("%lld\n", ret);

}
