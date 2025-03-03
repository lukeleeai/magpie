#include <cstdio>

#define N 100005

int n;

struct edge{

    int to,next;

}e[N<<1];

int head[N],cnt;

void add(int u,int v){

    e[++cnt]=(edge){v,head[u]};

    head[u]=cnt;

}

int son[N];

int path[N],len;

bool dfs(int x,int fa){

    bool p=x==n;

    for(int i=head[x];i;i=e[i].next){

        int v=e[i].to;

        if(v==fa)continue;

        p|=dfs(v,x);

    }

    son[fa]+=son[x]+1;

    if(p){

        path[++len]=x;

        return true;

    }

    return false;

}

int main(){

    scanf("%d",&n);

    for(int i=1,u,v;i<n;++i){

        scanf("%d%d",&u,&v);

        add(u,v);add(v,u);

    }

    dfs(1,0);

    int ans=0;

    for(int i=len;i>len/2;--i)

        ans+=son[path[i]]-son[path[i-1]];

    printf("%s\n",ans*2>n?"Fennec":"Snuke");

    return 0;

}
