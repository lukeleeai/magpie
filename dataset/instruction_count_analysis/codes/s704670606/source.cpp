#include <iostream>

#include <vector>

#include <queue>

#include <algorithm>

#define MAX_V 200000

#define INF 1 << 29

using namespace std;

typedef long long ll;

typedef pair<ll, int> pli;

struct Edge {

    int to;

    ll cost;

};

vector<Edge> g[MAX_V];

ll d[MAX_V];

void solve() {

    d[0] = 0;

    queue<pli> q;

    q.push(pli(0LL, 0));

    while (!q.empty()) {

        pli p = q.front(); q.pop();

        int v = p.second;

        for (size_t i = 0U; i < g[v].size(); ++i) {

            Edge e = g[v][i];

            if (d[e.to] > e.cost + d[v]) {

                d[e.to] = e.cost + d[v];

                q.push(pli(d[e.to], e.to));

            }

        }

    }

}

int main(void) {

    int k; cin >> k;

    for (int i = 0; i <= k; ++i) {

        d[i] = INF;

    }

    for (int i = 0; i < k; ++i) {

        Edge e = { i + 1, 1LL };

        g[i].push_back(e);

    }

    for (int i = 1; i < k; ++i) {

        Edge e = { i * 10 % k, 0LL };

        if (e.to == 0) e.to = k;

        g[i].push_back(e);

    }

    solve();

    cout << d[k] << endl;

    return 0;

}








































