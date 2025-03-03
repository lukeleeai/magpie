# include <iostream>

# include <cstdio>

using namespace std;

const int N = 2e5 + 12;

const int inf = 0x3f3f3f3f;

int n,head[N],dt,du[N],bac[N],que[N],rt,a[N],tot,p;char str[N];bool w[N];

struct Edge{int to,nex;}edge[N << 1];

void Add(int u,int v){edge[++dt] = (Edge){v,head[u]};head[u] = dt;du[u]++;}

void Dfs(int u,int pre)

{

    if(str[u] == 'W')w[u] = true;

    for(int i = head[u];i;i = edge[i].nex)if(edge[i].to != pre)

    {

        Dfs(edge[i].to,u);

        if(!w[edge[i].to])du[u]--,du[edge[i].to]--;

        w[u] |= w[edge[i].to];

    }

    if(w[u])tot++;

}

void rebuild()

{

    for(int i = 1;i <= n;i++)if(str[i] == 'W')rt = i;

    Dfs(rt,-1);

    for(int i = 1;i <= n;i++)if(w[i])a[i] = (str[i] == 'B') ^ (du[i] & 1),p += !a[i];

}

int dp[N][2],f[N];

void dfs(int u,int pre)

{

    f[u] = (tot - 1) * 2 + p;

    dp[u][0] = a[u] ? -1 : 1;

    for(int i = head[u];i;i = edge[i].nex)if(edge[i].to != pre && w[edge[i].to])

    {

        dfs(edge[i].to,u);

        f[u] = min(f[u],f[edge[i].to]);

        f[u] = min(f[u],(tot - 1) * 2 + p - dp[u][0] - dp[edge[i].to][1] - 1);

        f[u] = min(f[u],(tot - 1) * 2 + p - dp[u][1] - dp[edge[i].to][0] - 1);

        dp[u][0] = max(dp[u][0],dp[edge[i].to][0] + 1 + (a[u] ? -1 : 1));

        dp[u][1] = max(dp[u][1],dp[edge[i].to][1] + 1 + (a[u] ? -1 : 1));

    }

}

int main()

{

    

    scanf("%d",&n);int x,y;

    for(int i = 1;i < n;i++)scanf("%d %d",&x,&y),Add(x,y),Add(y,x);

    scanf("%s",str + 1);rebuild();dfs(rt,-1);

    printf("%d\n",!tot ? tot : f[rt]);

}


