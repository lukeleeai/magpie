#include<cstdio>

#include<bitset>

#include<cmath>

using namespace std;



int h, w, a[80][80], b[80][80], mid = 6480;

bitset<12960> dp[80], temp;

 

int main() {

  scanf("%d%d", &h, &w);

  for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) scanf("%d", &a[i][j]);

  for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) scanf("%d", &b[i][j]);

  dp[0][mid+a[0][0]-b[0][0]] = true;

  dp[0][mid-a[0][0]+b[0][0]] = true;

  for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) if (i + j > 0) {

    temp = dp[j];

    if (j != 0) temp |= dp[j-1];

    int x = abs(a[i][j]-b[i][j]);

    dp[j] = (temp >> x) | (temp << x);

  }

  for (int i = 0;; i++) if (dp[w-1][mid-i] || dp[w-1][mid+i]) {

    printf("%d\n", i);

    return 0;

  }

}
