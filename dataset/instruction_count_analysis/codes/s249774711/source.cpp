#include<cstdio>

#include<cstring>

#include<algorithm>

#include<queue>

using namespace std;

const int N=1000000+5;

typedef long long ll;

struct node{

    int u,v,nxt;

}edge[N*2];

int head[N],mcnt;

int du[N];

void add_edge(int u,int v){

    mcnt++;

    edge[mcnt].u=u;

    edge[mcnt].v=v;

    edge[mcnt].nxt=head[u];

    head[u]=mcnt;

    du[u]++;

}

ll I,P,Q;

bool tag[N];

bool vis[N];

bool flag;

void dfs(int u){

    vis[u]=1;

    for(int i=head[u];i;i=edge[i].nxt){

        int v=edge[i].v;

        if(!vis[v]){

            tag[v]=tag[u]^1;

            dfs(v);

        }

        else

            if(tag[u]==tag[v])

                flag=false;

    }

}

int main()

{

    int n,m;

    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++){

        int u,v;

        scanf("%d%d",&u,&v);

        add_edge(u,v);

        add_edge(v,u);

    }

    for(int i=1;i<=n;i++){

        if(vis[i])

            continue;

        if(du[i]==0){

            I++;

            continue;

        }

        flag=true;

        dfs(i);

        if(flag)

            Q++;

        else

            P++;

    }

    ll ans=1ll*2*I*n-1ll*I*I+1ll*P*P+2ll*P*Q+2ll*Q*Q;//

    printf("%lld\n",ans);

}
