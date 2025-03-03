#include"stdc++.h"

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)

#define MAX 100001

#define Mod 1000000007

typedef long long ll;

using namespace std;

ll ans, cnt;

ll fac[MAX], finv[MAX], inv[MAX];

void comInit() {

  fac[0] = fac[1] = 1;

  finv[0] = finv[1] = 1;

  inv[1] = 1;

  for (int i = 2; i < MAX; i++) {

    fac[i] = fac[i - 1] * i % Mod;

    inv[i] = Mod - inv[Mod % i] * (Mod / i) % Mod;

    finv[i] = finv[i - 1] * inv[i] % Mod;

  }

}



ll com(ll n, ll r) {

  if (n < r)

    return 0;

  if (n < 0 || r < 0)

    return 0;

  return fac[n] * (finv[r] * finv[n - r] % Mod) % Mod;

}



int main() {

  ll n, k;

  cin >> n >> k;

  vector<ll> a(n);

  rep(i, n)

  {

    cin >> a[i];

  }

  comInit();



  sort(a.begin(), a.end());



  ll maxsum = 0;

  rep(i, n)

  {

    maxsum += (com(i, k - 1) * a[i]) % Mod;

    maxsum %= Mod;

  }



  reverse(a.begin(), a.end());

  ll minsum = 0;

  rep(i, n)

  {

    minsum += (com(i, k - 1) * a[i]) % Mod;

    minsum %= Mod;

  }



  cout << (maxsum - minsum) % Mod << endl;



  return 0;

}