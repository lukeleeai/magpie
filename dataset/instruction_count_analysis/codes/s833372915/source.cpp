#include "stdc++.h"

#define FOR(i,a,b) for (int i=(a);i<(b);i++)

#define pb push_back



typedef long long ll;

using namespace std;

int MOD (1e9+7);

int powMod(int a, int n, int m){

  ll pro = 1, tmp = a;

  for(; n > 0; n >>= 1){

    if(n & 1) pro = (pro * tmp) % m;

    tmp = tmp * tmp % m;

  }

  if (pro < 0) cout << "pro < 0" << a << "," << n << endl;

  return pro;

}



vector<int> A, R;

int comb(int n, int c){

  return int(ll(A[n + c]) * R[n] % MOD * R[c] % MOD);

}

main(){

  cin.tie(0);

  ios::sync_with_stdio(false);

  int N, M, K;

  cin >> N >> M >> K;



  ll t = 1;

  A.pb(1);

  R.pb(1);

  FOR(i, 1, N + M + K + 1){

    t = t * i % MOD;

    A.pb(t);

    R.pb(powMod(t, MOD - 2, MOD));

  }

  int sum = M + K, p3 = powMod(3, sum, MOD), ret = p3, r3 = powMod(3, MOD - 2, MOD);

  if(M > K) swap(M, K);

  ll pre = 1;



  FOR(i, 1, sum + 1){

    pre *= 2;

    p3 = ll(p3) * r3 % MOD;

    if(i > M){

      pre = pre + MOD - comb(M, i - M - 1);

      if(i > K) pre = pre + MOD - comb(K, i - K - 1);

    }

    pre %= MOD;

    ret += pre * comb(N - 1, i) % MOD * p3 % MOD;

    ret %= MOD;

  }

  cout << ret << endl;

}
