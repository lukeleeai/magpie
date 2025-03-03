#include<stdio.h>

#include<algorithm>

using namespace std;

int main()

{

    int n,ans = 0;

    int dp[1100][1100];

    char field;

    while(scanf("%d",&n),n)

    {

        for(int i = 0; i < n; i++)

            for(int j = 0; j < n; j++)

            {

                scanf(" %c",&field);

                dp[j + 1][i + 1] = 0;

                if(field == '*')dp[j + 1][i + 1] = -1;

            }

        for(int i = 1; i < n + 1; i++)

        {

            for(int j = 1; j < n + 1; j++)

            {

                if(dp[j][i] == -1);

                else if(j == 1 || i == 1)dp[j][i] = 1;

                else dp[j][i] = max(1,min(dp[j - 1][i - 1],min(dp[j - 1][i],dp[j][i - 1])) + 1);

                ans = max(ans,dp[j][i]);

            }

        }

        /*for(int i = 1; i < n + 1; i++)

        {

            for(int j = 1; j < n + 1; j++)

            {

                printf("%2d",dp[j][i]);

            }

            printf("\n");

        }*/

        printf("%d\n",ans);

        ans = 0;

    }

    return 0;

}