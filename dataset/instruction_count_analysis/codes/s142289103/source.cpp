#ifdef ConanYu

#include "local.hpp"

#else

#pragma GCC optimize("-O3")

#include "stdc++.h"

using namespace std;

typedef long long ll;

void Main();

#define debug(...) do { } while(0)

int main() {

  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

  Main();

}

#endif



const int MOD = 1e9 + 7;

const int N = 2e5 + 10;

int fac[N], inv[N];



int fpow(int a, int b) {

  int ans = 1;

  for(; b > 0; a = 1ll * a * a % MOD, b >>= 1) {

    if(b & 1) {

      ans = 1ll * ans * a % MOD;

    }

  }

  return ans;

}



void init() {

  fac[0] = 1;

  for(int i = 1; i < N; i++) {

    fac[i] = 1ll * fac[i - 1] * i % MOD;

  }

  inv[N - 1] = fpow(fac[N - 1], MOD - 2);

  for(int i = N - 2; i >= 0; i--) {

    inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;

  }

}



const int INV2 = fpow(2, MOD - 2);



int f(int n) {

  return 1ll * n * (n + 1) % MOD * INV2 % MOD;

}



void Main() {

  init();

  int n, m, k; cin >> n >> m >> k;

  int ans = 1ll * fac[n * m - 2] * inv[k - 2] % MOD * inv[n * m - k] % MOD;

  int c = 0;

  for(int i = 0; i < m; i++) {

    c += 1ll * f(i) * n % MOD * n % MOD;

    if(c >= MOD) c -= MOD;

  }

  for(int i = 0; i < n; i++) {

    c += 1ll * f(i) * m % MOD * m % MOD;

    if(c >= MOD) c -= MOD;

  }

  ans = 1ll * ans * c % MOD;

  cout << ans << "\n";

}
