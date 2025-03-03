#include <stdio.h>

#include <iostream>

#include <algorithm>

#include <sstream>

#include <complex>

#include <vector>

#include <list>

#include <queue>

#include <deque>

#include <stack> 

#include <set>

#include <map>

#include <cstdio>

#include <string>

#include <cstdlib>

#include <cstring>

#include <cassert>

#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

using edge = struct {ll to; ll cost;};

struct point {ll x; ll y;

    bool operator<(const point& p) const{

        if (x == p.x) return y < p.y;

        return x < p.x;

    }

};

struct undirected_edge {

    ll from; ll to; ll cost;

    bool operator<(const undirected_edge& ue) const{

        return cost < ue.cost;

    }

};



typedef string str;

typedef std::pair<ll,ll> pl;

typedef std::pair<ll,pl> pl3;

typedef std::map<string, ll> msl;

typedef std::map<char, ll> mcl;

typedef std::map<ll, ll> mll;

typedef std::vector<ll> vl;

typedef std::vector<pl> vpl;

typedef std::vector<point> points;

typedef std::vector<pl3> vpl3;

// priority queue. Taking from the higher value. Don't forget calling !q.empty()

typedef std::priority_queue<ll> pq;

// priority queue. Taking from the lower value

typedef std::priority_queue<ll, vl, greater<ll>> pql;

typedef std::vector<edge> Graph;

const ll N_DIGITS = 60;

const ll MOD = 1e9 + 7;

// const ll MOD = 998244353;

const ll INF = MOD * MOD;

const long double EPS = 1e-9;

const long double PI = 3.14159265358979323846;

points dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1},  // four directions

               {1, 1}, {-1, 1}, {-1, -1}, {1, -1},  // diagonal

               {0, 0}  // self

               };



template <typename A, typename B>

string to_string(pair<A, B> p);

 

template <typename A, typename B, typename C>

string to_string(tuple<A, B, C> p);

 

template <typename A, typename B, typename C, typename D>

string to_string(tuple<A, B, C, D> p);

 

string to_string(const string& s) {

  return '"' + s + '"';

}

 

string to_string(const char* s) {

  return to_string((string) s);

}

 

string to_string(bool b) {

  return (b ? "true" : "false");

}

 

string to_string(vector<bool> v) {

  bool first = true;

  string res = "{";

  for (int i = 0; i < static_cast<int>(v.size()); i++) {

    if (!first) {

      res += ", ";

    }

    first = false;

    res += to_string(v[i]);

  }

  res += "}";

  return res;

}

 

template <size_t N>

string to_string(bitset<N> v) {

  string res = "";

  for (size_t i = 0; i < N; i++) {

    res += static_cast<char>('0' + v[i]);

  }

  return res;

}

 

template <typename A>

string to_string(A v) {

  bool first = true;

  string res = "{";

  for (const auto &x : v) {

    if (!first) {

      res += ", ";

    }

    first = false;

    res += to_string(x);

  }

  res += "}";

  return res;

}

 

template <typename A, typename B>

string to_string(pair<A, B> p) {

  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";

}

 

template <typename A, typename B, typename C>

string to_string(tuple<A, B, C> p) {

  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";

}

 

template <typename A, typename B, typename C, typename D>

string to_string(tuple<A, B, C, D> p) {

  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";

}

 

void debug_out() { cerr << endl; }

 

template <typename Head, typename... Tail>

void debug_out(Head H, Tail... T) {

  cerr << " " << to_string(H);

  debug_out(T...);

}



#define rep(i, n) for(ll (i) = 0; (i) < (n) ; (i)++ )

#define revrep(i, n) for(ll (i) = n - 1; (i) >= 0 ; (i)--)

#define For(i, a, b) for(ll (i) = (a); (i) < (b) ; (i)++ )

#define revFor(i, b, a) for(ll (i) = (b) - 1; (i) >= (a) ; (i)--)

#define all(a) (a).begin(), (a).end()

#define rall(a) (a).rbegin(), (a).rend()

#define isUpper(c) ('a' - c > 0)

#define isNum(c) (0 <= (c) - '0' && (c) - '0' <= 9)

#define toLower(c) char((c)+0x20)

#define toUpper(c) char((c)-0x20)

#define pb push_back

#define mp make_pair

#define pr(a) cout << (a)

#define prl(a) cout << (a) << endl

#define prl2(a,b) cout << (a) << " " << (b) << endl

#define prl3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl

#define prl4(a,b,c,d) cout << (a) << " " << (b) << " " << (c) << " " << (d) << endl

#define prs(a) cout << (a) << " "

#define prs2(a,b) cout << (a) << " " << (b) << " "

#define prs3(a,b,c) cout << (a) << " " << (b) << " " << (c) << " "

#define prs4(a,b,c,d) cout << (a) << " " << (b) << " " << (c) << " " << (d) << " "

#define yn(condition) if ((condition)) prl("Yes"); else prl("No");

#define YN(condition) if ((condition)) prl("YES"); else prl("NO");

#define in1(a) cin >> (a)

#define in2(a,b) cin >> (a) >> (b)

#define in3(a,b,c) cin >> (a) >> (b) >> (c)

#define in4(a,b,c,d) cin >> (a) >> (b) >> (c) >> (d)

#define e1 first

#define e2 second

#define ctol(c) ll((c)) - ll('0')

#define ltos(n) to_string((n))

#define items(kv, v) for(auto &(kv): (v))

#define ndig(N, n) ctol(ll(ltos((N))[ll(ltos((N)).length()) - (n)]))

#define rsort(a,n) sort(a,a+n,greater<>())

#define Forchar(c,a,z) for(char (c) = (a); (c) <= (z); (c)++)

#define cntchar(s,c) count(all((s)), c)

#define substring(s, start, end) s.substr((start), (end) - (start) + 1)

