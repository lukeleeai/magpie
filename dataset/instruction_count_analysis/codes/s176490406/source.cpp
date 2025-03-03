#include "stdc++.h"



#define int long long



using namespace std;



const int N = 100005;

vector <pair <int, int> > g[N];

vector <int> all, temp[N], pref_all, pref_temp[N];

int dp[N], ans[N], dist[N];

bool visited[N];



void dfs (int u, int p) {

    dp[u] = 1;

    for (int i = 0; i < g[u].size(); i++) {

        int v = g[u][i].first;

        if (v != p && !visited[v]) {

            dfs(v, u);

            dp[u] += dp[v];

        }

    }

}



int find_centroid (int u, int p, int sz) {

    for (int i = 0; i < g[u].size(); i++) {

        int v = g[u][i].first;

        if (v != p && !visited[v] && dp[v] > sz/2) return find_centroid(v, u, sz);

    }



    return u;

}



void redfs (int u, int p, int val, int branch) {

    all.push_back(val);

    temp[branch].push_back(val);



    dist[u] = val;

    for (int i = 0; i < g[u].size(); i++) {

        int v = g[u][i].first;

        if (v == p || visited[v]) continue;



        redfs(v, u, min(val,g[u][i].second), branch);

    }

}



void cal (int u, int p, int branch) {

    int pos_all = upper_bound(all.begin(), all.end(), dist[u]) - all.begin();

    int pos_temp = upper_bound(temp[branch].begin(), temp[branch].end(), dist[u]) - temp[branch].begin();

    ans[u] = ans[u] + pref_all[pos_all - 1] - pref_temp[branch][pos_temp - 1];



    pos_all = (int)all.size() - pos_all;

    pos_temp = (int)temp[branch].size() - pos_temp;

    ans[u] = ans[u] + (pos_all - pos_temp + 1) * dist[u];



    for (int i = 0; i < g[u].size(); i++) {

        int v = g[u][i].first;

        if (visited[v] || v == p) continue;



        cal(v, u, branch);

    }

}



void centroid (int root) {

    dfs(root, root);



    if(dp[root] == 1) return;

    int cen = find_centroid(root, root, dp[root]);

    visited[cen] = true;



    all.clear();

    pref_all.clear();

    for (int i = 0; i < g[cen].size(); i++) {

        int v = g[cen][i].first;

        if (visited[v]) continue;



        temp[v].clear();

        pref_temp[v].clear();

        redfs(v, cen, g[cen][i].second, v);

    }



    sort(all.begin(), all.end());

    pref_all.push_back(all[0]);

    for (int i = 1; i < all.size(); i++) pref_all.push_back(all[i] + pref_all[pref_all.size() - 1]);

    for (int i = 0; i < g[cen].size(); i++) {

        int v = g[cen][i].first;

        if (visited[v]) continue;



        sort(temp[v].begin(), temp[v].end());

        for (int j = 0; j < temp[v].size(); j++) {

            if (j == 0) pref_temp[v].push_back(temp[v][0]);

            else pref_temp[v].push_back(temp[v][j] + pref_temp[v][pref_temp[v].size() - 1]);

        }



        cal(v, cen, v);

    }



    ans[cen] += pref_all[pref_all.size() - 1];

    for (int i = 0; i < g[cen].size(); i++) {

        int v = g[cen][i].first;

        if (!visited[v]) centroid(v);

    }

}



signed main(){

    int n;

    scanf("%lld", &n);

    for (int i = 1; i <= n - 1; i++) {

        int u, v, w;

        scanf("%lld %lld %lld", &u, &v, &w);

        g[u].push_back(make_pair(v, w));

        g[v].push_back(make_pair(u, w));

    }



    memset(visited, 0, sizeof(visited));

    memset(ans, 0, sizeof(ans));

    centroid(1);



    for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);



    //cout << "dist " << dist[2] << "\n";

    //for (int i = 0; i < all.size(); i++) cout << all[i] << " ";

    //for (int i = 0; i < temp[2].size(); i++) cout << temp[2][i] << " ";

    //cout << dist[1] << " " << dist[2] << " " << dist[3];

    return 0;

}



/*

4

1 2 10

2 3 20

1 4 10

*/
