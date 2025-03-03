#include <algorithm>

#include <cstdio>

const int MAXN = 5005;

char S[MAXN];

int dp[MAXN][MAXN];

int N;



int solve() {

  for (int i = 0; i <= N; ++i) {

    dp[i][0] = dp[0][i] = 0;

  }

  int ret = 0;

  for (int i = 1; i <= N; ++i) {

    for (int j = 1; j <= N; ++j) {

      if ((i == j) || (S[i] != S[j])) {

        dp[i][j] = 0;

      } else if (S[i] == S[j]) {

        dp[i][j] = std::min(dp[i-1][j-1] + 1, std::abs(i - j));

        ret = std::max(dp[i][j], ret);

      }

    }

  }

  return ret;

}



int main() {

  scanf(" %d%s", &N, S+1);

  printf("%d\n", solve());

  return 0;

}