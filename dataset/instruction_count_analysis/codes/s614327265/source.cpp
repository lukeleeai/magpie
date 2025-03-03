#include"stdc++.h"

using namespace std;

const int N = 1e5 + 100;

int p[N],disc[N],low[N],vis[N],ap[N],wmy,n,m;

vector<int> g[N];

void dfs(int u) {

    int children = 0;

    vis[u] = true;

    disc[u] = low[u] = ++wmy;

    for(int &v: g[u]) {

        if(!vis[v]) {

            children++;p[v] = u;

            dfs(v);

            low[u] = min(low[u],low[v]);

            if(p[u] == -1 && children > 1) ap[u] = true;

            else if(p[u]!=-1 && low[v] >= disc[u]) ap[u] = true;



        }

        else if(v != p[u]) low[u] = min(low[u],disc[v]);

    }

}

int main() {

    scanf("%d%d",&n,&m);

    memset(vis,0,sizeof(vis));

    memset(low,0,sizeof(low));

    memset(ap,0,sizeof(ap));

    memset(p,0,sizeof(p));

    wmy = 0;

    for(int i = 0;i < N;i++) g[i].clear();

    for(int i = 1;i <= m;i++) {

        int u,v;

        scanf("%d%d",&u,&v);

        g[u].push_back(v);

        g[v].push_back(u);

    }

    p[0] = -1;

    dfs(0);

    for(int i = 0;i < n;i++) if(ap[i]) printf("%d\n",i);

} 