#define prl_nd(num, digits) cout << fixed << setprecision(digits) << (num) << endl;

#define XOR(a, b) (a)^(b)

#define prl_time(s) prl3("Elapsed Time:", 1000.0 * (clock() - s) / CLOCKS_PER_SEC, "[ms]");

#define char_to_str(c) string(1, (c))

#define DEBUG(x) cerr<<#x<<": "<<(x)<<endl

#define DEBUG_VEC(v) cerr<<#v<<": ";rep(__i,(v).size())cerr<<((v)[__i])<<", ";cerr<<endl

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)



template<class T>

inline bool chmax(T &a, T b) {

    if(a < b) {a = b; return true;}

    return false;

}



template<class T>

inline bool chmin(T &a, T b) {

    if(a > b){a = b; return true;}

    return false;

}



struct MaxFlow {

    struct F_edge {

        ll to, rev, capacity;

        F_edge(ll to, ll rev, ll capacity) : to(to), rev(rev), capacity(capacity) {}

    };



    typedef vector<F_edge> F_edges;

    vector<F_edges> graph;

    ll n_vertex;

    // level is the shortest path to get a given node from the source node.

    vl level, iter;



    MaxFlow(ll n_vertex) : n_vertex(n_vertex) {graph.resize(n_vertex);}



    void add_edge(ll from, ll to, ll capacity) {

        graph[from].pb({to, ll(graph[to].size()), capacity});

        graph[to].pb({from, ll(graph[from].size()) - 1, 0});

    }



    void bfs(ll source){

        level = vl(n_vertex, -1); level[source] = 0;

        queue<ll> q; q.push(source);

        while (!q.empty()) {

            ll vertex = q.front(); q.pop();

            rep(i, graph[vertex].size()){

                ll target = graph[vertex][i].to;

                ll cap_target = graph[vertex][i].capacity;

                // if the flow can be into the target node, implement below.

                if (cap_target > 0 && level[target] < 0){

                    level[target] = level[vertex] + 1;

                    q.push(target);

                }

            }

        }

    }



    ll dfs(ll vertex, ll sink, ll flow) {

        if (vertex == sink) return flow;

        for(ll &i = iter[vertex]; i < graph[vertex].size(); i++){

            ll target = graph[vertex][i].to; ll cap_target = graph[vertex][i].capacity;

            ll rev_target = graph[vertex][i].rev;

            // if capasitiy is not full yet and target is farther,

            // then assign current flow 

            if (cap_target > 0 && level[vertex] < level[target]) {

                ll d = dfs(target, sink, min(cap_target, flow));

                if (d > 0){ // if the flow successfully reaches the sink, reduce the flow from the capacity 

                    graph[vertex][i].capacity -= d;

                    graph[target][rev_target].capacity += d;

                    return d;

                }

            }

        }

        return 0;

    }



    ll dinic(ll source, ll sink){

        // complexity O(EV^2)

        ll flow = 0;

        while (true) {

            bfs(source);

            // if there is no path leading to the sink, the maximum flow is 0.

            if (level[sink] < 0) return flow;

            iter = vl(n_vertex, 0); ll f;

            while ((f = dfs(source, sink, INF)) > 0) flow += f;

        }

    }

};



class UnionFind {

    vl parents, set_size;

    ll n_groups;

public:

    UnionFind(){}

    UnionFind(ll n){

        parents = set_size = vl(n);

        n_groups = n;

        rep(i, n) {parents[i] = i; set_size[i] = 1LL;}

    }



    ll root_find(ll x){

        if (parents[x] == x) return x;

        return parents[x] = root_find(parents[x]);

    }



    void unite(ll x, ll y){

        // priority for x is larger than that of y

        x = root_find(x); y = root_find(y);

        if (x == y) return;

        parents[y] = x, set_size[x] += set_size[y];

        n_groups--;

    }



    bool is_same(ll x, ll y) {// connected or not

        return root_find(x) == root_find(y);

    }



    ll size(ll x) {

        return set_size[root_find(x)];

    }



    ll union_count() const{

        return n_groups;

    }

};



struct Doubling { // ABC167D

    ll n;

    ll sz;

    vector<vl> next; 

    /*

        next[k + 1][i] := next[k][next[k][i]]

        next[0][i] := edge[i]

        e.g. a0, a1, ..., an-1 / 0 <= ai <= n - 1

        a0 -> a[a0] -> a[a[a0]] -> ... -> a[a[...[a[0]]]] (m times)

        Let the function repeatedly input a[i] m times be f[m](a[i])

        

        - get(i, x) returns f[x](a[i])

        - lower_bound(i, j) returns minimum x which satisfies f[x](a[i]) >= j.

                                    if not possible returns n.



    */

 

    // edge[i]: the step size for one iteration

    Doubling(vl& edge) : n(edge.size()), sz(62) {

        next.resize(sz, vl(n, -1));

        rep(i, n) next[0][i] = edge[i];

        rep(k, sz - 1) rep(i, n) next[k + 1][i] = next[k][next[k][i]];

    }

    

    ll get(ll i, ll x) {

        ll ret = i;

        rep(bit, sz){

            if (!(x >> bit & 1)) continue;

            ret = next[bit][ret];

        }

        return ret;

    }

    

    ll lower_bound(ll i, ll j) {

        ll cur = i, acc = 0;

        revrep(wid, sz){

            if (next[wid][cur] < j) {

                acc += 1LL << wid;

                cur = next[wid][cur];

            }

        }

        return min(n, acc + 1);

    }

};



class LowestCommonAncestor{

public:

    ll N, logN;

    vl depth, len;

    vector<Graph> tree;

    vector<vl> parents;



