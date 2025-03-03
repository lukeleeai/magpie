#include "stdc++.h"



using namespace std;



const int N = 233;



int main() {

  int n;

  scanf("%d", &n);

  vector<int> dp(N);

  for (int i = 0; i < n; i++) {

    int cur;

    scanf("%d", &cur);

    vector<int> ndp(N, n);

    for (int x = 0; x < N; x++) {

      for (int y = 0; y < N; y++) {

        if (x != y) {

          ndp[y] = min(ndp[y], dp[x] + (y != cur));

        }

      }

    }

    dp = ndp;

  }

  int ans = *min_element(dp.begin(), dp.end());

  printf("%d\n", ans);

  return 0;

}