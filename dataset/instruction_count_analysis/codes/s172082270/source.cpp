// ===================================

//   author: M_sea

//   website: https://m-sea-blog.com/

// ===================================

#include "stdc++.h"

using namespace std;

typedef long long ll;

 

int read() {

    int X=0,w=1; char c=getchar();

    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }

    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();

    return X*w;

}

 

const int N=50+10;

 

struct edge { int v,nxt; } e[N];

int head[N];

void addEdge(int u,int v) {

    static int cnt=0;

    e[++cnt]=(edge){v,head[u]},head[u]=cnt;

}

 

int n,X,d;

struct node { ll v; int w,id; } a[N];

int operator <(node a,node b) { return a.w*b.v>b.w*a.v; }

ll dp[N*N*N];

 

void dfs(int u) {

    a[u].w=1,a[u].id=u;

    for (int i=head[u];i;i=e[i].nxt)

        dfs(e[i].v),a[u].v+=a[e[i].v].v,a[u].w+=a[e[i].v].w;

}

 

int main() {

    n=read(),X=read(),d=read();

    a[1].v=read();

    for (int i=2;i<=n;++i)

        a[i].v=read(),addEdge(read(),i);

    dfs(1); int mx=n*n*n,L=min(n,d);

    memset(dp,0x3f,sizeof(dp)),dp[0]=0;

    for (int i=1;i<=n;++i) {

        int x=L;

        for (int j=0;1<<j<=x;++j) {

            int w=a[i].w*(1<<j); ll v=a[i].v*(1<<j);

            for (int k=mx;k>=w;--k) dp[k]=min(dp[k],dp[k-w]+v);

            x-=1<<j;

        }

        if (x) {

            int w=a[i].w*x; ll v=a[i].v*x;

            for (int j=mx;j>=w;--j) dp[j]=min(dp[j],dp[j-w]+v);

        }

    }

    sort(a+1,a+n+1);

    while (a[n].id!=1) --n;

    ll ans=0;

    for (int i=0;i<=mx;++i) {

        if (dp[i]>X) continue;

        ll w=i,v=dp[i];

        for (int j=1;j<n;++j) {

            ll c=min((ll)d-L,(X-v)/a[j].v);

            w+=c*a[j].w,v+=c*a[j].v;

        }

        ll c=(X-v)/a[n].v;

        w+=c*a[n].w,v+=c*a[n].v;

        ans=max(ans,w);

    }

    printf("%lld\n",ans);

    return 0;

}