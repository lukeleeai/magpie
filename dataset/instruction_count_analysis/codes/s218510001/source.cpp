#include"stdc++.h"

using namespace std;

typedef long long LL;

const int MAXN = 1000005;

struct node

{

    int from, to, w;

} G[MAXN];

int dist[MAXN];

int head[MAXN];

bool vis[MAXN];

int cnt;

void add(int u, int v, int w)

{

    G[cnt].to=v;

    G[cnt].w=w;

    G[cnt].from=head[u];

    head[u]=cnt++;

}

void spfa(int s)

{

    memset(vis, false, sizeof(vis));

    queue<int> q;

    while(!q.empty())

        q.pop();

    vis[1]=true;

    q.push(s);

    dist[s]=0;

    while(!q.empty())

    {

        int u=q.front();

        q.pop();

        vis[u]=false;

        for(int i=head[u]; ~i; i=G[i].from)

        {

            int v=G[i].to;

            if(dist[v]>dist[u]+G[i].w)

            {

                dist[v]=dist[u]+G[i].w;

                if(!vis[v])

                {

                    vis[v]=true;

                    q.push(v);

                }

            }

        }

    }

}

int main()

{

    int k;

    scanf("%d", &k);

    memset(head, -1, sizeof(head));

    memset(dist, 0x3f,sizeof(dist));

    cnt=0;

    for(int i=0; i<k; ++i)

    {

        add(i,(i+1)%k, 1);

        add(i, i*10%k, 0);

    }

    spfa(1);

    printf("%d\n", dist[0]+1);

    return 0;

}


