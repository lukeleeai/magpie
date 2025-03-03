#include "stdc++.h"



// dp[i][500yen][num_1000yen] := remain ([i] is deleted)

int dp[128][512];

int n;

int P[128];



void init() {

  for(int j = 0; j < 128; ++j) {

    for(int k = 0; k < 512; ++k) {

      dp[j][k] = -1;

    }

  }

}



int main() {

  for(;;) {

    init();

    scanf("%d", &n);

    if( n == 0 ) break;

    for(int i = 0; i < n; ++i) {

      scanf("%d", &P[i]);

    }

    int k_max = 0;

    dp[0][0] = 0;

    for(int i = 0; i < n; ++i) {

      k_max += (P[i] + 999) / 1000;

      for(int j = i; j >= 0; --j) {

        for(int k = k_max; k >= 0; --k) {

          if( dp[j][k] == -1 ) continue;

          int n1kyen = (P[i] + 999) / 1000;

          int rem = dp[j][k] + n1kyen * 1000 - P[i];

          int next_num500yen = j + (rem >= 500 ? 1 : 0);

          int next_num1kyen  = k + n1kyen;

          int next_rem       = rem >= 500 ? rem - 500 : rem;

          int& next = dp[next_num500yen][next_num1kyen];

          next = std::max(next, next_rem);

        }

      }

    }    

    int res = (1 << 28);

    int max = -1;

    for(int j = n; j >= 0; --j) {

      for(int k = 0; k < 512; ++k) {

        if( dp[j][k] == -1 ) continue;

        int cost = k * 1000 - 500 * j - dp[j][k];

        res = std::min(res, cost);

      }

      if( res != (1 << 28) ) {

        max = j;

        break;

      }

    }

    printf("%d %d\n", max, res);

  }



  return 0;

}