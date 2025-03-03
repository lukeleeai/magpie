#include "stdc++.h"

#define rep(i, n) for (lli i = 0; i < (n); i++)

#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)

using namespace std;

using lli = long long int;

lli dp[2][100005] = {};

lli mod = 1e9 + 7;

using p = pair<lli, lli>;

vector<p> e[100005];

vector<p> re[100005];

int main()

{

    lli n, m;

    cin >> n >> m;

    lli s, t;

    cin >> s >> t, s--, t--;

    lli u, v, d;

    rep(i, m)

    {

        cin >> u >> v >> d;

        u--, v--;

        e[u].push_back(make_pair(v, d));

        e[v].push_back(make_pair(u, d));

    }



    lli inf = 1e18;

    priority_queue<p, vector<p>, greater<p>> que;

    que.push(make_pair(0, s));

    vector<lli> dm(n, inf);

    while (!que.empty()) {

        auto piyo = que.top();

        d = piyo.first;

        auto cur = piyo.second;

        que.pop();

        if (dm[cur] <= d)

            continue;

        dm[cur] = d;

        for (auto to : e[cur]) {

            que.push(make_pair(d + to.second, to.first));

        }

    }

    que.push(make_pair(0, s));

    dp[0][s] = 1;

    vector<bool> used;

    used.assign(n, false);



    while (!que.empty()) {

        auto dd = que.top().first;

        auto s = que.top().second;

        que.pop();

        if (used[s])

            continue;

        used[s] = true;

        for (auto from : e[s]) {

            if (dm[s] + from.second == dm[from.first]) {

                (dp[0][from.first] += dp[0][s]) %= mod;

            }

            if (dm[s] < dm[from.first])

                que.push(make_pair(dm[from.first], from.first));

        }

    }

    // rep(i, n)

    // {

    //     cout << dm[i] << endl;

    // }

    auto ddm = dm;

    que.push(make_pair(0, t));

    dm.assign(n, inf);

    while (!que.empty()) {

        auto piyo = que.top();

        d = piyo.first;

        auto cur = piyo.second;

        que.pop();

        if (dm[cur] <= d)

            continue;

        dm[cur] = d;

        for (auto to : e[cur]) {

            que.push(make_pair(d + to.second, to.first));

        }

    }



    used.assign(n, false);

    que.push(make_pair(0, t));

    dp[1][t] = 1;

    while (!que.empty()) {

        auto dd = que.top().first;

        auto ss = que.top().second;

        que.pop();

        if (used[ss])

            continue;

        used[ss] = true;

        for (auto from : e[ss]) {

            if (dm[ss] + from.second == dm[from.first]) {

                if (from.first == 3) {

                }

                (dp[1][from.first] += dp[1][ss]) %= mod;

            }

            if (dm[ss] < dm[from.first])

                que.push(make_pair(dm[from.first], from.first));

        }

    }



    lli ans = dp[1][s] * dp[0][t];

    lli piyo = dm[s];

    vector<int> pivot_v;

    map<int, map<int, bool>> pivot_e;



    rep(i, n)

    {

        lli dd = dm[i];

        if (dd * 2 == piyo) {

            lli tmp = dp[1][i] * dp[0][i] % mod;

            ans = (ans - (tmp % mod * tmp) % mod + mod) % mod;

        } else {

            for (auto s : e[i]) {

                if ((dd * 2 < piyo and (dd + s.second) * 2 > piyo) and dm[i] + ddm[s.first] + s.second == piyo) {

                    //cout << i << " " << s.first << " " << endl;

                    lli tmp = dp[1][i] * dp[0][s.first];

                    ans = ((ans - (tmp % mod * (tmp % mod))) % mod + mod) % mod;

                }

            }

        }

    }

    cout << ans << endl;

}
