#include"stdc++.h"

//#pragma GCC optimize("O3")

//#pragma GCC target ("sse4")

using namespace std;

#define PB push_back

#define all(x) (x).begin(),(x).end()

#define MEM(x,a) memset((x),a,sizeof((x)))

#define F first

#define S second

#define imx INT_MAX

#define inI(x) scanf("%d",&x)

#define inI2(x,y) scanf("%d %d",&x,&y)

#define inI3(x,y,z) scanf("%d %d %d",&x,&y,&z)

const long long MOD = (long long)(1e9+7);

const long long MMX = (long long)(1e18);

typedef long long LL;

long long n,w,val[105],ww[105],k=MMX,dp[105][1000],ans=0;

int main()

{

    for(int i=0;i<105;i++)for(int j=0;j<1000;j++)dp[i][j]=-1;

    dp[0][0]=0;

    scanf("%lld %lld",&n,&w);

    for(int i=1;i<=n;i++)

    {

        scanf("%lld %lld",&ww[i],&val[i]);

        k=min(k,ww[i]);

    }

    for(int i=1;i<=n;i++)ww[i]-=k;

    for(int t=1;t<=n;t++)

    {

        for(int i=100;i>=0;i--)

        {

            for(int j=1000;j>=0;j--)

            {

                if(dp[i][j]!=-1)

                {

                    dp[i+1][j+ww[t]]=max(dp[i+1][j+ww[t]],dp[i][j]+val[t]);

                }

            }

        }

    }

    for(int i=0;i<105;i++)for(int j=0;j<1000;j++)if(((i*k)+j)<=w)ans=max(ans,dp[i][j]);

    printf("%lld",ans);

}
