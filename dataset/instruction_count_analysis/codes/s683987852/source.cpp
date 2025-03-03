//#include "stdc++.h"

#include <cstdio>

#include <vector>

using namespace std;



const int N = 100000 + 5;



int n, s, t, d;

vector<int> g[N];



void dfs(int x, int fa, int dis, int &point) {

    if (dis > d) {

        d = dis;

        point = x;

    }

    for (int i = 0; i < g[x].size(); ++i) {

        int y = g[x][i];

        if (y == fa) continue;

        dfs(y, x, dis + 1, point);

    }

}



vector<int> path;

bool color[N];



bool find_path(int x, int fa) {

    path.push_back(x); color[x] = true;

    if (x == t) return true;

    for (int i = 0; i < g[x].size(); ++i) {

        int y = g[x][i];

        if (y == fa) continue;

        if (find_path(y, x)) return true;

    }

    path.pop_back(), color[x] = false;

    return false;

}



bool vis[N];

int cnt[N];

int ans1[N], ans2[N];



int main() {

    scanf("%d", &n);

    for (int i = 1, a, b; i < n; ++i) {

        scanf("%d%d", &a, &b);

        g[a].push_back(b), g[b].push_back(a);

    }

    dfs(1, 0, 0, s), d = 0, dfs(s, 0, 0, t);

    find_path(s, 0);

    for (int i = 0; i < path.size(); ++i) {

        int x = path[i];

        for (int j = 0; j < g[x].size(); ++j) {

            int y = g[x][j];

            vis[y] = true;

            if (!color[y]) ++cnt[i];

        }

    }

    for (int i = 1; i <= n; ++i) if (!vis[i]) { puts("-1"); return 0; }

    int pos = 1, id = 1;

    for (int i = 0; i < path.size(); ++i) {

        for (int j = 1; j <= cnt[i]; ++j)

            ans1[pos++] = id + j;

        ans1[pos++] = id;

        id += cnt[i] + 1;

    }

    pos = 1, id = 1;

    for (int i = path.size() - 1; i >= 0; --i) {

        for (int j = 1; j <= cnt[i]; ++j)

            ans2[pos++] = id + j;

        ans2[pos++] = id;

        id += cnt[i] + 1;

    }

    int t = 1;

    for (int i = 1; i <= n; ++i) if (ans1[i] < ans2[i]) { t = 1; break; } else if (ans1[i] > ans2[i]) { t = 2; break; }

    if (t == 1) for (int i = 1; i <= n; ++i) printf("%d%c", ans1[i], i == n ? '\n' : ' ');

    else for (int i = 1; i <= n; ++i) printf("%d%c", ans2[i], i == n ? '\n' : ' ');

    return 0;

}
