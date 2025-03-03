#include "stdc++.h"

using namespace std;



const int N = 310;



typedef long long LL;



int dp[N][N], C[N][N], sum[N][N];



int main() {

    int n, k, mod; scanf("%d%d%d", &n, &k, &mod), n++;

    for (int i = 0; i <= n; i++) {

        C[i][0] = 1;

        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;

    }

    for (int i = 0; i <= k; i++) sum[1][i] = k - i + 1, dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {

        for (int j = 0; j <= k; j++) {

            for (int t = 1; t < i; t++) 

                dp[i][j] = (dp[i][j] + (LL)dp[i - t][j] * C[i - 2][t - 1] % mod * sum[t][j + 1]) % mod;

        }

        for (int j = k; j >= 1; j--) sum[i][j] = (sum[i][j + 1] + dp[i][j]) % mod;

    }

    printf("%d\n", dp[n][0]);

    return 0;

}//