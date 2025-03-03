#include "stdc++.h"

using namespace std;



int dp[100005][30];

int vis[30];

int main()

{

    string s;

    string t;

    cin >> s >> t;

    memset(dp,0x3f,sizeof(dp));

    for(int i = 0; i < s.length(); i++)

    {

        vis[s[i] - 'a'] = 1;

    }

    for(int i = s.length() - 2; i >= 0; i--)

    {

        for(int j = 0; j < 26; j++)

        {

            dp[i + 1][j] = dp[i + 2][j];

        }

        dp[i + 1][s[i + 1] - 'a'] = i + 2;

    }

    for(int j = 0; j < 26; j++)

    {

        dp[0][j] = dp[1][j];

    }

    dp[0][s[0] - 'a'] = 1;

    long long nowl = 0,nowr = 0;

    for(int i = 0; i < t.length(); i++)

    {

        if(!vis[t[i] - 'a'])

        {

            cout << "-1" << endl;

            return 0;

        }

        if(dp[nowl][t[i] - 'a'] == 0x3f3f3f3f)

        {

            nowr++;

            nowl = dp[0][t[i] - 'a'];

        }

        else

        {

            nowl = dp[nowl][t[i] - 'a'];

        }

        // cout << nowl << " " << nowr <<endl;

    }

    cout << nowl + nowr * s.length();

}