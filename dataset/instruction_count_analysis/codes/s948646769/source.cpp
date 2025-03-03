#include <stdio.h>

#include <stdlib.h>

#include <algorithm>



#define MAX_N (40)

#define MAX_A (10)

#define MAX_B (10)

#define INF (1 << 30)



using namespace std;



int dp[MAX_N + 1][MAX_N * MAX_A + 1][MAX_N * MAX_B + 1];



// self study

// time taken 40min

int main(int argc, char *argv[]) {

  // read inputs

  int N, Ma, Mb, as[MAX_N], bs[MAX_N], cs[MAX_N];

  scanf("%d %d %d", &N, &Ma, &Mb);

  for (int i = 0; i < N; i++) {

    scanf("%d %d %d", &as[i], &bs[i], &cs[i]);

  }



  // solve dp

  // dp[k+1][i][j] : minimum cost to make (i, j) using items 0 to k

  for (int i = 0; i <= N * Ma; i++) {

    for (int j = 0; j <= N * Mb; j++) {

      dp[0][i][j] = INF;

    }

  }

  dp[0][0][0] = 0;

  for (int k = 0; k < N; k++) {

    const int a = as[k], b = bs[k], c = cs[k];

    for (int i = 0; i <= N * Ma; i++) {

      for (int j = 0; j <= N * Mb; j++) {

        const int i2 = i - a, j2 = j - b;

        if (i2 >= 0 && j2 >= 0) {

          dp[k + 1][i][j] = min(dp[k][i][j], dp[k][i2][j2] + c);

        } else {

          dp[k + 1][i][j] = dp[k][i][j];

        }

        // printf("%d ", dp[k + 1][i][j]);

      }

    }

  }



  int min_cost = INF;

  for (int k = 1; k <= N; k++) {

    min_cost = min(min_cost, dp[N][k * Ma][k * Mb]);

  }

  if (min_cost < INF) {

    printf("%d\n", min_cost);

  } else {

    printf("-1\n");

  }



  return 0;

}
