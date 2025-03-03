#pragma GCC optimize("Ofast")

#include <cstdio>

#define rint register int

using namespace std;

const int MOD = 1000000007;

const int N = 3001;

int n,cur;

long long dp[2][N];

char ch;

inline void adj(long long &x) {if(x>=MOD)x-=MOD;}

int main()

{

    scanf("%d\n",&n);

    dp[0][1]=1LL;

    for (rint i=2;i<=n;i++,cur^=1)

    {

        scanf("%c",&ch);

        if (ch=='<')

        {

            dp[cur^1][1]=0LL;

            for (rint j=2;j<=i;j++) 

            {

                dp[cur^1][j]=dp[cur^1][j-1]+dp[cur][j-1];

                adj(dp[cur^1][j]);

            }

        }

        else 

        {

            dp[cur^1][i]=0LL;

            for (rint j=i-1;j>=1;j--) 

            {

                dp[cur^1][j]=dp[cur^1][j+1]+dp[cur][j];

                adj(dp[cur^1][j]);

            }

        }

    }

    for (rint i=1;i<n;i++) dp[cur][n]+=dp[cur][i];

    printf("%lld\n",dp[cur][n]%MOD);

    return 0;

}
