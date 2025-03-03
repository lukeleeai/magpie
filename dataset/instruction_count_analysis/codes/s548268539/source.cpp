#include <algorithm>

#include <bitset>

#include <cassert>

#include <cmath>

#include <climits>

#include <cstdlib>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <string>

#include <vector>

#define DEBUG 1

using namespace std;

constexpr int MOD = 1000000007;

typedef long long LL;



vector<long long> fact, fact_inv, inv;



void init_nCk(int SIZE) {

  fact.resize(SIZE + 5);

  fact_inv.resize(SIZE + 5);

  inv.resize(SIZE + 5);

  fact[0] = fact[1] = 1;

  fact_inv[0] = fact_inv[1] = 1;

  inv[1] = 1;

  for (int i = 2; i < SIZE + 5; i++) {

    fact[i] = fact[i - 1] * i % MOD;

    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;

    fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;

  }

}



long long nCk(int n, int k) {

  if (n < k) return 0;

  if (n < 0 || k < 0) return 0;

  return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;

}



int main() {

  int N, K; std::cin >> N >> K;

  init_nCk(1e5);

  for (int k = 1; k <= K; ++k) {

    std::cout << nCk(N - K + 1, k) * nCk(K - 1,  k - 1) % MOD << std::endl;

  }

}
