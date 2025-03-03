#include "stdc++.h"



#define int long long



using namespace std;



const int N = 305;

int dp[N][N], pref[N][N], C[N][N], n, k, m;



signed main(){

    scanf("%lld %lld %lld", &n, &k, &m);



    for (int i = 0; i < N; i++) {

        for (int j = 0; j <= i; j++) {

            if (i == 0 || j == 0 || i == j) C[i][j] = 1;

            else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % m;

        }

    }



    memset(dp, 0, sizeof(dp));



    for (int i = 1; i <= k + 1; i++) {

        dp[1][i] = 1;

        if (i == 1) pref[1][i] = dp[1][i];

        else pref[1][i] = (pref[1][i - 1] + dp[1][i]) % m;

    }



    for (int i = 2; i <= n + 1; i++) {

        for (int j = 1; j <= k + 1; j++) {

            for (int p = 1; p <= i - 1; p++) {

                int res = C[i - 2][p - 1];

                res *= dp[p][j]; res %= m;

                res *= pref[i - p][j - 1]; res %= m;



                dp[i][j] = (dp[i][j] + res) % m;

            }



            if (j == 1) pref[i][j] = dp[i][j];

            else pref[i][j] = (pref[i][j - 1] + dp[i][j]) % m;

        }

    }



    printf("%lld", dp[n + 1][k + 1]);

    return 0;

}