    LowestCommonAncestor(ll n, ll offset = -1, bool is_weighted = true){

        N = n;

        logN = 0;

        while (N > (1LL << logN)) logN++;

        depth = vl(N); len = vl(N);

        parents = vector<vl>(logN, vl(N));

        tree = vector<Graph>(N);

        input(N, offset, is_weighted);

        init(0, -1, 0, 0);

        build();

    }



    void add_edge(ll from, ll to, ll dist){

        tree[from].pb({to, dist});

        tree[to].pb({from, dist});

    }



    void input(ll n, ll offset = -1, bool is_weighted = true){

        rep(i, n - 1){

            ll a, b, d = 1; in2(a, b);

            a += offset, b += offset;

            if (is_weighted) in1(d);

            add_edge(a, b, d);

        }

    }



    void init(ll source, ll parent, ll d, ll l){

        depth[source] = d;

        parents[0][source] = parent;

        len[source] = l;

        rep(i, tree[source].size()){

            ll target = tree[source][i].to;

            ll cost = tree[source][i].cost;

            if (target == parent) continue;

            init(target, source, d + 1, cost + l);

        }

    }



    void build(){

        rep(k, logN - 1) rep(n, N){

            // if there is no parent, -1.

            // otherwise, the parent of the parent is the parent.

            if (parents[k][n] < 0) parents[k + 1][n] = -1;

            else parents[k + 1][n] = parents[k][parents[k][n]];

        }

    }



    ll query(ll u, ll v){

        if (depth[u] > depth[v]) swap(u, v);

        rep(k, logN) if ((depth[v] - depth[u]) >> k & 1) v = parents[k][v];

        if (u == v) return u;



        revrep(k, logN){

            if (parents[k][u] != parents[k][v]){

                u = parents[k][u]; v = parents[k][v];

            }

        }

        return parents[0][u];

    }



    ll distance(ll u, ll v){

        ll w = query(u, v);

        return len[u] + len[v] - 2 * len[w];

    }



};



struct BinaryIndexedTree{

    ll n; vl dat;

    BinaryIndexedTree(ll n, ll ini = 0): 

        dat(n + 1, ini), n(n){};



    //       x: 1001 1010  1100 1011 1101  1111

    // x & - x: 0001 0010  0100 0001 0001  0001

    //      ->: 1010 1100 10000 1100 1100 10000



    ll update_func(ll val, ll d){

        // if maximum -> max(val, dat)

        // return max(val, dat);

        // if cumulative sum

        return val + d;

    }



    ll query(ll i){

        /*

        v[0] + v[1] + ... + v[i]

        e.g.) i = 10101

        itr1. 10101 -> 10100 

        itr2. 10100 -> 10000

        itr3. 10000 -> 00000 (break)

        */

        ll ret = 0;

        for (ll j = i; j >= 0; j = (j & (j + 1)) - 1){

            ret = update_func(ret, dat[j]);

        }

        return ret;

    }



    ll query(ll l, ll r){

        return query(r) - query(l);

    }



    ll lower_bound(ll key){

        //v[0] + v[1] + ... + v[left - 1] < key <= v[0] + v[1] + ... + v[left]

        if (key <= 0) return 0;

        ll left = 0, right = 1;

        while(right <= n) right *= 2;



        for (ll i = right; i > 0; i /= 2){

            if (left + i <= n && dat[left + i - 1] < key){

                key -= dat[left + i - 1];

                left += i;

            }

        }

        return left;

    }



    void update(ll i, ll val){

        /*

        e.g.) i = 10101, n = 11111

        itr1. i: 10101, i+1: 10110 -> 10111

        itr2. i: 10111, i+1: 11000 -> 11111 (break)

        */

        if (i < 0) return;

        for(ll j = i; j < n; j |= j + 1){

            dat[j] = update_func(val, dat[j]);

        }

    }

};



struct SegmentTree{

	ll n, ini, minimize;

	vl dat;



    // when seeking minimum

    // ini = INF

    // when seeking maximum

    // ini = -INF

	SegmentTree(ll n_, bool minimize_ = true){

        n = 1; minimize = minimize_;

        if (minimize) ini = INF;

        else ini = - INF;

		while (n < n_) n *= 2;

		dat.resize(2 * n - 1);

		rep(i, 2 * n - 1) dat[i] = ini;

    };



	void update(ll idx, ll val){

		idx += n - 1;

        if (minimize && dat[idx] <= val) return;

        if (!minimize && dat[idx] >= val) return;



		dat[idx] = val;

		while (idx > 0){

			idx = (idx - 1) / 2;

            // when seeking minimum

			if (minimize) dat[idx] = min(dat[idx * 2 + 1], dat[idx * 2 + 2]);

            // when seeking maximum

            else dat[idx] = max(dat[idx * 2 + 1], dat[idx * 2 + 2]);

		}

	}



	ll query(ll l, ll r){

        // ### NOTE ###

        // the range is [l, r]

        // l, l + 1, ..., r

        r++; // to adjust to this method

        return query_segment(l, r, 0, 0, n);

	}



	ll query_segment(ll a, ll b, ll idx, ll l, ll r){

        assert(a < b);



		if (r <= a || b <= l) return ini;

		if (a <= l && r <= b) return dat[idx];

		else{

            ll seg1 = query_segment(a, b, idx * 2 + 1, l, (l + r) / 2);

            ll seg2 = query_segment(a, b, idx * 2 + 2, (l + r) / 2, r);

            // when seeking minimum

            if (minimize) return min(seg1, seg2);

            // when seeking maximum

            else return max(seg1, seg2);

        }

	}

};



template<class Target>

class RerootingTreeDP {

public:

    using T = typename Target::type;

    struct DP_edge {

        ll to, rev; // rev is the index to trace the source node.

        T value; // objective value

    };

private:

    ll n;

