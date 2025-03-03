#include <unordered_map>

#include <chrono>

#include <random>

#include <algorithm>

#include <cstdint>

#include <cstring>

#include <cstdio>

using namespace std;



static const int Maxn = 155;



struct custom_hash {

  static uint64_t splitmix64(uint64_t x) {

    x += 0x9e3779b97f4a7c15;

    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;

    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

    return x ^ (x >> 31);

  }

  size_t operator()(uint64_t x) const {

    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

    return splitmix64(x + FIXED_RANDOM);

  }

};



int n, k, mod;

inline int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }

inline void inc(int &x, int y) { (x += y) >= mod && (x -= mod); }

inline int mul(int x, int y) { return 1LL * x * y - 1LL * x * y / mod * mod; }



namespace solve1 {

/* N个数中选一些数使得连续段的长度不超过K */

  int dp[Maxn][Maxn];

  int solve(int n, int k) {

  memset(dp, 0, sizeof(dp));

  dp[0][0] = 1;

  for (int i = 0; i < n; ++i) {

    for (int j = 0; j <= k; ++j) {

      inc(dp[i + 1][0], dp[i][j]);

    }

    for (int j = 0; j < k; ++j) {

      inc(dp[i + 1][j + 1], dp[i][j]);

    }

  }

  int res = 0;

  for (int j = 0; j <= k; ++j) {

    inc(res, dp[n][j]);

  }

  return res;

  }

}



namespace solve2 {

  int n, k;

  unordered_map<long long, int, custom_hash> dp[Maxn];

  inline long long encode(int p, int q, int mxp, int mxq) {

    return (p * 1LL << 40) | (q * 1LL << 30) | (mxp * 1LL << 20) | (mxq * 1LL << 10);

  }

  int dfs(int pos, int p, int q, int mxp, int mxq) {

    if (mxp < pos || mxq < pos) return 0;

    if (pos == n) return 1;

    p = min(p, k / 2 + 1);

    q = min(q, k / 2 + 1);

    long long enc = encode(p, q, mxp, mxq);

    if (dp[pos].find(enc) != dp[pos].end()) return dp[pos][enc];

    int &ans = dp[pos][enc]; ans = 0;

    int res1, res2;



// 填入数pos

    int newmxp = n, newmxq = n;

    if (pos % 2 == 0 && 2 * q - 1 >= k) newmxq = pos + k - 2 * min(k / 2, p);

    if (pos % 2 == 1 && 2 * p - 1 >= k) newmxp = pos + k - 2 * min(k / 2, q);

    int newp = p + (pos % 2 == 0), newq = q + (pos % 2 == 1);

    res1 = dfs(pos + 1, newp, newq, min(mxp, newmxp), min(mxq, newmxq));



// 不填数pos

    if (pos % 2 == 0) res2 = dfs(pos + 1, 0, q, n, mxq);

    else res2 = dfs(pos + 1, p, 0, mxp, n);



    return ans = add(res1, res2);

  }

  int solve(int n, int k) {

    solve2::n = n, solve2::k = k;

    for (int i = 0; i <= n; ++i) {

      unordered_map<long long, int, custom_hash> empty_tmp;

      dp[i].swap(empty_tmp);

    }

    return dfs(0, 0, 0, n, n);

  }

}



int main() {

  scanf("%d%d%d", &n, &k, &mod);

  if (k == 1) {

    printf("%d\n", solve1::solve(n, 2));

    return 0;

  }

  if (k % 2 == 0) {

    int odd = solve1::solve(n + 1 >> 1, k >> 1);

    int even = solve1::solve(n >> 1, k >> 1);

    printf("%d\n", mul(odd, even));

    return 0;

  }

  printf("%d\n", solve2::solve(n, k));

  return 0;

}
