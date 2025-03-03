#include <cstdio>

#include <vector>



int scan() {

  int r = 0;

  int c;

  while ((c = getchar_unlocked() - '0') >= 0)

    r = r * 10 + c;

  return r;

}



int main() {

  const int n = scan();

  std::vector<std::vector<int>> t(n);

  for (int i = 0; i != n - 1; i += 1) {

    const int a = scan() - 1;

    const int b = scan() - 1;

    t[a].push_back(b);

    t[b].push_back(a);

  }

  const int m = scan();

  const int s = 1 << m;

  std::vector<int> z(s, 0);

  {

    std::vector<int> x(n, 0);

    for (int i = 0; i != m; i += 1) {

      const int u = scan() - 1;

      const int v = scan() - 1;

      x[u] ^= 1 << i;

      x[v] ^= 1 << i;

    }

    const auto dfs = [&](const auto &dfs, int v, int p) -> void {

      for (int e : t[v]) {

        if (e != p) {

          dfs(dfs, e, v);

          z[x[e]] += 1;

          x[v] ^= x[e];

        }

      }

    };

    dfs(dfs, 0, n);

  }

  for (int w = 1; w != s; w <<= 1) {

    for (int i = 0; i != s; i += w << 1) {

      const int end = i + w;

      for (int j = i; j != end; j += 1) {

        z[j + w] += z[j];

      }

    }

  }



  long long ans = 0;

  for (int i = 0; i != 1 << m; i += 1) {

    auto res = 1LL << z[s - 1 ^ i];

    if (__builtin_parity(i))

      res = -res;

    ans += res;

  }

  printf("%lld", ans);

}