    void dfs_fwd(ll source, ll parent){

        ll par_idx = -1;

        vector<T> values;

        rep(i, tree[source].size()) {

            const DP_edge& e = tree[source][i];

            if (e.to == parent){par_idx = i; continue;}

            dfs_fwd(e.to, source);

            values.pb(e.value);

        }

        

        // If the parent != -1, update the value on edge from parent to source

        if (par_idx != -1){

            ll src_idx = tree[source][par_idx].rev;

            // update values on the edge from parent to source

            tree[parent][src_idx].value = Target::merge(values);

        }

    }



    void dfs_bwd(ll source, ll parent){

        vector<T> values;

        for (auto&& e: tree[source]) values.pb(e.value);

        values = Target::evaluate(values);



        rep(i, tree[source].size()) {

            const DP_edge& e = tree[source][i];

            if (e.to == parent) continue;

            // tree[e.to][e.rev]: e.to -> source

            tree[e.to][e.rev].value = values[i];

            dfs_bwd(e.to, source);

        }

    }

public:

    UnionFind uf;

    vector<vector<DP_edge>> tree;

    RerootingTreeDP(ll n) : n(n), uf(n), tree(n) {}



    void add_edge(ll u, ll v, T val){

        assert(!uf.is_same(u, v));

        tree[u].pb({v, ll(tree[v].size()), val});

        tree[v].pb({u, ll(tree[u].size()) - 1, val});

        uf.unite(u, v);

    }

    

    void dp() {

        vector<bool> visited(n, false);

        rep(i, n){

            if (visited[uf.root_find(i)]) continue;

            dfs_fwd(i, -1);

            visited[uf.root_find(i)] = true;

        }



        visited.assign(n, false);

        rep(i, n){

            if (visited[uf.root_find(i)]) continue;

            dfs_bwd(i, -1);

            visited[uf.root_find(i)] = true;

        }

    }



    ll size() const {return tree.size();}

};



// ABC160F is one example

// Modify the functions evaluate and merge based on given problems

struct Merger {

    using type = ll;



    static type merge(const vector<type>& value){

        // merge the result below the source node

        // each value is from each child node of the source node

        // value[i] := f(child i)

        // Here, we would like to obtain f(source) using f(child i) (i = 0, 1, ..., n_children)

        ll ret = 1;

        for (auto&& v: value) ret += v;

        return ret;

    }

  

    static vector<type> evaluate(const vector<type>& value){

        // value[i] := f(source -> child i)

        // we would like to obtain f(child i -> source)

        // child j (j != i) is the grandchildren of child i

        // represent f(child i -> source) using f(source -> j) (j != i)

        // L[i + 1] := the result using f(source -> k) (k = 0, 1, ..., i)

        // R[i] := the result using f(source -> k) (k = i, i + 1, ..., n_children)



        const ll n_children = value.size();

        vl L(n_children + 1, 0), R(n_children + 1, 0);

        rep(i, n_children)

            L[i + 1] = L[i] + value[i];

        revrep(i, n_children)

            R[i] = R[i + 1] + value[i];



        vl ret(n_children);

        rep(i, n_children) ret[i] = L[i] + R[i + 1] + 1;



        return ret;

    }

};



struct StronglyConnectedComponents{

    ll n;

    vector<vl> graph, graph_rev, dag, cmp;

    vl order, visited, cmp_idx;



    StronglyConnectedComponents(){}

    StronglyConnectedComponents(ll sz):

        n(sz), graph(sz), graph_rev(sz),

        visited(sz), cmp_idx(sz){}

    

    void add_edge(ll from, ll to){

        graph[from].pb(to);

        graph_rev[to].pb(from);

    }



    void input(ll m, ll offset = -1){

        ll a, b;

        rep(i, m){

            in2(a, b);

            add_edge(a + offset, b + offset);

        }

    }



    ll operator[](ll k){

        return cmp_idx[k];

    }

 

    void dfs_fwd(ll source){

        visited[source] = 1;

        rep(i, graph[source].size()){

            ll target = graph[source][i];

            if (!visited[target]) dfs_fwd(target);

        }

        order.pb(source);

    }



    void dfs_bwd(ll source, ll num){

        visited[source] = 1, cmp_idx[source] = num;



        cmp[num].pb(source);

        rep(i, graph_rev[source].size()){

            ll target = graph_rev[source][i];

            if (!visited[target]) dfs_bwd(target, num);

        }

    }



    ll build(){

        fill(all(visited), 0);

        order.clear();

        rep(i, n)

            if (!visited[i]) dfs_fwd(i);

        

        fill(all(visited), 0);

        ll num = 0;

        revrep(i, order.size()){

            if (!visited[order[i]]){

                dag.pb(vl());

                cmp.pb(vl());

                dfs_bwd(order[i], num++);

            }

        }



        rep(i, n) for (ll to: graph[i])

            if (cmp_idx[i] != cmp_idx[to])

                dag[cmp_idx[i]].pb(cmp_idx[to]);

        

        rep(i, num){

            sort(all(dag[i]));

            dag[i].erase(unique(all(dag[i])), dag[i].end());

        }

        return num;

    }

};



struct CombinationMemo{

    ll sz, mod;

    vl facts, facts_inv, minv;



    CombinationMemo(ll sz, ll _mod):

        sz(sz), mod(_mod){

            facts.resize(sz + 5);

            facts_inv.resize(sz + 5); 

            minv.resize(sz + 5);

            init();

        }

    

    void init(){

        facts[0] = facts[1] = 1;

        minv[1] = 1;

        facts_inv[0] = facts_inv[1] = 1;



        For(i, 2, sz + 3){

            facts[i] = (i * facts[i - 1]) % mod;

            minv[i] = mod - minv[mod % i] * (mod / i) % mod;

            facts_inv[i] = facts_inv[i - 1] * minv[i] % mod;

        }

    }



