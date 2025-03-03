#pragma GCC optimize(3,"Ofast","inline")

#include"stdc++.h"

#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

#define ms(a,b) memset(a,b,sizeof(a))

#define msn(a,n,b) for(int i=0;i<=n;i++)a[i]=b

#define lson l,mid,rt<<1

#define rson mid+1,r,rt<<1|1

#define fi first

#define se second

using namespace std;

mt19937 rng_32(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

typedef long double ld;

typedef pair<int,int> P;

typedef double db;

const int mod=1e9+7;

const int seed=233;

const double PI=acos(-1.0);

const double eps=1e-7;

const int inf=0x3f3f3f3f;

const int max_n=200005;

ll ceil(ll x,ll y){if(x==0)return 0;if(y<0)x=-x,y=-y;bool sign=x>0;x=abs(x);return sign?(x+y-1)/y:-x/y;}

ll floor(ll x,ll y){if(x==0)return 0;if(y<0)x=-x,y=-y;bool sign=x>0;x=abs(x);return sign?x/y:-(x+y-1)/y;}

namespace {

    inline int Add(int x,int y){return (x+=y)>=mod?x-mod:x;}

    inline int Sub(int x,int y){return (x-=y)<0?x+mod:x;}

    inline int Mul(int x,int y) {return 1ll*x*y%mod;}

    inline int Pow(int x,int y=mod-2){if(y==0)return 1;int res=1;while(y){if(y&1)res=1ll*res*x%mod;x=1ll*x*x%mod;y>>=1;}return res;}

}

/**********************head************************/

int n, c[max_n];

vector<int> G[max_n];

int sz[max_n];

bool big[max_n];

ll ans[max_n];

int par[max_n];

void dfs1(int u,int fa)

{

    sz[u]=1;

    for(auto v:G[u])

    {

        if(v==fa)continue;

        par[v] = u;

        dfs1(v,u);

        sz[u]+=sz[v];

    }

}

int cur[max_n];

bool vis[max_n];

void add(int u,int fa,int val)

{

    bool f = false;

    if(!vis[c[u]]){

        f = true;

        vis[c[u]] = true;

        cur[c[u]] += val * sz[u];

    }

    for(auto v:G[u])

    {

        if(v==fa||big[v])continue;

        add(v,u,val);

    }

    if(f)vis[c[u]] = false;

}

void dfs(int u,int fa,bool keep)

{

    int mx=-1,son=-1;

    for(auto v:G[u])

    {

        if(v==fa)continue;

        if(sz[v]>mx)mx=sz[v],son=v;

    }

    for(auto v:G[u])

    {

        if(v==fa||v==son)continue;

        dfs(v,u,0);

    }

    if(~son)dfs(son,u,1),big[son]=1;

    //vis[c[u]]=true,cur[c[u]] = sz[u];

    cur[c[u]] = 0;

    add(u,fa,1);

    int x=c[par[u]];

    if(par[u]){

        ll y = sz[u] - cur[x];

        ans[x] += 1ll* y*(y+1)/2;

    }

    if(~son)big[son]=0;

    if(!keep)add(u,fa,-1);

}

int main() {

    scanf("%d", &n);

    for(int  i = 1; i <= n; i++ )scanf("%d",c + i);

    for(int i = 1; i < n; i++) {

        int u, v; scanf("%d%d", &u, &v);

        G[u].push_back(v), G[v].push_back(u);

    }

    dfs1(1,0);

    dfs(1,0,1);

    for(int i = 1; i <= n; i++) ans[i] += 1ll * (n - cur[i]) * ( n -cur[i] + 1) /2;

    for(int i = 1; i <= n; i++) printf("%lld\n", 1ll*n*(n+1)/2 -ans[i]);

    return 0;

}