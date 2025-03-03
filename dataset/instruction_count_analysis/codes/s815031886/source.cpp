#include <cstdio>

#include <algorithm>

#include <cstring>

#include <cmath>

#include <vector>

using namespace std;

static_assert(sizeof(long) >= 8, "sizeof(long) >= 8");

constexpr int mod = 998244353;

long fac[100001], inv[100001];

int dp[10001];

int solve(int x, int y) {

    dp[0] = 1;

    for (int i = 1; i <= x; i++)

        for (int j = 1; j <= y; j++)

            dp[j] = (dp[j] + (long) i * dp[j - 1]) % mod;

    long ans = 0;

    for (int i = 0; i <= y; i++)

        ans = (ans + dp[i] * inv[x + i]) % mod;

    return ans * fac[x] % mod * fac[x] % mod * fac[y] % mod * fac[x + y] % mod;

}

char a[10001], b[10001];

int main() {

    fac[0] = 1;

    for (int i = 1; i <= 100000; i++)

        fac[i] = fac[i - 1] * i % mod;

    inv[100000] = 812950533;

    for (int i = 100000; i >= 1; i--)

        inv[i - 1] = inv[i] * i % mod;



    scanf("%s%s", a, b);

    int x = 0, y = 0;

    for (int i = 0; a[i]; i++)

        if (a[i] == '1')

            (b[i] == '0' ? x : y)++;

    printf("%d\n", solve(x, y));

}
