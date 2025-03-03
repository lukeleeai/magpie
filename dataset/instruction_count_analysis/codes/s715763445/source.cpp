#include<iostream>

#include<cstdio>

const int N=1e5+5;

int n,cnt,head[N],nxt[N<<1],to[N<<1],deg[N];

void init() {

    for(int i=0;i<n;i++) head[i]=-1,deg[i]=0;cnt=0;

}

void addEdge(int u,int v) {

    nxt[cnt]=head[u];to[cnt]=v;head[u]=cnt++;

}

int dfs(int u,int fa) {

    int ans=0;bool f=false;

    for(int i=head[u];~i;i=nxt[i]) {

        int v=to[i];if(v==fa) continue;

        int tmp=dfs(v,u);

        ans+=tmp?tmp:f;

        f=f||!tmp;

    }

    return ans;

}

int main() {

    scanf("%d",&n);init();int u,v;

    for(int i=1;i<n;i++) scanf("%d%d",&u,&v),addEdge(u,v),addEdge(v,u),deg[v]++,deg[u]++;

    int root=-1;

    for(int i=0;i<n;i++) if(deg[i]>2) root=i;

    printf("%d\n",root==-1?1:dfs(root,-1));

    return 0;

}
