// Written by newbiechd

#include <cstdio>

#include <cctype>

#include <cstring>

using namespace std;



const int BUF = 100003;

inline char getChar() {

  static char buf[BUF], *bufS, *bufT;

  if (bufS == bufT) {

    bufT = (bufS = buf) + fread(buf, 1, BUF, stdin);

    if (bufS == bufT) return EOF;

  }

  return *bufS++;

}

inline int read() {

  int f = 0;

  char ch;

  while (!isdigit(ch = getChar())) {}

  do f = f * 10 + (ch ^ 48);

  while (isdigit(ch = getChar()));

  return f;

}



const int maxN = 403, mod = 998244353;

int a[maxN], b[maxN], inv[maxN], fac[maxN], bin[maxN][maxN];

int p[maxN][maxN], temp[maxN][maxN];



inline int power(int x, int y) {

  int o = 1;

  while (y) {

    if (y & 1) o = 1ll * o * x % mod;

    x = 1ll * x * x % mod, y >>= 1;

  }

  return o;

}



int main() {

  int n = read(), i, j, k, t, A = 0, B = 0, ans = 0;

  for (i = 1; i <= n; ++i)

    A += a[i] = read(), b[i] = read();

  inv[1] = 1;

  for (i = 2; i < maxN; ++i)

    inv[i] = -1ll * (mod / i) * inv[mod % i] % mod;

  fac[0] = 1;

  for (i = 1; i < maxN; ++i)

    fac[i] = 1ll * fac[i - 1] * i % mod;

  k = power(A, mod - 2);

  for (i = 1; i <= n; ++i) {

    t = 1ll * k * a[i] % mod, bin[i][0] = 1;

    for (j = 1; j < b[i]; ++j)

      bin[i][j] = 1ll * bin[i][j - 1] * t % mod * inv[j] % mod;

  }

  

  p[0][0] = 1, A = 0;

  for (i = 1; i <= n; ++i) {

    for (j = 0; j <= A; ++j)

      for (k = 0; k <= B; ++k) {

        temp[j + a[i]][k] = (temp[j + a[i]][k] + p[j][k]) % mod;

        for (t = 0; t < b[i]; ++t)

          temp[j][k + t] = (-1ll * p[j][k] * bin[i][t] + temp[j][k + t]) % mod;

      }

    A += a[i], B += b[i];

    for (j = 0; j <= A; ++j) {

      memcpy(p[j], temp[j], sizeof(int) * B);

      memset(temp[j], 0, sizeof(int) * B);

    }

  }

  

  for (i = 0; i <= A; ++i)

    for (j = 0; j <= B; ++j)

      p[i][j] = -p[i][j];

  ++p[A][0];

  k = power(A, mod - 2);

  for (i = 0; i < A; ++i) {

    t = 1ll * k * i % mod;

    for (j = 0; j <= B; ++j)

      ans = (1ll * p[i][j] * fac[j] % mod * power(1 - t, mod - j - 2) + ans)

        % mod;

  }

  printf("%d\n", (ans + mod) % mod);

  return 0;

}
