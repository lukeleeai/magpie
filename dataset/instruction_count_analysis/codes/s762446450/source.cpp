#include <cstdio>

using namespace std;

static_assert(sizeof(long) >= 8, "sizeof(long) >= 8");

constexpr int mod = 998244353;

int fac[20001], inv[20001];

int dp[10001];

int solve(int x, int y) {

    dp[0] = 1;

    for (int i = 1; i <= x; i++)

        for (int j = 1; j <= y; j++)

            dp[j] = (dp[j] + (long) i * dp[j - 1]) % mod;

    int ans = 0;

    for (int i = 0; i <= y; i++)

        ans = (ans + (long) dp[i] * inv[x + i]) % mod;

    return (long) ans * fac[x] % mod

                      * fac[x] % mod

                      * fac[y] % mod

                      * fac[x + y] % mod;

}

char a[10001], b[10001];

int main() {

    fac[0] = 1;

    for (int i = 1; i <= 20000; i++)

        fac[i] = (long) fac[i - 1] * i % mod;

    inv[20000] = 292343761;

    for (int i = 20000; i >= 1; i--)

        inv[i - 1] = (long) inv[i] * i % mod;



    scanf("%s%s", a, b);

    int x = 0, y = 0;

    for (int i = 0; a[i]; i++)

        if (a[i] == '1')

            (b[i] == '0' ? x : y)++;

    printf("%d\n", solve(x, y));

}
