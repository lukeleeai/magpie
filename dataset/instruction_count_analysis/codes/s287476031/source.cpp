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



inline vector<int> get_d(int n) {return vector<int>(n, INF);}

inline vector<ll> get_d(ll n) {return vector<ll>(n, LINF);}

template<typename T> vector<T> dijkstra(int s, vector<vector<pair<int, T>>>& g) {

    T n = sz(g);

    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;

    vector<T> d = get_d(n);

    d[s] = 0;

    q.emplace(0, s);



    while (!q.empty()) {

        pair<T, int> p = q.top();

        q.pop();

        int v = p.second;

        if (d[v] < p.first) continue;



        for (auto x : g[v]) {

            if (d[x.first] > d[v] + x.second) {

                d[x.first] = d[v] + x.second;

                q.emplace(d[x.first], x.first);

            }

        }

    }

    return d;

}



void solve() {

    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, ll>>> g(n, vector<pair<int, ll>>());

    int l, r;

    ll c;

    REP(i, m) {

        cin >> l >> r >> c;

        l--; r--;

        g[l].emplace_back(r, c);

    }

    REP(i, n - 1) g[i + 1].emplace_back(i, 0);

    vector<ll> d = dijkstra(0, g);

    cout << (d[n - 1] == LINF ? -1 : d[n - 1]) << EOL;

}
