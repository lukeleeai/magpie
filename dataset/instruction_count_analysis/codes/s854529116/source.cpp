#include <cstdio>



const int MaxN = 100 + 5, MaxK = 100000 + 5;



int N, K;

int A[MaxN];

bool Dp[MaxK];



void init() {

  scanf("%d %d", &N, &K);

  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);

}



void solve() {

  Dp[0] = false;

  for (int i = 1; i <= K; ++i) {

    Dp[i] = false;

    for (int j = 1; j <= N; ++j)

      if (i >= A[j] && Dp[i - A[j]] == false)

        Dp[i] = true;

  }

  puts(Dp[K] == true ? "First" : "Second");

}



int main() {

  init();

  solve();

  return 0;

}