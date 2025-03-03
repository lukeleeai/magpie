#include<cstdio>

#include<cstring>

#include<algorithm>

#include<deque>

using namespace std;

const int N=2e5+5;

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

bool vis[N];

int check(int u){

    for(int i=head[u];i;i=edge[i].nxt){

        int v=edge[i].v;

        if(!vis[v])

            return v;

    }

    return -1;

}

int n,m;

deque<int>q;

int main()

{

    scanf("%d%d",&n,&m);

    int u,v;

    for(int i=1;i<=m;i++){

        scanf("%d%d",&u,&v);

        add_edge(u,v);

        add_edge(v,u);

    }

    q.push_back(u);

    q.push_back(v);

    vis[u]=1;

    vis[v]=1;

    while(1){

        u=check(q.front());

        if(u==-1)

            break;

        vis[u]=1;

        q.push_front(u);

    }

    while(1){

        v=check(q.back());

        if(v==-1)

            break;

        vis[v]=1;

        q.push_back(v);

    }

    printf("%d\n",q.size());

    while(!q.empty()){

        printf("%d ",q.front());

        q.pop_front();

    }

}