    ll nCk(ll n, ll r){

        if (n == r && n == 0) return 1;

        else if (n <= 0 || r < 0 || r > n) return 0;

        ll val = (facts[n] * facts_inv[n - r]) % mod;

        val *= facts_inv[r];

        return val % mod;

    }

};



struct Grid2D{

    vector<Graph> graph;

    ll Width, Height;



    Grid2D(ll w, ll h) : Width(w), Height(h){

        graph.resize(w * h);

    }



    ll pos_to_idx(point p){

        return p.y * Width + p.x;

    }



    point idx_to_pos(ll idx){

        return {idx % Width, idx / Width}; 

    }



    bool undefined_region(point p, vector<vector<bool>>& block){

        if (p.x < 0 || p.x > Width - 1) return true;

        if (p.y < 0 || p.y > Height - 1) return true;

        if (block[p.x][p.y]) return true;

        return false;

    }



    void build(vector<vector<bool>>& block, ll val = 1){

        rep(x, Width) rep(y, Height){

            point p = {x, y};

            ll idx1 = pos_to_idx(p); ll idx2;



            if (block[x][y]) continue;

            rep(i, 4){

                point d = dirs[i], nxt = {x + d.x, y + d.y}; 

                idx2 = pos_to_idx(nxt);

                if (!undefined_region(nxt, block))

                    graph[idx1].pb({idx2, val}); // dist[idx1][idx2] = val; (warshall-floyd)

            }

        }

    }

};



ll gcd(ll m, ll n){

    ll a = max(m, n);

    ll b = min(m, n);

    while(b != 1 && b != 0){ a %= b; swap(a, b);}

    return b == 1 ? 1 : a;

}



ll lcm(ll m, ll n){ return m / gcd(m, n) * n;}



ll power_mod(ll a, ll power, ll mod){

    ll value = 1;

    while(power != 0){

        if(power & 1) value = (value * a) % mod;

        a = (a * a) % mod;

        power = power >> 1;

    }

    return value % mod;

}



ll modinv(ll a, ll mod){

    return power_mod(a, mod - 2, mod);

}



ll power_normal(ll a, ll power){

    ll value = 1;

    while(power != 0){

        if(power & 1) value = value * a;

        a = a * a;

        power = power >> 1;

    }

    return value;

}



vector<vl> pascal_triangle(ll n){

    /*

    Complexity: O(n^2)

    The upper bound of n is nearly 50.



    Parameters

    ----------

    n; the size of returned vector



    Returns

    -------

    comb[i][j]: combination(i, j). 0 <= i <= n, 0 <= j <= i

    */



    vector<vl> comb(n, vl(n));

    comb[0][0] = 1;

    For(i, 1, n + 1) rep(j, i + 1){

        comb[i][j] += comb[i - 1][j];

        if (j > 0) comb[i][j] += comb[i - 1][j - 1];

    }



    return comb;

}



ll combination(ll n, ll r, ll mod){

    if (n == r && n == 0) return 1;

    else if (n <= 0 || r < 0 || r > n) return 0;

    ll numerator = 1;

    ll denomenator = 1;

    for(ll i = 0; i < r ; i++){

        ll num = (n - i) % mod, den = (i + 1) % mod;

        (numerator *= num) %= mod;

        (denomenator *= modinv(den, mod)) %= mod;

    }



    return (numerator * denomenator) % mod;

}



ld log_combination(ll n, ll r){

    if (n == r && n == 0) return 0;

    else if (n <= 0 || r < 0 || r > n) return -INF;

    ld val = 0;

    for(ll i = 0; i < r ; i++){

        val += log(n - i);

        val -= log(i + 1);

    }



    return val;

}



ll bin_search(ll key, ll A[], ll left, ll right){

    // return the index idx where A[idx] = key.

    // A[left] is start and A[right] is end..

    // In other words, A[right], not A[right - 1], must be defined.

    while(right >= left){

        ll mid = left + (right - left) / 2;

        if (A[mid] == key) return mid;

        else if (A[mid] > key) right = mid - 1;

        else if (A[mid] < key) left = mid + 1;

    }

    return -1;

}



/*

// vs[lb - 1] < key <= vs[lb]

lb = lower_bound(all(vs), key);

// vs[ub - 1] <= key < vs[lb]

ub = upper_bound(all(vs), key);



ll bin_search_temp(ll left, ll right, callable judge){

    while(right > left){

        // when seeking lower bound

        ll mid = (right + left) / 2;

        if (judge(mid)) right = mid;

        else left = mid + 1;

        // when seeking upper bound

        ll mid = (right + left + 1) / 2;

        if (judge(mid)) left = mid;

        else right = mid - 1;

    }



    return right;

}



trinary_search



// Care the value EPS!!! Compare to the condition

ld left = 0; ld right = p;

while(abs(right - left) > EPS){

    ld left2 = (2 * left + right) / 3.0;

    ld right2 = (left + 2 * right) / 3.0;

    ld f1 = tak_func(left2);

    ld f2 = tak_func(right2);

    if (f1 <= f2) right = right2;

    else if (f2 <= f1) left = left2;

}



*/



str bin_expression(ll n, ll dig){

    str s = "";

    rep(i, dig){

        s += ltos(n % 2);

        n /= 2;

    }

    reverse(all(s));

    return s;

}



ll fact(ll n){

    if (n == 0) return 1;

    return n * fact(n - 1);

}



ll fact_mod(ll n, ll mod){

    if (n == 0) return 1;

    return n * fact_mod(n - 1, mod);

}



bool is_prime(ll n){

    if (n <= 1) return false;

    for(ll i = 2; i * i <= n; i++){

        if (n % i == 0) return false;

    }

    return true;

}



