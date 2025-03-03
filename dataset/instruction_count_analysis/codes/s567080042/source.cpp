// =================================

//   author: M_sea

//   website: http://m-sea-blog.com/

// =================================

#include <algorithm>

#include <iostream>

#include <cstdlib>

#include <cstring>

#include <cstdio>

#include <cmath>

#include <queue>

#define re register

using namespace std;



inline int read() {

    int X=0,w=1; char c=getchar();

    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }

    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();

    return X*w;

}



const int N=2000+10;



struct Edge { int v,nxt; } e[N];

int head[N];



inline void addEdge(int u,int v) {

    static int cnt=0;

    e[++cnt]=(Edge){v,head[u]},head[u]=cnt;

}



int n;

int a[N],vis[N],deg[N];

int G[N][N];



inline void dfs(int u) {

    vis[u]=1;

    for (re int i=1;i<=n;++i) {

        if (vis[i]||!G[u][i]) continue;

        ++deg[i],addEdge(u,i);

        dfs(i);

    }

}



inline void topsort() {

    priority_queue<int> Q;

    for (re int i=1;i<=n;++i)

        if (!deg[i]) Q.push(i);

    while (!Q.empty()) {

        int u=Q.top(); Q.pop();

        printf("%d ",a[u]);

        for (re int i=head[u];i;i=e[i].nxt) Q.push(e[i].v);

    }

}



int main() {

    n=read();

    for (re int i=1;i<=n;++i) a[i]=read();

    sort(a+1,a+n+1);

    for (re int i=1;i<=n;++i)

        for (re int j=i+1;j<=n;++j) {

            if (__gcd(a[i],a[j])==1) continue;

            G[i][j]=G[j][i]=1;

        }

    for (re int i=1;i<=n;++i)

        if (!vis[i]) dfs(i);

    topsort();

    return 0;

}