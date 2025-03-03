#include"stdc++.h"

#define ll long long int

using namespace std;

ll N, i, a[110001], u, v, w, visited[100010], dist[100010];

vector<int>Adj[100010], W[100010];

void dfs(ll v)

{

    visited[v] = 1;

    for(ll i=0;i<Adj[v].size();i++)

    {

        ll u = Adj[v][i];

        if(!visited[u])

        {

            dist[u] = dist[v] + W[v][i];

            dfs(u);

        }

    }

}

int main()

{

    cin >> N;

    for(i=0;i<N-1;i++)

    {

        cin >> u >> v >> w;

        Adj[u].push_back(v);

        Adj[v].push_back(u);

        W[u].push_back(w);

        W[v].push_back(w);

    }

    dfs(1);

    for(i=1;i<=N;i++)

        cout << dist[i]%2 << endl;

    return 0;

}
