#include<cstdio>

#include<vector>

#include<iostream>

#include<map>

#include<queue>

#include<algorithm>

#include<cstring>

#include<cmath>

#define eps 1e-10

#define inf 100000000

using namespace std;

int n,m,c;

struct node

{

    int t,cost;

    node(int t=0,int cost=0):t(t),cost(cost) {}

};

vector<node> G[105];

int d[105][105];

void spfa()

{

    queue<pair<int,int> > q;

    bool vis[105][105];

    for(int i=1;i<=n;i++)

    for(int j=0;j<=n;j++) d[i][j]=inf;

    d[1][0]=0;memset(vis,0,sizeof(vis));

    q.push(make_pair(1,0));

    while(!q.empty())

    {

        pair<int,int> p=q.front();q.pop();

        int x=p.first,y=p.second;

        vis[x][y]=0;

        for(int i=0;i<G[x].size();i++)

        {

            int v=G[x][i].t,co=G[x][i].cost;

            if(d[v][y]>d[x][y]+co)

            {

                d[v][y]=d[x][y]+co;

                if(!vis[v][y])

                {

                    vis[v][y]=1;

                    q.push(make_pair(v,y));

                }

            }

            if(y<n&&d[v][y+1]>d[x][y])

            {

                d[v][y+1]=d[x][y];

                if(!vis[v][y+1])

                {

                    vis[v][y+1]=1;

                    q.push(make_pair(v,y+1));

                }

            }

        }



    }

}

main()

{

    while(scanf("%d%d%d",&n,&m,&c),n+m+c)

    {

        memset(G,0,sizeof(G));

        for(int i=1;i<=m;i++)

        {

            int s,t,c;

            scanf("%d%d%d",&s,&t,&c);

            G[s].push_back(node(t,c));

        }

        spfa();

        int ans;

        for(int j=1;j<=n;j++)

        if(d[n][j]<=c) {ans=j;break;}

        cout<<ans<<endl;

    }

}