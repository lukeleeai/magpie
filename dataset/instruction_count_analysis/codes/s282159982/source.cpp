#include "stdc++.h"



using namespace std;



typedef long long ll;



const int N = 2e5 + 5, mod = 1e9 + 7;



int n;

int siz[N], mul[N], ans[N];

vector<int> g[N];



int pw(int x, int y) {

    int res = 1;

    while (y) {

        if (y & 1)

            res = (ll)res * x % mod;

        x = (ll)x * x % mod;

        y >>= 1;

    }

    return res; 

}



void dfs(int u, int fa) {

    siz[u] = 1, mul[u] = 1;

    for (auto v : g[u]) 

        if (v != fa) {

            dfs(v, u);

            siz[u] += siz[v];

            mul[u] = (ll)mul[u] * mul[v] % mod;

        }

    mul[u] = (ll)mul[u] * siz[u] % mod;

}



void dfs2(int u, int fa, int fromFa) {

    if (u != 1)

        ans[u] = (ll)mul[u] * pw(siz[u], mod - 2) % mod * n % mod * fromFa % mod;

    else 

        ans[u] = (ll)mul[u] * fromFa % mod; 

    for (auto v : g[u]) 

        if (v != fa) {

            int tmp = (ll)fromFa * mul[u] % mod * pw(mul[v], mod - 2) % mod * pw(siz[u], mod - 2) % mod * (n - siz[v]) % mod;

            dfs2(v, u, tmp);

        }

}



int main() {

    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i < n; i++) {

        int u, v;

        cin >> u >> v;

        g[u].push_back(v);

        g[v].push_back(u);

    }

    dfs(1, 0);

    dfs2(1, 0, 1);

    int x = 1;

    for (int i = 1; i <= n; i++)

        x = (ll)x * i % mod;

    for (int i = 1; i <= n; i++)

        cout << (ll)x * pw(ans[i], mod - 2) % mod << '\n';

    return 0; 

}