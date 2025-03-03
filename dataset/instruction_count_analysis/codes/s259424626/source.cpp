#include <cstdio>

#include <iostream>

#include <vector>

using namespace std;

const int N = 5010, mod = 1e9 + 7;

int n, x, y, dp[N][N], siz[N], tmp[N], g[N];

vector<int> G[N];

void dfs(int u, int fa) {

    siz[u] = 1; 

    dp[u][1] = 1;

    for(auto v : G[u]) {

        if(v == fa) continue;

        dfs(v, u);

        for(int i = 1; i <= siz[u] + siz[v]; ++i) tmp[i] = 0;

        for(int i = 1; i <= siz[u]; ++i)

            for(int j = 0; j <= siz[v]; ++j)

                (tmp[i + j] += 1ll * dp[u][i] * dp[v][j] % mod) %= mod;

        siz[u] += siz[v];

        for(int i = 1; i <= siz[u]; ++i) dp[u][i] = tmp[i];

    }

    for(int i = 2; i <= siz[u]; i += 2)

        (dp[u][0] += 1ll * dp[u][i] * g[i] % mod) %= mod;

    if(fa) dp[u][0] = mod - dp[u][0];

}

int main() {

    scanf("%d", &n);

    for(int i = 1; i < n; ++i) {

        scanf("%d %d", &x, &y);

        G[x].push_back(y); 

        G[y].push_back(x);

    }

    g[0] = 1;

    for(int i = 2; i <= n; i += 2)

        g[i] = 1ll * g[i - 2] * (i - 1) % mod;

    dfs(1, 0);

    printf("%d\n", dp[1][0]);

    return 0;

}