mll prime_factorization(ll n){

    ll i = 2;

    mll table;

    while(i * i <= n){

        while(n % i == 0){

            table[i] ++;

            n /= i;

        }

        i++;

    }

    if (n > 1) table[n] = 1;

    return table;

}



vl divisor_table(ll n){

    vl table;

    ll i = 1;

    while(i * i <= n){

        if (n % i == 0){

            table.pb(i);

            if (i * i != n) table.pb(n / i);

        }

        i++;

    }



    sort(all(table));



    return table;

}



ll char_to_idx(char c){

    ll idx = 0;

    Forchar(cc, 'a', 'z'){

        if (c == cc) return idx;

        else idx ++;

    }

}



ll next_combination(ll sub){

    /*

    ### Attention ###

    if k is 0 or 1 and n is 0, it does not work well.



    ll n, k; ll bit = (1 << k) - 1;

    for (; bit < (1 << n); bit = next_combination(bit)){

        bool ith = bit & (1 << i);

        procedures...

    }



        sub & -sub: the binary which shares the last digit whose value is 1 in sub

        sub + x   : carry up the last digit

            ~y    : the binary whose digits are 1 if y's digit is 0.

    (sub & ~y) / x: reduce the same number of 0s after first 1 in x from (sub & ~y).

    */

    ll x = sub & -sub, y = sub + x;

    return (((sub & ~y) / x) >> 1) | y; 

}



// just change the input if you want to change the target.

// If you want to check the common sequences in two strings,

// combine them. e.g. ABC150F

vl z_algorithm(str s){

    /*

    Paramters

    ---------

    str: the string of interest



    Returns

    -------

    res[i] is the maximum number of K which satisfies

    s[:K] == s[i:i + K]

    for each i = 0, 1, 2, ..., n - 1.

    */

    ll n = s.length(); vl res(n);

    res[0] = n;

    ll i1 = 1, i2 = 0;



    while(i1 < n){

        /*

        i1: the starting point

        i2: the length of substring

        */

        while (i1 + i2 < n && s[i2] == s[i1 + i2]) ++i2;

        res[i1] = i2; if (i2 == 0){++i1; continue;}

        ll i3 = 1;



        // update the already seen points

        while (i1 + i3 < n && i3 + res[i3] < i2){res[i1 + i3] = res[i3]; ++i3;}

        // update up to i1 + i3 and the next possible minimum length is i2 - i3 (= res[i3])

        i1 += i3, i2 -= i3;

    }

    return res;

}



ll big_number_mod(str s, ll mod){

    ll l = s.length(); ll idx = 0;

    ll val = 0; ll tenth = 1;

    while (idx < l){

        ll m = ctol(s[l - 1 - idx]);

        val += (m * tenth) % mod; val %= mod;

        tenth *= 10; tenth %= mod; idx++;

    }



    return val;

}



ll big_number_compare(str s1, str s2){    

    if (s1.length() > s2.length()) return 1;

    else if (s1.length() < s2.length()) return -1;

    else if (s1 == s2) return 0; 



    return 2 * (s1 > s2) - 1;

}



ll string_to_ll(str s){

    ll l = s.length(); ll idx = 0;

    ll val = 0; ll tenth = 1;

    while (idx < l){

        ll m = ctol(s[l - 1 - idx]);

        val += (m * tenth);

        tenth *= 10; idx++;

    }



    return val;

}



str reflected_string(str s){

    str t, u; ll n = s.length();

    t = s; reverse(all(t));

    u = substring(t, 0, n - 2) + s + substring(t, 1, n - 1);

    return u;

}



ld distance_between_point_line(point l_begin, point l_end, point p){

    ll xl1 = l_begin.x, yl1 = l_begin.y; 

    ll xl2 = l_end.x, yl2 = l_end.y;

    ll xp = p.x, yp = p.y;

    ll a = yl2 - yl1;

    ll b = - xl2 + xl1;

    ll c = - a * xl2 - b * yl2;

    return abs(ld(a * xp + b * yp + c)) / ld(sqrt(a * a + b * b));

}



bool is_cross(point l1_begin, point l1_end, point l2_begin, point l2_end){

    ll x1 = l1_begin.x, y1 = l1_begin.y;

    ll x2 = l1_end.x, y2 = l1_end.y;

    ll x3 = l2_begin.x, y3 = l2_begin.y;

    ll x4 = l2_end.x, y4 = l2_end.y;

    ll val1 = (x1 - x2) * (y3 - y1) + (y1 - y2) * (x1 - x3);

    ll val2 = (x1 - x2) * (y4 - y1) + (y1 - y2) * (x1 - x4);

    ll val3 = (x3 - x4) * (y1 - y3) + (y3 - y4) * (x3 - x1);

    ll val4 = (x3 - x4) * (y2 - y3) + (y3 - y4) * (x3 - x2);



    return val1 * val2 < 0 && val3 * val4 < 0;

}



ld space_of_triangle(point p1, point p2, point p3){

    ll x1 = p1.x, y1 = p1.y;

    ll x2 = p2.x, y2 = p2.y;

    ll x3 = p3.x, y3 = p3.y;

    ll v1 = x2 - x1; ll u1 = y2 - y1;

    ll v2 = x3 - x1; ll u2 = y3 - y1;

    ld s = ld(v1 * u2 - u1 * v2) / ld(2);

    return abs(s);

}



