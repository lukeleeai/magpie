#include <cstdio>



const int _ = 3e3 + 5, p = 1e9 + 7;



int n, m, a[_], dp[_][_];



inline int power(int x, int k) {

    int res = 1;

    for (; k; k >>= 1, x = 1ll * x * x % p)

        if (k & 1) res = 1ll * res * x % p;

    return res % p;

}



int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) scanf("%d", a + i);

    for (int i = 1; i <= n; ++i)

        for (int j = 1; j <= n; ++j) dp[i][j] = a[i] < a[j];

    int inv2 = power(2, p - 2);

    for (int x, y, i = 1; i <= m; ++i) {

        scanf("%d %d", &x, &y);

        dp[x][y] = dp[y][x] = 1ll * inv2 * ((dp[x][y] + dp[y][x]) % p) % p;

        for (int j = 1; j <= n; ++j) {

            if (j == x | j == y) continue ;

            dp[x][j] = dp[y][j] = 1ll * inv2 * ((dp[x][j] + dp[y][j]) % p) % p;

            dp[j][x] = dp[j][y] = 1ll * inv2 * ((dp[j][x] + dp[j][y]) % p) % p;

        }

    }

    int ans = 0;

    for (int i = 1; i <= n; ++i)

        for (int j = 1; j < i; ++j) ans = (ans + dp[i][j]) % p;

    ans = 1ll * ans * power(2, m) % p;

    printf("%d\n", ans);

    return 0;

}
