#include "stdc++.h"



using namespace std;



const int max_n = 2022, mod = 1000000007;



struct edge {

    int u, v, d;



    bool operator < (const edge &e) const {

        return d < e.d;

    }

};



int mul(int x, int y) {

    return 1LL * x * y % mod;

}



int n, m, p[max_n], pw[max_n];

edge e[max_n];

bool take[max_n];

vector<int> g[max_n], d[max_n];

long long x;



int find_set(int v) {

    if (v == p[v]) {

        return v;

    }

    return p[v] = find_set(p[v]);

}



bool union_set(int v1, int v2) {

    v1 = find_set(v1);

    v2 = find_set(v2);

    if (v1 == v2) {

        return false;

    }

    p[v1] = v2;

    return true;

}



int get_max(int v, int fin, int mx, int p) {

    if (v == fin) {

        return mx;

    }

    int res = -1;

    for (int i = 0; i < g[v].size(); ++i) {

        const int to = g[v][i], c = d[v][i];

        if (to == p) {

            continue;

        }

        res = max(res, get_max(to, fin, max(mx, c), v));

    }

    return res;

}



int main() {

    //freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

    pw[0] = 1;

    for (int i = 1; i < max_n; ++i) {

        pw[i] = mul(pw[i - 1], 2);

    }

    cin >> n >> m >> x;

    if (n <= 2) {

        cout << 0 << endl;

        return 0;

    }

    for (int i = 0; i < m; ++i) {

        cin >> e[i].u >> e[i].v >> e[i].d;

        --e[i].u;

        --e[i].v;

    }

    sort(e, e + m);

    for (int i = 0; i < n; ++i) {

        p[i] = i;

    }

    long long tot = 0;

    for (int i = 0; i < m; ++i) {

        take[i] = false;

        if (union_set(e[i].u, e[i].v)) {

            take[i] = true;

            tot += e[i].d;

            g[e[i].u].push_back(e[i].v);

            d[e[i].u].push_back(e[i].d);

            g[e[i].v].push_back(e[i].u);

            d[e[i].v].push_back(e[i].d);

        }

    }

    int ans = 0;

    if (tot == x) {

        ans += mul(pw[n - 1] + mod - 2, pw[m - n + 1]);

    }

    vector<int> all;

    for (int i = 0; i < m; ++i) {

        if (!take[i]) {

            int mx = get_max(e[i].u, e[i].v, -1, -1);

            all.push_back(e[i].d - mx);

        }

    }

    sort(all.begin(), all.end());

    for (int i = 0; i < all.size(); ++i) {

        if (tot + all[i] == x) {

            ans += pw[all.size() - i];

            ans %= mod;

        }

    }

    cout << ans << endl;

    return 0;

}