pair<point, ll> center_2det_of_3points(point p1, point p2, point p3){

    // the center of circle on the given three points

    // return the determinant value and the product of center points and 2 * determinant value

    ll x1 = p1.x, y1 = p1.y;

    ll x2 = p2.x, y2 = p2.y;

    ll x3 = p3.x, y3 = p3.y;



    // center of 2 points

    ll c2x_2 = x2 + x1, c2y_2 = y2 + y1;

    ll c3x_2 = x3 + x1, c3y_2 = y3 + y1;



    // vertical vector of 2 lines

    ll b2y = x2 - x1, b2x = - y2 + y1;

    ll b3y = x3 - x1, b3x = - y3 + y1;



    ll x1_2 = c3x_2 * b3y - c3y_2 * b3x, y1_2 = c2x_2 * b2y - c2y_2 * b2x;

    ll det = - b3y * b2x + b3x * b2y;

    if (det == 0) return {{INF, INF}, det};

    ll cx_2det = - b2x * x1_2 + b3x * y1_2, cy_2det = - b2y * x1_2 + b3y * y1_2;

    return {{cx_2det, cy_2det}, det};

}



ll inversion_number(vl a, ll a_max){

    /*

    Paramters

    ---------

    a: vector<ll>

        All the elements must be non-negative.

        Prefably the elements are compressed to reduce the computational cost.

    a_max: ll

        The maximum value of the vector a or the value bigger than the value stated previously.

    */



    BinaryIndexedTree bit(a_max + 1); ll val = 0;

    rep(i, a.size()){

        // i is the number of elements that have lower index than a[i].

        // call the number of elements that have lower value than a[i]

        // by subtracting these two, the residual number is the number of elements that have larger value 

        val += i - bit.query(a[i] - 1);// cumulative sum from 0 to a[i] - 1

        bit.update(a[i], 1);

    }

    return val;

}



template<typename T>

vector<T> compress(vector<T> v){

    // sort and remove all the duplicated values

    sort(all(v));

    v.erase(unique(all(v)), v.end());

    return v;

}



template<typename T>

map<T, ll> dict(const vector<T> &v){

    map<T, ll> d;

    rep(i, v.size()) d[v[i]] = i;

    return d;

}



points compress2D(vl xs, vl ys){

    /*

    NOTE

    ----

    Add the corner points if required

    */



    ll n = xs.size();

    vl xcs = compress(xs), ycs = compress(ys);

    map<ll, ll> xd = dict(xcs), yd = dict(ycs);

    points ps(n);



    rep(i, n) 

        xs[i] = xd[xs[i]], ys[i] = yd[ys[i]];

        

    rep(i, n) 

        ps[i] = {xs[i], ys[i]};

    

    sort(all(ps));



    return ps;

}



void GaussJordanBitVector(vl &bs){

    ll n = bs.size();

    ll rank = 0; ll j = 0;

    revrep(i, N_DIGITS){

        for(j = rank; j < n; j++) if (bs[j] & (1LL << i)) break;

        if (j == n) continue;

        if (j > rank) bs[rank] ^= bs[j];

        for (j = rank + 1; j < n; j++) bs[j] = min(bs[j], bs[j] ^ bs[rank]);

        rank++;

    }

}



ll kruskal(vector<undirected_edge>& es, ll n_vertex){

    sort(all(es));

    UnionFind uf(n_vertex);



    ll min_cost = 0;



    rep(i, es.size()){

        undirected_edge& e = es[i];

        if (!uf.is_same(e.from, e.to)){

            min_cost += e.cost;

            uf.unite(e.from, e.to);

        }

    }

    return min_cost;

}



ll LongestIncreasedSequence(vl& v, ll n){

    vl dp(n, INF);

    rep(i, n)

        *lower_bound(all(dp), v[i]) = v[i];

    return lower_bound(all(dp), INF) - dp.begin();

}



void dijkstra(ll start, vector<Graph>& graph, vl& dist,

              vl& vertex_pre, bool trace = false){

    priority_queue<pl, vector<pl>, greater<pl>> edge_costs;

    ll n = graph.size();

    dist = vl(n, INF);

    if (trace) vertex_pre = vl(n, -1);

    dist[start] = 0;

    edge_costs.push(pl(0, start));



    while (!edge_costs.empty()) {

        pl edge_cost = edge_costs.top();

        edge_costs.pop();

        ll idx = edge_cost.second;

        ll cost = edge_cost.first;

        if (dist[idx] < cost) continue;



        rep(i, graph[idx].size()){

            edge e = graph[idx][i];

            if (dist[e.to] > dist[idx] + e.cost){

                dist[e.to] = dist[idx] + e.cost;

                if (trace) vertex_pre[e.to] = idx;

                edge_costs.push(pl(dist[e.to], e.to));

            }

        }

    }

}



vl get_predecessor(ll g, vl& vertex_pre){

    vl path;

    for (; g != -1; g = vertex_pre[g]) path.pb(g);

    

    reverse(all(path));

    return path;

}



void warshall_floyd(ll n, vector<vl>& dist){

    // Dont forget the initialization

    // rep(i, n) rep(j, n) dist[i][j] = INF * (i != j);

    rep(k, n) rep(i, n) rep(j, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

}



// ABC061D

bool find_negative_cycle(ll n, ll goal, vector<Graph>& graph, vl& dist){

    rep(i, n) rep(v, n) rep(k, graph[v].size()){

        edge e = graph[v][k];

        if (dist[e.to] != INF && dist[e.to] > dist[v] + e.cost){

            dist[e.to] = -INF;

            if (goal == -1) return true;

            else if (goal == e.to) return true;

        }

    }

    return false;

}



bool bellman_ford(ll start, ll n, ll goal, vector<Graph>& graph, vl& dist){

    // if there is a closed circuit, it returns false. (when goal == -1)

    // if the distance to goal cannot be obtained, it returns false (when goal != -1)

    dist = vl(n, INF);

    dist[start] = 0;

    rep(i, n) rep(v, n) rep(k, graph[v].size()){

        edge e = graph[v][k];

        if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) 

            dist[e.to] = dist[v] + e.cost;

    }



    if (find_negative_cycle(n, goal, graph, dist)) return false;

    return true;

}



