#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <string>

#include <cstdlib>

#define N 3030

typedef long long ll;

template<typename T> inline void read(T &x) {

  x = 0; char c = getchar();

  while (!isdigit(c)) { c = getchar(); }

  while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }

}

using namespace std;

const int P = 1e9 + 7;

int n, m;

int f[N][N][2];

inline void ADD(int &a, int b) {

  a += b;

  if (a >= P) a -= P;

}

inline void work() {

  for (int i = 0; i <= n; ++i)  f[0][i][0] = 1;

  for (int i = 0; i < m; ++i) {

    ADD(f[i][0][1], f[i][0][0]);

    f[i][0][0] = 0;

    for (int j = 0; j <= n; ++j) {

      for (int t = 0; t < 2; ++t) if (f[i][j][t]) {

        if (j != 0) {

          if (t == 0 && j == 1) ADD(f[i + 1][j][1], f[i][j][0]);

          else  ADD(f[i + 1][j][t], f[i][j][t]);

          ADD(f[i + 1][j - 1][t], f[i][j][t]);

        }

        if (j != n) {

          ADD(f[i + 1][j][t], f[i][j][t]);

          ADD(f[i + 1][j + 1][t], f[i][j][t]);

        }

      }

    }

  }

  int ans = 0;

  for (int i = 0; i <= n; ++i)  ADD(ans, f[m][i][1]);

  ADD(ans, f[m][0][0]);

  printf("%d\n", ans);

}

int main() {

  read(n), read(m);

  work();

  return 0;

}
