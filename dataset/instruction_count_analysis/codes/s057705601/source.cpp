#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

typedef long long ll;

const int N=2e6+5;

struct node{

    int u,v,nxt;

}edge[N];

int head[N],mcnt;

void add_edge(int u,int v){

    mcnt++;

    edge[mcnt].u=u;

    edge[mcnt].v=v;

    edge[mcnt].nxt=head[u];

    head[u]=mcnt;

}

int g[N];

int SG(int u,int fa=0){

    g[u]=0;

    for(int i=head[u];i;i=edge[i].nxt){

        int v=edge[i].v;

        if(v==fa)

            continue ;

        g[u]^=SG(v,u)+1;

    }

    return g[u];

}

int n;

int main()

{

    scanf("%d",&n);

    for(int i=1;i<n;i++){

        int u,v;

        scanf("%d%d",&u,&v);

        add_edge(u,v);

        add_edge(v,u);

    }

    puts(SG(1)?"Alice":"Bob");

}
