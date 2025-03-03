#include <iostream>

#include <string>

#include <cstdio>

#include <cstdlib>

 

using namespace std;

 

const int SZ = 1e6;

int dp[SZ];

 

int32_t main()

{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;

    string s;

    cin >> n >> s;

    fill(dp, dp + SZ, 0);

    dp[0] = 0;

    for (int i = 0; i < n; i++)

    {

        dp[i + 1] = max(dp[i + 1], dp[i]);

        if (s[i] == '1' || i == 0 || i == n - 1) continue;

        if (s[i-1] != '1' || s[i + 1] != '1') continue;

        int i1 = i - 1, i2 = i + 1;

        while (s[i1] == '1' && i1 >= 0)

            i1--;

        while (s[i2] == '1' && i2 < n)

            i2++;

        for (int j = i1 + 1; j < i; j++)

            dp[i + 2] = max(dp[i + 2], i - j + dp[j]);

        for (int j = i2 - 1; j > i; j--)

            dp[j + 1] = max(dp[j + 1], j - i + dp[i - 1]);

    }

    cout << dp[n] << endl;

}