#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#define fo(i,l,r) for(int i=l;i<=r;i++)

#define of(i,l,r) for(int i=l;i>=r;i--)

#define fe(i,u) for(int i=head[u];i;i=e[i].next)

using namespace std;

typedef long long ll;

inline int rd()

{

    static int x,f;

    x=0,f=1;

    char ch=getchar();

    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;

    for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';

    return x*f;

}

const int N=200010,Inf=1000000000;

struct edge{

    int v,next;

    edge(int v=0,int next=0):v(v),next(next){}

}e[N<<1];

int n;ll ans=0;

int head[N],tot=0;

int mx[N],sx[N],mn[N],siz[N];

char s[N];



inline void add(int u,int v){e[++tot]=edge(v,head[u]);head[u]=tot;}



void dfs1(int u,int fat)

{

    if(s[u]=='1')mn[u]=0,siz[u]=1;

    else mn[u]=Inf;

    fe(i,u){

        int v=e[i].v;

        if(v==fat)continue;

        dfs1(v,u);siz[u]+=siz[v];

        int dis=mx[v]+1;

        if(mx[u]<dis)sx[u]=mx[u],mx[u]=dis;

        else sx[u]=max(sx[u],dis);

        if(siz[v])mn[u]=min(mn[u],dis);

    }

}

void dfs2(int u,int fat)

{

    int mxd=min(mx[u]-1,sx[u]+1);

    if(mxd>=mn[u])ans+=(ll)mxd-mn[u]+1;

    fe(i,u){

        int v=e[i].v;

        if(v==fat)continue;

        int dis=mx[u]==mx[v]+1?sx[u]+1:mx[u]+1;

        if(mx[v]<dis)sx[v]=mx[v],mx[v]=dis;

        else sx[v]=max(sx[v],dis);

        if(siz[v]<siz[1])mn[v]=min(mn[v],dis);

        dfs2(v,u);

    }

}



int main()

{

    n=rd();

    fo(i,1,n-1){

        int x=rd(),y=rd();

        add(x,y);add(y,x);

    }

    scanf("%s",s+1);

    dfs1(1,0);dfs2(1,0);

    printf("%lld\n",ans+1ll);

    return 0;

}