/*



diameter of tree

Graph tree[MAX_N];

ll dM = 0, vM = 0, v2 = 0;



void dfs1(ll source, ll parent, ll d){

    if (d > dM) dM = d, vM = source;

    

    rep(i, tree[source].size()){

        ll target = tree[source][i].to;

        if (target == parent) continue;

        dfs1(target, source, d + 1);

    }

}

 

void dfs2(ll source, ll parent, ll d){

    if (dM <= d) dM = d, v2 = source;

    rep(i, tree[source].size()){

        ll target = tree[source][i].to;

        if (target == parent) continue;

        dfs2(target, source, d + 1);

    }

}



dfs(0, -1, 0);

dfs2(vM, -1, 0);

prl2(vM + 1, v2 + 1); // the two edges of tree



*/



/*



    # 2. The usage of next_permutation and combination (factorial search)

    ll a[8];

    rep(i, 8) a[i] = i;

    sort(a, a + 8);

    do{

    }while(next_permutation(a, a+n));



    # 4. imos method

    // used when we would like to count the number which

    // shows how many times the numbers between l and r belongs to smt.

    // This method is composed of three process.

    ll n, m, s[MAX_M], l, r;

    in2(n, m);

    rep(i, m) s[i] = 0;



    // 1st step

    rep(i, n){

        in3(l, r, c);

        l--; r--; // if l starts from 1.

        s[l] += c; s[r + 1] -= c;

    }



    // 2nd step

    rep(i, m - 1) s[i + 1] += s[i];

    // 3rd step: judgement...



    #5. shakutori method (syakutori, two pointers technique)

    // 1. strech right side while the condition is met.

    // 2. renew the answer

    // 3. increments left side

    // 4. Back to 1. (l <= r must be satisfied all the time.)



    ll l = 0; ll r = 0;

    while (l < n){

        r = max(r, l);

        if (l == r) r++;

        while(r < n && cond) r++;

        answer += r - l; l++;

    }

    prl(answer);



    #11. bfs ABC146D, ABC007C

    1. first create a tree.

    2. start searching from a node.

    3. do some processes and push nodes connected with a given target node in BFS.

    4. repeat a series of procedure until queue is empty.



    queue<pl> q;



    void bfs(ll source, ll parents){

        ll n_edge = graph[source].size();

        if (parents != -1) dist[source] = min(dist[source], dist[parents] + 1);

        if (visited[source]) return;

        visited[source] = true;



        rep(idx, n_edge){

            ll target = graph[source][idx].to;

            if (target == parents) continue;

            q.push(mp(target, source)); 

        }

    }



    q.push(mp(sg.e1, -1));

    while(!q.empty()){

        pl source = q.front(); q.pop();

        bfs(source.e1, source.e2);

    }



    # Cumulative sum (2 dimension)



    ll func(ll x, ll y, ll dx, ll dy){

        if (x + dx > w || y + dy > h) return - INF;

        ll val = cum[x + dx][y + dy];

        val += cum[x][y];

        val -= cum[x][y + dy];

        val -= cum[x + dx][y];

        return val;

    }



    rep(x, w + 1) cum[x][0] = 0;

    rep(y, h + 1) cum[0][y] = 0;

    rep(y, h + 1) rep(x, w)

        cum[x + 1][y + 1] = cum[x][y + 1] + vs[x][y];



    rep(x, w + 1) rep(y, h)

        cum[x][y + 1] += cum[x][y];



*/



/*

# the operators regarding bit

& (AND), | (OR), ^ (XOR)

- (REVERSE), >> (SMALLER SHIFT)

<< (BIGGER SHIFT)





     x1: 0000 0001 0010 0101 0110 0111 0111

     x2: xxxx 0001 0011 0100 0101 1000 0110

x1 & x2: 0000 0001 0010 0100 0100 0000 0110



      x: 1001 1010  1100 1011 1101  1111

x & - x: 0001 0010  0100 0001 0001  0001

    sum: 1010 1100 10000 1100 1100 10000



x << y is x * 2 ** y

x >> y is rep(i, y) x = x // 2 



####### Attention #######

1 << i and 1LL << i is different. If programs show WA, try switch to this one.

Let S be a bit sequence and i be a non-negative integer

S & (1 << i) -> if true, i in S

S | (1 << i) -> S union {i}

S & ~(1 << i) -> S - {i}

__builtin_popcount(S) -> the number of elements in S

S = 0 -> S is an empty set

__builtin_popcountl(i) -> the number of 1 in binary

S = (1 << n) - 1 -> S includes all the elements up to the n-th



#Conditional Operator

condition ? true : false;



#iterator

type declaration: auto

value reference: *itr

increment: itr++

decrement: itr--

substitution of value: *itr = smt



# inclusion-exclusion principle

|U[i = 1 to n] Ai| = sum[i = 1 to n] |Ai| - sum[i < j]|Ai ^ Aj| + ... + (-1)^(n - 1) |^[i = 1 to n]Ai|

*/



const ll MAX_N = 200005;

bool okay = false;

ll answer = 0;

ll n, m, k;

vector<Graph> graph;



void solve(){

    /*

    ll start, ll n, vector<Graph>& graph, vl& dist,

              vl& vertex_pre, bool trace = false

    */



    graph.resize(3 * n);

    rep(i, k){

        ll a, b; in2(a, b); a--, b--;

        graph[a].pb({n + b, 1});

        graph[n + a].pb({2 * n + b, 1});

        graph[2 * n + a].pb({b, 1});

    }



    ll start, goal;

    in2(start, goal); start--, goal--;



    vl dist, _;

    dijkstra(start, graph, dist, _);

    prl(dist[goal] == INF ? -1 : dist[goal] / 3);

}



int main(void){

    in2(n, k);

    // assert(n <= 3000);

    solve();

    return 0;

}
