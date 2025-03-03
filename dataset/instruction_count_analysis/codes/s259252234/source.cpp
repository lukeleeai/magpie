#include "stdc++.h"



using namespace std;



typedef long long ll;

typedef pair<ll, ll> P;



#define each(i,a) for (auto&& i : a)

#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)

#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)

#define REP(i,n) FOR(i,0,n)

#define RREP(i,n) RFOR(i,0,n)

#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME

#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)

#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)

#define pb push_back

#define all(a) (a).begin(),(a).end()

#define chmin(x,v) x = min(x, v)

#define chmax(x,v) x = max(x, v)



const ll linf = 1e18;

const int inf = 1e9;

const double eps = 1e-12;

const double pi = acos(-1);



template<typename T>

istream& operator>>(istream& is, vector<T>& vec) {

    each(x,vec) is >> x;

    return is;

}

template<typename T>

ostream& operator<<(ostream& os, const vector<T>& vec) {

    rep(i,vec.size()) {

        if (i) os << " ";

        os << vec[i];

    }

    return os;

}

template<typename T>

ostream& operator<<(ostream& os, const vector< vector<T> >& vec) {

    rep(i,vec.size()) {

        if (i) os << endl;

        os << vec[i];

    }

    return os;

}

class MaxFlow {

public:

    struct Edge {

        ll to, cap, rev;

    };

    vector<vector<Edge>> G;

    vector<ll> iter;

private:

    bool is_debug;

    ll V;

    vector<ll> bfs(ll s) {

        vector<ll> dist(V, linf);

        dist[s] = 0;

        queue<ll> Q; Q.push(s);

        while ( !Q.empty() ) {

            ll v = Q.front(); Q.pop();

            each(e, G[v]) {

                if (e.cap > 0 && dist[e.to] == linf) {

                    dist[e.to] = dist[v]+1;

                    Q.push(e.to);

                }

            }

        }

        return dist;

    }

    ll dfs(ll v, ll t, ll f, const vector<ll>& dist, vector<bool>& used) {

        if (v == t) return f;

        if (used[v]) return 0;

        used[v] = true;

        for (ll& i = iter[v]; i < G[v].size(); ++i) {

            Edge& e = G[v][i];

            if (e.cap > 0 && dist[e.to] == dist[v]+1) {

                ll d = dfs(e.to, t, min(f, e.cap), dist, used);

                if (d > 0) {

                    e.cap -= d;

                    G[e.to][e.rev].cap += d;

                    return d;

                }

            }

        }

        return 0;

    }

public:

    const vector<vector<Edge>> Graph() {

        return G;

    }

    MaxFlow(ll V, bool is_debug=false) : V(V), G(V), is_debug(is_debug) {}

    void init(ll n) {

        V = n;

        G.assign(V, vector<Edge>());

    }

    void add(ll from, ll to, ll cap) {

        if (is_debug) cout << "ADD: " << from << " " << to << " " << cap << endl;

        assert(V > 0);

        G[from].pb({to, cap, (ll)G[to].size()});

        G[to].pb({from, 0, (ll)G[from].size()-1});

    }

    // S -> s, T -> t ??? inf ???????????§

    void add(ll from, ll to, ll min_flow, ll cap, ll S, ll T) {

        if (is_debug) cout << endl << "ADD_MIN:" << from << " " << to << " " << min_flow << " " << cap << endl;

        add(from, to, cap-min_flow);

        add(S, to, min_flow);

        add(from, T, cap);

        if (is_debug) cout << endl;

    }

    ll flow(ll s, ll t, ll f=linf) {

        ll res = 0;

        while (f > 0) {

            vector<ll> dist = bfs(s);

            if (dist[t] == linf) break;

            iter.assign(G.size(), 0);

            while (f > 0) {

                vector<bool> used(V, false);

                ll df = dfs(s, t, f, dist, used);

                if (df == 0) break;

                f -= df;

                res += df;

            }

        }

        return res;

    }

};

vector<ll> prime_divisors(ll n) {

    vector<ll> res;

    for (ll i = 2; i*i <= n; ++i) {

        if (n % i != 0) continue;

        res.pb(i);

        while (n % i == 0) n /= i;

    }

    if (n > 1) res.pb(n);

    sort(all(res));

    return res;

}

ll gcd(ll a, ll b) {

    return b == 0 ? a : gcd(b, a%b);

}

int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    ll n, m;

    while (cin >> n >> m, n || m) {

        vector<ll> a(n), b(m); cin >> a >> b;

        // ll s = n+m, t = s+1;

        // MaxFlow mf(t+1);

        // rep(i, n) rep(j, m) {

        //     if (gcd(a[i], b[j]) > 1) {

        //         mf.add(i, n+j, 1);

        //     }

        // }

        // rep(i, n) mf.add(s, i, 1);

        // rep(i, m) mf.add(n+i, t, 1);

        vector<vector<ll>> ad(n), bd(m);

        map<ll,ll> id;

        rep(i, n) ad[i] = prime_divisors(a[i]);

        rep(i, m) bd[i] = prime_divisors(b[i]);

        rep(i, n) each(x, ad[i]) id[x];

        rep(i, m) each(x, bd[i]) id[x];

        ll lid = 0;

        each(p, id) p.second = lid++;

        ll ids = lid;

        ll s = n+m+ids, t = s+1;

        MaxFlow mf(t+1);

        rep(i, n) mf.add(s, i, 1);

        rep(i, m) mf.add(n+i, t, 1);

        rep(i, n) each(x, ad[i]) mf.add(i, n+m+id[x], 1);

        rep(i, m) each(x, bd[i]) mf.add(n+m+id[x], n+i, 1);

        cout << mf.flow(s, t) << endl;

    }

}