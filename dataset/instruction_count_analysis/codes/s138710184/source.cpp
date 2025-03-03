#include <stdio.h>

#define mod 1000000007

typedef long long ll;

 

ll rev(ll a) {

  ll b = mod - 2, ans = 1;

  while(b) {

    if(b & 1) ans *= a, ans %= mod;

    b >>= 1, a *= a, a %= mod;

  }

  return ans;

}

 

int main(void) {

  ll i, j, k, r[2], c[2], ans = 0, now;

  scanf("%lld%lld%lld%lld", &r[0], &c[0], &r[1], &c[1]);

  r[0]--, c[0]--;

  ll n = r[1] + c[1], fact[n + 10];

  fact[0] = 1;

  for(i = 1; i <= n + 9; ++i) fact[i] = fact[i - 1] * i, fact[i] %= mod;

  for(i = 0; i < 2; ++i) for(j = 0; j < 2; ++j) {

    now = fact[c[i] + r[j] + 2] * rev(fact[c[i] + 1]);

    now %= mod;

    now *= rev(fact[r[j] + 1]);

    now %= mod;

    ans += now * ((i ^ j) ? -1 : 1) + mod;

    ans %= mod;

  }

  printf("%lld", ans);

  return 0;

}