#include <iostream>

#include <vector>

#include <iomanip>

#include <algorithm>

#include <cmath>

#define REP(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;

using arr = vector<ll>;

constexpr ll MOD = 1000000007;

constexpr ll INF = 1LL << 60;

constexpr int MAX = 110000;

long fac[MAX], inv[MAX], finv[MAX];

void init()

{

    fac[0] = inv[0] = finv[0] = 1;

    fac[1] = inv[1] = finv[1] = 1;

    for (int i = 2; i < MAX; ++i)

    {

        fac[i] = fac[i - 1] * i % MOD;

        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;

        finv[i] = finv[i - 1] * inv[i] % MOD;

    }

}

long C(int n, int k)

{

    if (n < 0 || k < 0 || n < k)

        return 0;

    return (fac[n] * finv[n - k] % MOD) * finv[k] % MOD;

}



ll n, b;



int main()

{

  cin >> n >> b;

  ll r = n - b;

  init();

  REP(i, b)

    cout << C(b - 1, i) * C(r - i + i + 1, i + 1) % MOD << '\n';

  return 0;

}