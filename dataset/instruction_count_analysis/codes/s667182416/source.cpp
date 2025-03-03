#include<stdio.h>

int main()

{

    int n,m,vis[200001];

    while(scanf("%d%d",&n,&m)!=EOF)

    {

        int u,v;

        bool flag=false;

        for(int i=1;i<=n;i++)

            vis[i]=false;

        for(int i=1;i<=m;i++)

        {

            scanf("%d%d",&u,&v);

            if(flag) continue;

            if(u==1)

            {

                if(vis[v])

                {

                    flag=true;

                }

                vis[v]=true;

            }else if(v==n)

            {

                if(vis[u])

                {

                    flag=true;

                }

                vis[u]=true;

            }

        }

        if(flag) printf("POSSIBLE\n");

        else printf("IMPOSSIBLE\n");

        break;

    }

    return 0;

}