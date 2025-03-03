#include"stdc++.h"

#define ll long long

using namespace std;

inline int read(){

    int s=0,w=1;

    char ch=getchar();

    while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}

    while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}

    return s*w;

}

const int maxn=1e5+10;

struct edge{

    int to,nxt;

}e[maxn*2];

int head[maxn],tot,col[maxn];

ll c1,c2;

int flag;

void addedge(int u,int v){

    e[++tot].to=v;

    e[tot].nxt=head[u];

    head[u]=tot;

}

void dfs(int u,int color){

    if(flag) return;

    col[u]=color;

    if(color==1) ++c1;

    else ++c2;

    for(int i=head[u];i;i=e[i].nxt)

    {

        int v=e[i].to;

        if(!col[v]) dfs(v,3-color);

        else if(col[v]==color){

            flag=true;

            return;

        }

    }

}

ll n,m;

int main(){

    n=read(),m=read();

    for(int i=1;i<=m;i++){

        int u,v;

        u=read(),v=read();

        addedge(u,v);

        addedge(v,u);

    }

    dfs(1,1);

    if(flag) printf("%lld",1LL*n*(n-1)/2-m);

    else printf("%lld",c1*c2-m);



    return 0;

}