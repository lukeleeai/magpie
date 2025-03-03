#include "stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)

long long mo = 1e9 + 7;

typedef long long ll;

typedef long double ld;

typedef pair<int,int> Pii;

typedef pair<ll,ll> Pll;

template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }

template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}

ld PI=3.14159265358979323846;



vector<vector<ll>> G(100010);

vector<ll> memo(100010,-1), dist(100010,1e18), memo2(100010,-1), dist2(100010,1e18);

ll N,u,v;



ll dfs(ll vv){

    for(auto& uu:G[vv]){

        if(memo[uu] != -1) continue;

        memo[uu] = vv;

        dist[uu] = dist[vv] + 1;

        if(uu == v) continue;

        dfs(uu);

    }

    return 0;

}

ll dfs2(ll vv){

    for(auto& uu:G[vv]){

        if(memo2[uu] != -1) continue;

        memo2[uu] = vv;

        dist2[uu] = dist2[vv] + 1;

        dfs2(uu);

    }

    return 0;

}



int main(){

    cin >> N >> u >> v;

    u--;v--;

    ll a,b;

    rep(i,N-1){

        cin >> a >> b;

        a--;b--;

        G[a].push_back(b);

        G[b].push_back(a);

    }

    memo[u] = -2;

    dist[u] = 0;

    dfs(u);

    ll diff = dist[v];

    ll t = v;

    while(t != u){

        dist[t] = 1e18;

        t = memo[t];

    }

    /*

    ll M = 0;

    ll Mt = -1;

    rep(i,N){

        if(dist[i]==1e18) continue;

        if(M < dist[i]){

            M = dist[i];

            Mt = i;

        }

    }*/

    memo2[v] = -2;

    dist2[v] = 0;

    dfs2(v);

    ll M = 0;

    rep(i,N){

        if(dist[i] != 1e18 && dist[i] < dist2[i]){

            cmax(M,dist2[i]);

        }

    }

    /*

    memo = vector<ll>(N,-1);

    dist = vector<ll>(N,1e18);

    dfs(v, -2);*/

    //ll ans = M + diff - 1;

    cout << M - 1 << endl;

}