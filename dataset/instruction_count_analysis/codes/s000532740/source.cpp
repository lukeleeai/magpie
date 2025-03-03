#include "stdc++.h"



using namespace std;



const int N = 112;

const int C = 1103;



int n, c;

int l[N], q[N];

long long f[C][N];



long long solve();



int main() {

  scanf("%d%d", &n, &c);

  for (int i = 1; i <= n; ++i) scanf("%d", &l[i]);

  sort(l + 1, l + n + 1);

  for (int i = 1; i < n; ++i) q[i] = i;

  long double res = 0;

  do { 

    res += solve();

  } while (next_permutation(q + 1, q + n));

  for (int i = 1; i < n; ++i) 

    res /= i * c * 1.0;

  printf("%.12Lf\n", res);

  return 0;

}



long long solve() {

  memset(f, 0, sizeof(f));

  f[n * l[n]][0] = 1;

  for (int i = 0; i < n * c; ++i) {

    if (!(i % n)) continue;

    int x = q[i % n];

    for (int s = 0; s <= (1 << (n - 1)) - 1; ++s) {

      if (s & (1 << (x - 1))) continue;

      for (int j = i; j <= n * c; ++j) {

        f[min(n * c, max(j, i + n * l[x]))]

          [s | (1 << (x - 1))] += f[j][s];

      }

    }

  }

  return f[n * c][(1 << (n - 1)) - 1];

}
