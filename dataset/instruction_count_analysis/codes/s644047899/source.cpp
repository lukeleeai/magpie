#include "stdc++.h"

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

#define ALL(v) (v).begin(), (v).end()

using ll = long long;

constexpr int INF = 1e9;

constexpr long long LINF = 1e18;

constexpr long long MOD = 1e9 + 7;



constexpr ll MAX = 1e15;



template <typename T>

vector<T> Dijkstra(int s, vector<vector<pair<int, T>>>& G,

                   /*vector<int> & prev,*/ const T INF = 1e9) {

    using P = pair<T, int>;

    int V = G.size();

    vector<T> dist(V, INF);

    priority_queue<P, vector<P>, greater<P>> que;

    dist[s] = 0;

    que.emplace(0, s);

    // prev.assign(V, -1);

    while (!que.empty()) {

        P p = que.top();

        que.pop();

        int v = p.second;

        if (dist[v] < p.first) continue;

        for (int i = 0; i < (int)G[v].size(); i++) {

            int to = G[v][i].first;

            T cost = G[v][i].second;

            if (dist[to] > dist[v] + cost) {

                dist[to] = dist[v] + cost;

                // prev[to] = v;

                que.emplace(dist[to], to);

            }

        }

    }

    return dist;

}



signed main() {

    int n, m, s, t;

    cin >> n >> m >> s >> t;

    s--;

    t--;

    int u, v, a, b;

    vector<vector<pair<int, ll>>> Gs(n), Gt(n);

    rep(i, m) {

        cin >> u >> v >> a >> b;

        u--;

        v--;

        Gs[u].emplace_back(v, a);

        Gs[v].emplace_back(u, a);

        Gt[u].emplace_back(v, b);

        Gt[v].emplace_back(u, b);

    }

    auto dists = Dijkstra(s, Gs, LINF), distt = Dijkstra(t, Gt, LINF);

    ll mx = 0;

    ll ans[n];

    for (int v = n - 1; v >= 0; v--) {

        mx = max(mx, MAX - (dists[v] + distt[v]));

        ans[v] = mx;

    }

    rep(i, n) {

        cout << ans[i] << endl;

    }

    return 0;

}