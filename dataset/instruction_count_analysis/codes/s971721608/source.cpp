#include "stdc++.h"

using namespace std;

using ll=long long;

using pii=pair<int,int>;

#define F first

#define S second

#define sz(x) int(x.size())

#define pb push_back



int mod,n;

vector<vector<int>> G;

vector<ll> res,ans;

void dfs1(int u,int fa){

    res[u]=1;

    for(auto to:G[u]){

        if(to==fa) continue;

        dfs1(to,u);

        (res[u]*=ll(res[to]+1))%=mod;

    }

}

void dfs2(int root,int fa,ll now){

    ans[root]=((now+1)*res[root])%mod;

    vector<pair<ll,int>> pre,suf;

    for(auto to:G[root]){

        if(to==fa) continue;

        pre.pb({res[to]+1,to});

        suf.pb({res[to]+1,to});

    }

    for(int i=1;i<sz(pre);i++) (pre[i].F*=ll(pre[i-1].F))%=mod;

    for(int i=sz(suf)-2;i>=0;i--) (suf[i].F*=ll(suf[i+1].F))%=mod;

    for(int i=0;i<sz(pre);i++){

        ll l=(i==0?1:pre[i-1].F),r=(i==sz(pre)-1?1:suf[i+1].F);

        dfs2(pre[i].S,root,l*r%mod*(now+1)%mod);

    }

}

int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cin>>n>>mod;

    G.resize(n+1);

    res.resize(n+1);

    ans.resize(n+1);

    for(int i=0;i<n-1;i++){

        int x,y;

        cin>>x>>y;

        G[x].push_back(y);

        G[y].push_back(x);

    }

    dfs1(1,0);

    dfs2(1,0,0);

    for(int i=1;i<=n;i++){

        cout<<ans[i]<<endl;

    }

    return 0;

}


