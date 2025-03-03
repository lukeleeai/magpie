#include "stdc++.h"

#define rep(i, n) for (lli i = 0; i < (n); i++)

#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)

using namespace std;

using lli = long long int;

struct dijkstra {

    vector<vector<pair<lli, lli>>> e;

    int n;

    lli inf = 1e18;

    dijkstra(int n) : n(n)

    {

        e.resize(n);

    }

    void add(int a, int b, lli c)

    {

        e[a].push_back(make_pair(b, c));

    }

    void biadd(int a, int b, lli c)

    {

        add(a, b, c);

        add(b, a, c);

    }

    vector<lli> get(int s)

    {

        vector<lli> dist(n, inf);

        dist[s] = 0;

        using p = pair<lli, lli>;

        priority_queue<p, vector<p>, greater<p>> que;

        que.push(make_pair(0, s));

        while (!que.empty()) {

            lli d = que.top().first;

            lli cur = que.top().second;

            que.pop();

            if (dist[cur] < d)

                continue;

            dist[cur] = d;

            for (auto s : e[cur]) {

                lli wei = s.second;

                lli to = s.first;

                if (dist[to] > dist[cur] + wei) {

                    dist[to] = dist[cur] + wei;

                    que.push(make_pair(dist[cur] + wei, to));

                }

            }

        }

        return dist;

    }

    vector<lli> count(int s, lli mod)

    {

        auto sd = get(s);

        vector<bool> used(n, false);

        vector<lli> dp(n, 0);

        dp[s] = 1;



        using p = pair<lli, lli>;

        priority_queue<p, vector<p>, greater<p>> que;

        que.push(make_pair(0, s));

        while (!que.empty()) {

            lli d = que.top().first;

            lli cur = que.top().second;

            que.pop();

            if (used[cur])

                continue;

            used[cur] = true;

            for (auto ed : e[cur]) {

                lli wei = ed.second;

                lli to = ed.first;

                if (sd[to] == sd[cur] + wei) {

                    dp[to] = (dp[cur] + dp[to]) % mod;

                    que.push(make_pair(d + wei, to));

                }

            }

        }

        return dp;

    }

};

int main()

{

    int n, m, s, t;

    cin >> n >> m;

    dijkstra dij(n);

    cin >> s >> t;

    s--, t--;

    int u, v, d;

    rep(i, m)

    {

        cin >> u >> v >> d;

        u--, v--;

        dij.biadd(u, v, d);

    }

    auto ds = dij.get(s);

    auto dt = dij.get(t);

    lli mod = 1e9 + 7;

    auto ps = dij.count(s, mod);

    auto pt = dij.count(t, mod);



    lli ans = ps[t] * pt[s];

    rep(i, n)

    {

        lli tmp = 0;

        if (ds[i] * 2 == ds[t]) {

            tmp = (ps[i] * pt[i]) % mod;

            tmp = (tmp * tmp) % mod;

        } else {

            for (auto ed : dij.e[i]) {

                if (ds[i] * 2 < ds[t] and (ds[i] + ed.second) * 2 > ds[t] and ds[i] + ed.second + dt[ed.first] == ds[t]) {

                    tmp += (ps[i] * pt[ed.first]) % mod * (ps[i] * pt[ed.first] % mod);

                    tmp %= mod;

                }

            }

        }

        ans = (ans - (tmp % mod) + mod) % mod;

    }

    cout << ans << endl;

}
