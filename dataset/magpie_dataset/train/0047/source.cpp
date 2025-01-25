#include <cstdio>

#include <cfloat>

using namespace std;



char f[10][21];

int n, w[10], s[10], a[10], b[10];

bool u[10];

double maxg;



void dfs(int x, int tw, int m, double g) {

  if (m == n) {

    if (maxg < g) {

      maxg = g;

      for (int i=0; i<n; i++) {

        b[i] = a[i];

      }

    }

    return;

  }

  if (x>=n) {

    return;

  }

  if (!u[x] && tw <= s[x]) {

    u[x] = true;

    tw += w[x];

    a[m] = x;

    dfs(0, tw, m+1, g + w[x]*(m+1));

    tw -= w[x];

    u[x] = false;

  }

  dfs(x+1, tw, m, g);

}



int main() {

  while (1) {

    scanf("%d", &n);

    if (!n) break;

    for (int i=0; i<n; i++) {

      scanf("%s %d %d", f[i], &w[i], &s[i]);

    }

    for (int i=0; i<n; i++) {

      u[i] = false;

    }

    maxg = -DBL_MAX;

    dfs(0, 0, 0, 0.);

    for (int i=n-1; i>=0; i--) {

      printf("%s\n", f[b[i]]);

    }

  }

  return 0;

}