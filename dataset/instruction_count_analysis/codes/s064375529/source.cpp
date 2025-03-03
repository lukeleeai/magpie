#include "stdc++.h"

#define int long long

using namespace std;

const int oo =1e18;

const int MOD = 1e9 + 7;

const int Nmax = 1005;



int gt[Nmax];

int inv[Nmax];

int dp[Nmax][Nmax];

int n,a,b,c,d;



int power(int n, int k)

{

    if (k == 0) return 1;

    int tmp = power(n, k / 2);

    tmp = tmp * tmp % MOD;

    if (k % 2) return tmp * n % MOD;

    return tmp;

}



void init()

{

    gt[0] = 1;

    for (int i = 1; i <= 1000; i++)

    {

        gt[i] = gt[i - 1] * i;

        if (gt[i] > MOD) gt[i] %= MOD;

    }

    inv[0] = 1;

    for (int i = 1; i <= 1000; i++)

    {

        inv[i] = power(gt[i], MOD - 2);

    }

}



signed main()

{

    //freopen("file.inp","r",stdin);

    init();

    cin >> n >> a >> b >> c >> d;

    dp[a - 1][0] = 1;

    for (int i = a; i <= b; i++)

    for (int j = 0; j <= n; j++)

    {

        dp[i][j] += dp[i - 1][j];

        for (int k = c; k <= d; k++)

        {

            if (i * k > j) break;

            int res = gt[j] * power(inv[i], k) % MOD * inv[j - k * i] % MOD * inv[k] % MOD;

            dp[i][j] += dp[i - 1][j - i * k] * res % MOD;

            if (dp[i][j] > MOD) dp[i][j] %= MOD;

        }

    }

    cout << dp[b][n];

    return 0;

}
