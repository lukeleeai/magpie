#include "stdc++.h"



using namespace std;

using uint = unsigned int;

using ll = long long;

using ull = unsigned long long;

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T> using V = vector<T>;

template <class T> using VV = V<V<T>>;



// bit op

int bsr(uint x) { return 31 - __builtin_clz(x); }

int bsr(ull x) { return 63 - __builtin_clzll(x); }

int bsf(uint x) { return __builtin_ctz(x); }

int bsf(ull x) { return __builtin_ctzll(x); }



// D.key must be unsigned integer

template <class D> struct RadixHeap {

    using C = decltype(D().key);

    static int bsr1(C x) { return (x == 0) ? 0 : bsr(x) + 1; }

    int sz = 0;

    C last = 0;

    VV<D> v = VV<D>(sizeof(C) * 8 + 1);

    RadixHeap() {}

    void push(D x) {

        assert(last <= x.key);

        sz++;

        v[bsr1(x.key ^ last)].push_back(x);

    }

    void pull() {

        if (v[0].size()) return;

        int i = 1;

        while (!v[i].size()) i++;

        last = min_element(v[i].begin(), v[i].end(),

                           [&](D l, D r) { return l.key < r.key; })

                ->key;

        for (D p : v[i]) {

            v[bsr1(p.key ^ last)].push_back(p);

        }

        v[i].clear();

    }

    D top() {

        pull();

        return v[0].back();

    }

    void pop() {

        pull();

        sz--;

        v[0].pop_back();

    }

    int size() const { return sz; }

    bool empty() const { return sz == 0; }

};



template <class D> struct MinDist {

    V<D> dist;

    V<int> from;

};



template <class D, class E, class PQ, class P>

MinDist<D> get_mindist(const VV<E>& g, int s, D inf) {

    int n = (int)g.size();

    V<D> dist = V<D>(n, inf);

    V<int> from = V<int>(n);

    PQ q;

    q.push(P{0, s});

    dist[s] = D(0);

    while (!q.empty()) {

        P p = q.top();

        q.pop();

        if (dist[p.to] < p.key) continue;

        for (E e : g[p.to]) {

            if (p.key + e.dist < dist[e.to]) {

                dist[e.to] = p.key + e.dist;

                from[e.to] = p.to;

                q.push(P{dist[e.to], e.to});

            }

        }

    }

    return MinDist<D>{dist, from};

}

template <class D, class E>

MinDist<D> get_mindist_pq(const VV<E>& g,

                          int s,

                          D inf = numeric_limits<D>::max()) {

    struct P {

        D key;

        int to;

        bool operator<(P r) const { return key > r.key; }

    };

    return get_mindist<D, E, priority_queue<P>, P>(g, s, inf);

}



template <class D, class E>

MinDist<D> get_mindist_radix(const VV<E>& g,

                             int s,

                             D inf = numeric_limits<D>::max()) {

    struct P {

        D key;

        int to;

    };

    return get_mindist<D, E, RadixHeap<P>, P>(g, s, inf);

}





int main() {

    cin.tie(0);

    ios::sync_with_stdio(false);

    cout << setprecision(20) << fixed;

    int n, m;

    cin >> n >> m;



    using P = pair<int, int>;

    V<set<int>> gc(n);

    VV<P> _g(n);

    for (int i = 0; i < m; i++) {

        int p, q, c;

        cin >> p >> q >> c; p--; q--;

        gc[p].insert(c);

        gc[q].insert(c);

        _g[p].push_back(P(q, c));

        _g[q].push_back(P(p, c));

    }



    int co = 0;

    map<P, int> p2id;

    for (int i = 0; i < n; i++) {

        gc[i].insert(0);

        for (int c: gc[i]) {

            p2id[P(i, c)] = co;

            co++;

        }

    }



    struct Edge {

        int to, dist;

    };

    VV<Edge> g(co);

    for (int i = 0; i < n; i++) {

        for (P p: _g[i]) {

            int j = p.first;

            int c = p.second;

            int mid = p2id[P(i, c)];

            int yid = p2id[P(j, c)];

            g[mid].push_back(Edge{yid, 0});

        }

        for (int c: gc[i]) {

            if (c == 0) continue;

            int mid = p2id[P(i, c)];

            int yid = p2id[P(i, 0)];

            g[mid].push_back(Edge{yid, 0});

            g[yid].push_back(Edge{mid, 1});

        }

    }

    int sid = p2id[P(0, 0)];

    int tid = p2id[P(n-1, 0)];

    int ans = get_mindist_radix<uint>(g, sid).dist[tid];

    if (ans >= TEN(9)) ans = -1;

    cout << ans << endl;

    return 0;

}
