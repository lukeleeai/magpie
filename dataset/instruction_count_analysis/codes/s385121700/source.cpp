#include <cstdio>

int a[100005];

int n, m, sum;

void solve(int n, int m, int sum) {

  if (m == 0) {

    int all;

    if (sum == 1e9) {

      all = sum / n - 1;



    } else {

      all = sum + 1;

    }

    for (int i = 0; i < n; ++i) {

      a[i] = all;

    }

  } else {

    if (sum - n + m > 0) {

      for (int i = 0; i < n - m; ++i) {

        a[i] = 1;

      }

      a[n - m] = sum - n + m;

      for (int i = n - m + 1; i < n; ++i) {

        a[i] = sum;

      }

    } else {

      if (sum > 1) {

        solve(m + 1, m, sum);

        for (int i = m + 1; i < n; ++i) {

          a[i] = sum + 1;

        }

      } else {

        for (int i = 0; i < m; ++i) {

          a[i] = 1;

        }

        for (int i = m; i < n; ++i) {

          a[i] = 2;

        }

      }

    }

  }

}

int main() {

  scanf("%d %d %d", &n, &m, &sum);

  solve(n, m, sum);

  printf("%d", a[0]);

  for (int i = 1; i < n; ++i) {

    printf(" %d", a[i]);

  }

  printf("\n");

  return 0;

}
