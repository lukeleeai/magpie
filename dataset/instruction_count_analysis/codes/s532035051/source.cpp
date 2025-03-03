#include<stdio.h>

#include<string.h>

#include<math.h>

#include<iostream>

#include<algorithm>

#include<queue>

using namespace std;

int a[1000000];

long long sum[1000000];

bool vis[1000000];

int main()

{

    int n,m;

    scanf("%d%d",&n,&m);

    memset(vis,0,sizeof(vis));

    memset(a,0,sizeof(a));

    for(int i=1;i<=m;i++)

    {

        scanf("%d",&a[i]);

        vis[a[i]]=1;

    }

    if(vis[1]==1)

        sum[1]=0;

    else

        sum[1]=1;

    if(vis[2]==1)

        sum[2]=0;

    else

        sum[2]=sum[1]+1;

    for(int i=3;i<=n;i++)

    {

        if(vis[i-1]==0&&vis[i-2]==0)

            sum[i]=sum[i-1]%1000000007+sum[i-2]%1000000007;

        if(vis[i-1]==1&&vis[i-2]==0)

            sum[i]=sum[i-2]%1000000007;

        if(vis[i-1]==0&&vis[i-2]==1)

            sum[i]=sum[i-1]%1000000007;

        if(vis[i-1]==1&&vis[i-2]==1)

        {

            sum[n]==0;

            break;

        }

    }

    printf("%lld",sum[n]%1000000007);

        return 0;

}
