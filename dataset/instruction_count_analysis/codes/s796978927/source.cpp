#include <iostream>

#include <algorithm>

#include <vector>

#include <set>

#include <bitset>



const int MOD = 1e9 + 7;



using namespace std;



long long si = 0;



long long inq(long long a, long long b)

{

    if (b == 0) return 1;

    long long l = inq(a, b / 2);

    if (b % 2) return l * l % MOD * a % MOD;

    return l * l % MOD;

}



const int K = 10000;

vector<long long> dp(K);



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)

    {

        for (int j = 0; j <= k; j++)

        {

            si = (si + j * inq(k + 1, n - 1)) % MOD;

        }

    }

    dp[0] = 1;

    for (int i = n; i >= 1; i--)

    {

        vector<long long> dp2(K);

        for (int a = 0; a <= k; a++)

        {

            for (int hv = 0; hv < K; hv++)

            {

                if (dp[hv] != 0)

                {

                    if (a <= i) dp2[hv + (hv + a) / i] = (dp2[hv + (hv + a) / i] + dp[hv]) % MOD;

                    else dp2[hv] = (dp2[hv] + dp[hv]) % MOD;

                }

            }

        }

        dp = dp2;

    }

    long long si2 = 0;

    for (int i = 0; i < K; i++) si2 = (si2 + dp[i] * i) % MOD;

    cout << (si + MOD - si2) % MOD;

}
