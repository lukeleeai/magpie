#include "stdc++.h"

using namespace std;



const int maxn = 100 * 1000 + 20;

int n, m, dis[maxn];

vector <int> adj[maxn], adjexit[maxn];

bool vis[maxn];



void input() {

    cin >> n >> m;

    for (int i = 0, a, b; i < m; i++) {

        cin >> a >> b;

        adj[a].push_back(b);

        adj[b].push_back(a);

    }

}



void dfs(int v) {

    vis[v] = 1;

    for (int u : adj[v]) {

        if (!vis[u]) {

            dis[u] = dis[v] + 1;

            dfs(u);

            adjexit[u].size() % 2? adjexit[u].push_back(v): adjexit[v].push_back(u);

        }

        else if (dis[v] < dis[u])

            adjexit[v].push_back(u);

    }

}

void output() {

    for (int i = 1; i <= n; i++)

        for (int j : adjexit[i])

            cout << i << ' ' << j << endl;

}

int main() {    

    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    input();

    if (m % 2)

        return cout << -1 << endl, 0;

    dfs(1);

    output();

    return 0;    

}


