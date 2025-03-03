#include "stdc++.h"

#define RI register int

typedef long long LL;



using namespace std;



LL const mod = 924844033, MAXN = 1e4 + 5;

int vis[MAXN], len[MAXN], tot;

LL dp[2][MAXN][2], g[2][MAXN], frac[MAXN];

vector <LL> f[MAXN];



int main() {

 // freopen("count.in", "r", stdin);

 // freopen("count.out", "w", stdout);

  int n, k; scanf("%d %d", &n, &k);

  frac[0] = 1;

  for (RI i = 1; i <= n; ++i) frac[i] = frac[i - 1] * 1ll * i % mod;

  if (!k) return printf("%lld\n", frac[n]), 0;

  for (RI i = 1; i <= n; ++i)

    if (!vis[i]) {

      len[++tot] = 0;

      for (RI j = i; j <= n; j += k)

        vis[j] = 1, ++len[tot];

      memset(dp, 0, sizeof(dp));

      dp[1][0][0] = 1;

      for (RI j = 2; j <= len[tot]; ++j) {

        for (RI l = 0; l <= j >> 1; ++l) {

          dp[j & 1][l][0] = (dp[(j + 1) & 1][l][0] + dp[(j + 1) & 1][l][1]) % mod;

          if (l > 0) dp[j & 1][l][1] = dp[(j + 1) & 1][l - 1][0];

        }

      }

      for (RI j = 0; j <= len[tot] >> 1; ++j)

        f[tot].push_back(dp[len[tot] & 1][j][0] + dp[len[tot] & 1][j][1]);

    }

  g[1][0] = 1;

  for (RI i = 2; i <= (tot << 1) + 1; ++i) {

    memset(g[i & 1], 0, sizeof(g[i & 1]));

    for (RI j = 0; j <= len[i >> 1] >> 1; ++j)

      for (RI k = j; k <= n; ++k)

        g[i & 1][k] = (g[i & 1][k] + g[(i + 1) & 1][k - j] * f[i >> 1][j] % mod) % mod;

  }

  LL ans = 0;

  for (RI i = 0; i <= n; ++i)

    ans = (ans + (i & 1 ? -1ll : 1ll) * g[1][i] * frac[n - i] % mod) % mod;

  printf("%lld\n", (ans % mod + mod) % mod);

  return 0;

}