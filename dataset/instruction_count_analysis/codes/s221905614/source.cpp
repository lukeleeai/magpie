#include "stdc++.h"

using namespace std;



using ll = long long;

#define FOR(i, m, n) for (int i = (m); i < (n); i++)

#define FORR(i, m, n) for (int i = (m); i >= (n); i--)

#define REP(i, n) FOR(i, 0, (n))

#define REPR(i, n) FORR(i, (n) - 1, 0)

#define REP1(i, n) FOR(i, 1, (n) + 1)

#define ALL(c) (c).begin(), (c).end()

#define sz(v) (int)v.size()

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}

template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}

const int MOD = 1000000007;

const int INF = 1000000001;

const ll LINF = 1000000001000000001LL;

const char EOL = '\n';



void solve();



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cout << fixed << setprecision(numeric_limits<double>::max_digits10);

    solve();

    return 0;

}



struct edge {

    int to;

    ll cost;

};



// <最短距離, 頂点の番号>

using P = pair<ll, int>;

const int MAX_V = 100100;



vector<edge> G[MAX_V];

vector<ll> d(MAX_V, LINF);



void dijkstra(int s) {

    priority_queue<P, vector<P>, greater<P> > que;

    d[s] = 0;

    que.push(P(0, s));



    while (!que.empty()) {

        P p = que.top();

        que.pop();

        int v = p.second;

        if (d[v] < p.first) continue;



        for (int i=0; i<G[v].size(); ++i) {

            edge e = G[v][i];

            if (d[e.to] > d[v] + e.cost) {

                d[e.to] = d[v] + e.cost;

                que.push(P(d[e.to], e.to));

            }

        }

    }

}



void solve() {

    int n, m;

    cin >> n >> m;

    int l, r;

    ll c;

    REP(i, m) {

        cin >> l >> r >> c;

        l--; r--;

        edge e = {r, c};

        G[l].push_back(e);

    }

    REP(i, n - 1) {

        edge e = {i, 0};

        G[i + 1].push_back(e);

    }

    dijkstra(0);

    cout << (d[n - 1] == LINF ? -1 : d[n - 1]) << EOL;

}
