#include"stdc++.h"

using namespace std;

typedef long long ll;

const int max_n = 200005;

int n, c[max_n];

vector<int> G[max_n];

int cur[max_n], sz[max_n];

ll ans[max_n];

void dfs(int u, int fa) {

    int x = cur[c[u]];

    sz[u] = 1;

    for(auto v : G[u]) {

        if(v == fa) continue;

        int pre = cur[c[u]];

        dfs(v, u);

        sz[u] += sz[v];

        int suf = cur[c[u]];

        suf -= pre;

        int t = sz[v] - suf;

        ans[c[u]] -= 1ll * t * (t + 1) / 2;

    }

    x += sz[u];

    cur[c[u]] = x;

}

int main() {

    scanf("%d", &n);

    for(int i = 1; i<= n; i++) scanf("%d", c + i);

    for(int i = 1; i < n; i++) {

        int u, v; scanf("%d%d", &u, &v);

        G[u].push_back(v), G[v].push_back(u);

    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++) {

        int t = n - cur[i];

        ans[i] -= 1ll * t * (t + 1) / 2;

    }

    for(int i = 1; i <= n; i++) ans[i] += 1ll * n * (n + 1) / 2;

    for(int i = 1; i <= n; i++) printf("%lld\n", ans[i]);

    return 0;

}