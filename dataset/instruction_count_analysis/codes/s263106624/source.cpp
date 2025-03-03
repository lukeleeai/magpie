#include<stdio.h>

#include<algorithm>



using namespace std;



int dp[55][55][55];

int ar[55];

int n;



int serc(int x, int l, int r) {

  if (x == n) {

    return 1000000;

  }

  int &ret = dp[x][l][r];

  if (ret != -1) {

    return ret;

  }

  ret = 0;



  // ambil ke kanan

  ret = max(ret, min(serc(x + 1, l, x), min(ar[x] - ar[r], 24 - ar[l] - ar[x])));



  // ambil ke kiri

  ret = max(ret, min(serc(x + 1, x, r), min(ar[x] - ar[l], 24 - ar[r] - ar[x])));

  return ret;

}



int main() {

  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {

    scanf("%d", &ar[i]);

    for (int j = 0; j <= n; j++) {

      for (int k = 0; k <= n; k++) {

        dp[i][j][k] = -1;

      }

    }

  }

  n++;

  sort(ar, ar + n);

  printf("%d\n", min(max(serc(2, 0, 1), serc(2, 1, 0)), ar[1] - ar[0]));

  return 0;

}