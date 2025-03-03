#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <cstring>



using namespace std;



#define N 100008

#define INF 0x3f3f3f3f



int n;

int dp[N], v[N], p[N];



int dfs(int s)

{

    if (!s) return 0;

    if (dp[s] != INF) return dp[s];

    for (int i = 0; i <= 15; i++)

    {

        for (int j = 0; j <= 15; j++)

        {

            if (i == j) continue;

            if ((s & p[i]) && (s & p[j]))

            {

                int temp = i ^ j;

                if (p[temp] & s)

                    dp[s] = min(dp[s], dfs(s^p[temp]^p[i]^p[j])+2);

                else

                    dp[s] = min(dp[s], dfs(s^p[temp]^p[i]^p[j])+1);

            }

        }

    }

    return dp[s];

}



int main()

{

    int x, y, z;

    p[0] = 1;

    for (int i = 1; i <= 20; i++)

        p[i] = p[i-1] * 2;

    while (~scanf("%d", &n))

    {

        memset(v, 0, sizeof(v));

        memset(dp, 0x3f, sizeof(dp));

        for (int i = 1; i < n; i++)

        {

            scanf("%d%d%d", &x, &y, &z);

            v[x+1] ^= z;

            v[y+1] ^= z;

        }

        int start = 0, ans = 0;

        for (int i = 1; i <= n; i++)

        {

            if (v[i] == 0) continue;

            if (start & p[v[i]])

                ans++;

            start ^= p[v[i]];                

        }

        ans += dfs(start);

        printf("%d\n", ans);

    }

    return 0;

}