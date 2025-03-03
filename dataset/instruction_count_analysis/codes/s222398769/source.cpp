#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

const int inf=0x3f3f3f3f;

const int maxn=2e2+10;

int n,m,num;

int costl[maxn][maxn],costs[maxn][maxn];

int dp[1005][maxn];

int a[1005];

int main()

{

    while(scanf("%d%d",&n,&m)&&n&&m)

    {

        for(int i=1;i<=n;i++)

            for(int j=1;j<=n;j++)

            {

                if(i==j)

                {

                    costl[i][j]=costs[i][j]=0;

                }

                else

                {

                     costl[i][j]=costs[i][j]=inf/3;

                }

            }

        for(int i=1;i<=m;i++)

        {

            char s[2];

            int x,y,val;

            scanf("%d%d%d%s",&x,&y,&val,s);

            if(s[0]=='L')

            {

                costl[x][y]=costl[y][x]=min(val,costl[x][y]);

            }

            else

            {

                costs[x][y]=costs[y][x]=min(val,costs[x][y]);

            }

        }

        scanf("%d",&num);

        for(int i=1;i<=num;i++)

        {

            scanf("%d",&a[i]);

        }

        for(int k=1;k<=n;k++)

            for(int i=1;i<=n;i++)

                for(int j=1;j<=n;j++)

                {

                    costs[i][j]=min(costs[i][j],costs[i][k]+costs[k][j]);

                    costl[i][j]=min(costl[i][j],costl[i][k]+costl[k][j]);

                }

        memset(dp,0x3f,sizeof(dp));

        dp[1][a[1]]=0;

        for(int i=2;i<=num;i++)

            for(int j=1;j<=n;j++)

            {

                dp[i][j]=min(dp[i][j],dp[i-1][j]+costl[a[i-1]][a[i]]);

                for(int k=1;k<=n;k++)

                {

                    //dp[i][k]=min(dp[i][k],dp[i-1][j]+costl[a[i-1]][j]+costs[j][k]+costl[k][a[i]]);

                    dp[i][j]=min(dp[i][j],dp[i-1][k]+costl[a[i-1]][k]+costs[k][j]+costl[j][a[i]]);

                }

            }

        int ans=inf;

        for(int i=1;i<=n;i++)

        {

            ans=min(ans,dp[num][i]);

        }

        printf("%d\n",ans);

    }

}