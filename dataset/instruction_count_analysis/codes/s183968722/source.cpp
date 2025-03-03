#include"stdc++.h"

using namespace std;

#define INF 0x3f3f3f3f;

long long a,b,v,i,n,m,k,l,an[100010],ans=0,vis[10000],j;

long long ma[600][600],dist[6000],S,vis2[610][610],vis3[6000];

int flag=0;

void dijkstra(long long x)

{//printf("ok\n");

    for(i=1; i<=n; i++)

        dist[i]=(i==x)?0:INF;

    memset(vis,0,sizeof(vis));

   memset(vis3,0,sizeof(vis3));

    for(i=1; i<=n; i++)

    {

        int mark=-1,mindis=INF;

        for(j=1; j<=n; j++)

        {

            if(!vis[j]&&dist[j]<mindis)

            {

                mindis=dist[j];

                mark=j;

            }

        }

        vis[mark]=1;

        for(int j=1; j<=n; j++)

        {

            if(!vis[j])

            {

                if(dist[j]>=(dist[mark]+ma[mark][j])&&mark!=x&&mark!=j) {vis3[j]=1;}

                dist[j]=min(dist[j],dist[mark]+ma[mark][j]);

            }

        }

    }

    for(i=1; i<=n; i++)

    {  //printf("*%lld*",vis3[i]);

        if(dist[i]<=ma[x][i])

        {

            if(vis3[i]==1){vis2[x][i]=1;vis2[i][x]=1;}

            if(dist[i]<ma[x][i])

            {

                flag=1;

            }

        }

    }

   //printf("\n");

}

int main()

{

    scanf("%lld",&n);

    for(i=1; i<=n; i++)

    {

        for(j=1; j<=n; j++)

        {

            scanf("%lld",&ma[i][j]);

        }



    }

    ans=0;

    flag=0;



    for(l=1; l<=n; l++)

    {

        dijkstra(l);

        if(flag==1) break;

    }

    if(flag==0)

    {

        for(i=1; i<=n; i++)



        {

            for(j=i+1; j<=n; j++)

            {

                if(vis2[i][j]!=1) ans+=ma[i][j];

            }

        }

        printf("%lld\n",ans);

    }

    else printf("-1\n");

    return 0;

}


