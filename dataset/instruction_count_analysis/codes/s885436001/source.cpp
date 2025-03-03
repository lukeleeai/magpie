#include"stdc++.h"

using namespace std;



#define int long long

typedef vector<int>vint;

typedef pair<int,int>pint;

typedef vector<pint>vpint;

#define rep(i,n) for(int i=0;i<(n);i++)

#define reps(i,f,n) for(int i=(f);i<(n);i++)

#define all(v) (v).begin(),(v).end()

#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

#define pb push_back

#define fi first

#define se second

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}

template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}



int N,M;

vint G[111111];

bool vis[111111];

int ord[111111],low[111111];

vpint bridge;

void dfs(int v,int p,int &k){

    ord[v]=k++;

    low[v]=ord[v];

    vis[v]=true;

    for(auto u:G[v]){

        if(vis[u]){

            if(u!=p)chmin(low[v],ord[u]);

        }

        else{

            dfs(u,v,k);

            if(ord[v]<low[u])bridge.pb({min(v,u),max(v,u)});

            chmin(low[v],low[u]);

        }

    }

}



signed main(){

    cin>>N>>M;

    rep(i,M){

        int a,b;cin>>a>>b;

        G[a].pb(b);G[b].pb(a);

    }

    int k=0;dfs(0,-1,k);

    sort(all(bridge));

    rep(i,bridge.size())cout<<bridge[i].fi<<" "<<bridge[i].se<<endl;

}