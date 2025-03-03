#include "stdc++.h"

#define F first

#define S second

#define pii pair<int,int>

#define pb push_back

typedef long long ll;

const int N = 3 * 1e5 + 10;

using namespace std;

vector<int> adj[N];

bool dp[N]; int e[N];



void dfs(int v , int p = 0){

    for(auto u : adj[v]){

        if(u == p)continue;

        dfs(u , v);

        if(e[u] < e[v] && !dp[u])dp[v] = true;

    }

}



int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for(int i=1;i<=n;i++)cin >> e[i];

    for(int i=0;i<n-1;i++){

        int u , v; cin >> u >> v;

        adj[u].pb(v);

        adj[v].pb(u);

    }

    for(int i=1;i<=n;i++){

        memset(dp , 0 , sizeof dp);

        dfs(i);

        if(dp[i])cout << i << ' ';

    }cout << '\n';

}
