#include "bits/stdc++.h"



using namespace std;



int main()

{

    cin.tie(0);

    ios::sync_with_stdio(false);



    int n;

    while (cin >> n, n)

    {

        vector<int> w(n);

        for (int i = 0; i < n; i++)

            cin >> w[i];

        vector<vector<int>> dp(n, vector<int>(n, 0));

        int ret = 0;

        for (int i = 0; i < n - 1; i++)

        {

            if (abs(w[i] - w[i + 1]) <= 1)

            {

                dp[i][i + 1] = 2;

                ret = 2;

            }

        }

        for (int i = 3; i <= n; i++)

        {

            for (int j = 0; j <= n - i; j++)

            {

                if (dp[j + 1][j + i - 2] == i - 2 && abs(w[j] - w[j + i - 1]) <= 1)

                {

                    dp[j][j + i - 1] = i;

                    ret = i;

                }

                else

                {

                    for (int k = j + 1; k <= j + i - 1; k++)

                    {

                        dp[j][j + i - 1] = max(dp[j][j + i - 1], dp[j][k - 1] + dp[k][j + i - 1]);

                    }

                    ret = max(ret, dp[j][j + i - 1]);

                }

            }

        }

        cout << ret << endl;

    }

}


