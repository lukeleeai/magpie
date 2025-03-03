#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

const ll MOD = 1000000007;

// const ll MOD = 998244353;

const ll INF = MOD * MOD;

const long double EPS = 1e-12;



struct mint {

    ll x;

    mint(ll x = 0): x((x % MOD + MOD) % MOD){}

    mint operator-() const {return mint(-x);}



    mint& operator+=(const mint a){

        if ((x += a.x) >= MOD) x -= MOD;

        return *this;

    }



    mint& operator-=(const mint a){

        if ((x += MOD - a.x) >= MOD) x -= MOD;

        return *this;

    }



    mint& operator*=(const mint a) {(x *= a.x) %= MOD; return *this;}

    mint operator+(const mint a) const {return mint(*this) += a;}

    mint operator-(const mint a) const {return mint(*this) -= a;}

    mint operator*(const mint a) const {return mint(*this) *= a;}



    mint pow(ll t) const{

        if (!t) return 1;

        mint a = pow(t >> 1);

        a *= a;

        if (t & 1) a *= *this;

        return a;

    }



    // for prime mod

    mint inv() const {return pow(MOD - 2);}

    mint& operator/=(const mint a) {return *this *= a.inv();}

    mint operator/(const mint a) const {return mint(*this) /= a;}

};

istream& operator>>(istream& is, const mint& a) {return is >> a.x;}

ostream& operator<<(ostream& os, const mint& a) {return os << a.x;}



struct edge {

    ll to, cost;



    tuple<ll, ll> get_value(){return make_tuple(to, cost);}

};



struct BigInt{

    string num;



    ll mod(ll _mod){

        ll l = num.length(); ll idx = 0;

        ll val = 0; ll tenth = 1;

        while (idx < l){

            ll m = num[l - 1 - idx] - '0';

            val += (m * tenth) % _mod; val %= _mod;

            tenth *= 10; tenth %= _mod; idx++;

        }

        return val;

    }



    ll digits(){return num.length();}



    bool operator<(BigInt& n2) const{

        if (num.length() < n2.digits()) return true;

        else if (num.length() > n2.digits()) return false;

        return num < n2.num;

    }



    bool operator>(BigInt& n2) const{

        if (num.length() > n2.digits()) return true;

        else if (num.length() < n2.digits()) return false;

        return num > n2.num;

    }

};



struct fpoint {

    ld x = 0; ld y = 0;

    bool operator<(const fpoint& p) const{

        if (x == p.x) return y < p.y;

        return x < p.x;

    }



    bool operator==(const fpoint& p) const{

        if (p.x - EPS < x && x < p.x + EPS

            && p.y - EPS < y && y < p.y + EPS) return true;

        return false;

    }



    bool operator!=(const fpoint& p) const{

        if (p.x - EPS > x || x > p.x + EPS

            || p.y - EPS > y || y > p.y + EPS) return true;

        return false;

    }



    fpoint& operator+=(const ld a){x += a, y += a; return *this;}

    fpoint& operator-=(const ld a){x -= a, y -= a; return *this;}

    fpoint& operator*=(const ld a){x *= a, y *= a; return *this;}

    fpoint& operator/=(const ld a){x /= a, y /= a; return *this;}

    fpoint& operator+=(const fpoint p){x += p.x, y += p.y; return *this;}

    fpoint& operator-=(const fpoint p){x -= p.x, y -= p.y; return *this;}

    fpoint& operator*=(const fpoint p){x *= p.x, y *= p.y; return *this;}

    fpoint& operator/=(const fpoint p){x /= p.x, y /= p.y; return *this;}

    fpoint operator+(const fpoint p) const {return fpoint(*this) += p;}

    fpoint operator-(const fpoint p) const {return fpoint(*this) -= p;}

    fpoint operator*(const fpoint p) const {return fpoint(*this) *= p;}

    fpoint operator/(const fpoint p) const {return fpoint(*this) /= p;}

    fpoint operator+(const ld a) const {return fpoint(*this) += a;}

    fpoint operator-(const ld a) const {return fpoint(*this) -= a;}

    fpoint operator*(const ld a) const {return fpoint(*this) *= a;}

    fpoint operator/(const ld a) const {return fpoint(*this) /= a;}

    ld dot(const fpoint& p) const {return x * p.x + y * p.y;}

    ll cross(const fpoint& p) const {return x * p.y - y * p.x;}

    ld squared_norm() const {return x * x + y * y;}

    ld norm() const {return sqrt(x * x + y * y);}

    tuple<ld, ld> get_value(){return make_tuple(x, y);}



    ll which_quadrant() const{

        if (abs(x) < EPS && abs(y) < EPS) return 0;

        if (y > 0) return x > 0 ? 1 : 2;

        return x < 0 ? 3 : 4;

    }



    bool is_zero(){

        fpoint z = {0, 0};

        return z == *this;

    }



};



struct point {

    ll x = 0; ll y = 0;

    bool operator<(const point& p) const{

        if (x == p.x) return y < p.y;

        return x < p.x;

    }



    bool operator==(const point& p) const{

        if (x == p.x && y == p.y) return true;

        return false;

    }



    bool operator!=(const point& p) const{

        if (x != p.x || y != p.y) return true;

        return false;

    }



    point& operator+=(const ll a){x += a, y += a; return *this;}

    point& operator-=(const ll a){x -= a, y -= a; return *this;}

    point& operator*=(const ll a){x *= a, y *= a; return *this;}

    point& operator+=(const point p){x += p.x, y += p.y; return *this;}

    point& operator-=(const point p){x -= p.x, y -= p.y; return *this;}

    point& operator*=(const point p){x *= p.x, y *= p.y; return *this;}

    void operator++(int){x++, y++;}

    void operator++(){x++, y++;}

    void operator--(int){x--, y--;}

    void operator--(){x--, y--;}

    point operator+(const point p) const {return point(*this) += p;}

    point operator-(const point p) const {return point(*this) -= p;}

    point operator*(const point p) const {return point(*this) *= p;}

    point operator+(const ll a) const {return point(*this) += a;}

    point operator-(const ll a) const {return point(*this) -= a;}

    point operator*(const ll a) const {return point(*this) *= a;}

    ll dot(const point& p) const {return x * p.x + y * p.y;}

    ll cross(const point& p) const {return x * p.y - y * p.x;}

    ll squared_norm() const {return x * x + y * y;}

    tuple<ll, ll> get_value(){return make_tuple(x, y);}



    ll which_quadrant() const{

        if (x == 0 && y == 0) return 0;

        if (x >= 0 && y >= 0) return 1;

        else if (x <= 0 && y >= 0) return 2;

        else if (x <= 0 && y <= 0) return 3;

        else return 4;

    }



    bool is_zero(){

        point z = {0, 0};

        return z == *this;

    }



    fpoint to_fpoint(){

        fpoint ret = {ld(x), ld(y)};

        return ret;

    }

};



struct{

    template<typename T>

    bool operator()(const T p1, const T p2) const {

        ll q1 = p1.which_quadrant();

        ll q2 = p2.which_quadrant();

        if (q1 != q2) return q1 < q2;

        // judge for parallel lines

        // if p1 cross p2 > 0 -> sin arg(p1 -> o -> p2) > 0

        return p1.cross(p2) > 0;

    }

} angle_comparator;



struct undirected_edge {

    ll from; ll to; ll cost;

    bool operator<(const undirected_edge& ue) const{return cost < ue.cost;}

    tuple<ll, ll, ll> get_value(){return make_tuple(from, to, cost);}

};



struct event{

    ll loc, val, sgn;

    bool operator<(const event& e) const{

        if (loc == e.loc) return sgn == 1;

        return loc < e.loc;

    }

    

    bool operator>(const event& e) const{

        if (loc == e.loc) return sgn == -1;

        return loc > e.loc;

    }

    

    tuple<ll, ll, ll> get_value(){return make_tuple(loc, val, sgn);}

};



typedef std::pair<ll,ll> pl;

typedef std::tuple<ll, ll, ll> tp3;

typedef std::tuple<ll, ll, ll, ll> tp4;

typedef std::vector<ll> vl;

typedef std::vector<vl> vl2;

typedef std::vector<vl2> vl3;

typedef std::vector<vl3> vl4;

typedef std::vector<mint> vmi;

typedef std::vector<vmi> vmi2;

typedef std::vector<vmi2> vmi3;

typedef std::vector<vmi3> vmi4;

typedef std::vector<bool> vb;

typedef std::vector<vb> vb2;

typedef std::vector<vb2> vb3;

typedef std::vector<vb3> vb4;

typedef std::vector<pl> vpl;

typedef std::vector<tp3> vtp3;

typedef std::vector<tp4> vtp4;

typedef std::vector<point> points;

typedef std::vector<fpoint> fpoints;

// priority queue. Taking from the higher value. Don't forget calling !q.empty()

typedef std::priority_queue<ll> pq;

// priority queue. Taking from the lower value

typedef std::priority_queue<ll, vl, greater<ll>> pql;

typedef std::vector<vector<edge>> Graph;

const ll N_DIGITS = 60;

const long double PI = 3.14159265358979323846;

const points dirs = {{-1, 0}, { 1, 0}, { 0,  1}, {0, -1},  // four directions

                     { 1, 1}, {-1, 1}, {-1, -1}, {1, -1},  // diagonal

                     { 0, 0}};  // self



template <typename A, typename B>

string to_string(pair<A, B> p);

template <typename A, typename B, typename C>

string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>

string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {return '"' + s + '"';}

string to_string(char c){return string(1, c);}

string to_string(const char* s) {return to_string((string) s);}

string to_string(bool b){return (b ? "true" : "false");}

string to_string(mint a){return to_string(a.x);}

string to_string(point p){return "{" + to_string(p.x) + ", " + to_string(p.y) + "}";}

string to_string(fpoint p){return "{" + to_string(p.x) + ", " + to_string(p.y) + "}";}

template <typename A, typename B>

string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}

template <typename A, typename B, typename C>

string to_string(tuple<A, B, C> p){return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}

template <typename A, typename B, typename C, typename D>

string to_string(tuple<A, B, C, D> p){return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}

string to_string(vector<bool> v) {

  bool first = true;

  string res = "{";

  for (int i = 0; i < static_cast<int>(v.size()); i++) {

    if (!first) res += ", ";

    first = false;

    res += to_string(v[i]);

  }

  res += "}";

  return res;

}



template <size_t N>

string to_string(bitset<N> v) {

  string res = "";

  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);

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



template<typename T>

string to_string(priority_queue<T>& q){

    priority_queue<T> copy;

    bool first = true;

    string res = "{";

    while(!q.empty()){

        if (!first) {

            res += ", ";

        }

        first = false;

        res += to_string(q.top());

        copy.push(q.top());

        q.pop();

    }



    swap(q, copy);

    res += "}";

    return res;

}





void debug_out() {cerr << endl;}



template <typename Head, typename... Tail>

void debug_out(Head H, Tail... T){

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

#define mt make_tuple

#define pr(a) std::cout << (a)

#define prl(a) std::cout << (a) << endl

#define prl2(a,b) std::cout << (a) << " " << (b) << endl

#define prl3(a,b,c) std::cout << (a) << " " << (b) << " " << (c) << endl

#define prl4(a,b,c,d) std::cout << (a) << " " << (b) << " " << (c) << " " << (d) << endl

#define prs(a) std::cout << (a) << " "

#define prs2(a,b) std::cout << (a) << " " << (b) << " "

#define prs3(a,b,c) std::cout << (a) << " " << (b) << " " << (c) << " "

#define prs4(a,b,c,d) std::cout << (a) << " " << (b) << " " << (c) << " " << (d) << " "

#define yn(condition) if ((condition)) prl("Yes"); else prl("No");

#define YN(condition) if ((condition)) prl("YES"); else prl("NO");

#define in1(a) cin >> (a)

#define in2(a,b) cin >> (a) >> (b)

#define in3(a,b,c) cin >> (a) >> (b) >> (c)

#define in4(a,b,c,d) cin >> (a) >> (b) >> (c) >> (d)

#define in5(a,b,c,d,e) cin >> (a) >> (b) >> (c) >> (d) >> (e)

#define in6(a,b,c,d,e,f) cin >> (a) >> (b) >> (c) >> (d) >> (e) >> (f)

#define in7(a,b,c,d,e,f,g) cin >> (a) >> (b) >> (c) >> (d) >> (e) >> (f) >> (g)

#define e1 first

#define e2 second

#define Forchar(c,a,z) for(char (c) = (a); (c) <= (z); (c)++)

#define cntchar(s,c) count(all((s)), c)

#define substring(s, start, end) s.substr((start), (end) - (start) + 1)

#define prl_nd(num, digits) std::cout << fixed << setprecision(digits) << (num) << endl;

#define prl_time(s) prl3("Elapsed Time:", 1000.0 * (clock() - s) / CLOCKS_PER_SEC, "[ms]");

#define char_to_str(c) string(1, (c))



#ifdef _LOCAL

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

#else

#define debug(...) 42

#endif



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

            // then assign current flow.

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



struct UnionFind {

    vl parents, set_size;

    set<ll> root_idx;

    ll n_groups;



    UnionFind(ll n){

        parents = set_size = vl(n);

        n_groups = n;

        rep(i, n){

            parents[i] = i;

            set_size[i] = 1LL;

            root_idx.insert(i);

        }

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

        root_idx.erase(y);

        n_groups--;

    }



    // connected or not

    bool is_same(ll x, ll y){return root_find(x) == root_find(y);}

    ll size(ll x){return set_size[root_find(x)];}

    ll num_union() const{return n_groups;}

};



struct WeightedUnionFind{

    vl parents, set_size, weights;

    set<ll> root_idx;

    ll n_groups;



    WeightedUnionFind(ll n){

        parents = set_size = weights = vl(n);

        n_groups = n;

        rep(i, n){

            parents[i] = i;

            set_size[i] = 1LL;

            weights[i] = 0;

            root_idx.insert(i);

        }

    }



    ll root_find(ll x){

        if (parents[x] == x) return x;

        ll r = root_find(parents[x]);

        weights[x] += weights[parents[x]];

        return parents[x] = r;

    }



    ll weight(ll x){

        root_find(x);

        return weights[x];

    }



    void unite(ll x, ll y, ll w){

        // priority for x is larger than that of y

        w += weight(x) - weight(y);

        x = root_find(x); y = root_find(y);

        if (x == y) return;

        parents[y] = x, set_size[x] += set_size[y];

        root_idx.erase(y);

        weights[y] = w;

        n_groups--;

    }



    // connected or not

    bool is_same(ll x, ll y){return root_find(x) == root_find(y);}

    ll size(ll x){return set_size[root_find(x)];}

    ll num_union() const{return n_groups;}

    ll difference(ll x, ll y){return weight(y) - weight(x);}

};



struct Doubling { // ABC167D

    ll n;

    ll sz;

    vl2 next;

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



template<class T>

class LowestCommonAncestor{

public:

    ll N, logN;

    vl depth, len;

    T tree;

    vl2 parents;



    LowestCommonAncestor(ll n, T& _tree){

        N = n;

        logN = 0;

        while (N > (1LL << logN)) logN++;

        depth = len = vl(N);

        parents = vl2(logN, vl(N));

        tree = _tree;

        init(0, -1, 0, 0);

        build();

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

    ll n, ini; vl dat;

    BinaryIndexedTree(ll n, ll ini = 0):

        dat(n + 1, ini), n(n), ini(ini){};



    //       x: 1001 1010  1100 1011 1101  1111

    // x & - x: 0001 0010  0100 0001 0001  0001

    //      ->: 1010 1100 10000 1100 1100 10000



    ll update_func(ll val, ll d){

        // if maximum -> max(val, dat)

        // return max(val, d);

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



        if (i < 0) return ini;

        ll ret = 0;

        for (ll j = i; j >= 0; j = (j & (j + 1)) - 1){

            ret = update_func(ret, dat[j]);

        }

        return ret;

    }



    ll query(ll l, ll r){

        // a[l] + a[l + 1] + ... + a[r - 1] + a[r]

        return query(r) - query(l - 1);

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

        vb visited(n, false);

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



    // This is the exaple of the number of children

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

    ll n, n_cmp;

    // dag: edges from a cmp to another cmp

    vl2 graph, graph_rev, dag, cmp;

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

        return n_cmp = num;

    }



    bool in_loop(ll v){return cmp[cmp_idx[v]].size() > 1;}



    bool has_loop(){

        rep(i, cmp.size()) if (cmp[i].size() > 1) return true;

        return false;

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



    ll nPk(ll n, ll r){

        if (n == r && n == 0) return 1;

        else if (n <= 0 || r < 0 || r > n) return 0;

        ll val = (facts[n] * facts_inv[n - r]) % mod;

        return val % mod;

    }

};



struct PowerMemo{

    ll sz, mod, base;

    vl powB;



    PowerMemo(ll sz, ll base, ll _mod):

        sz(sz), base(base), mod(_mod){

            powB.resize(sz + 5);

            init();

        }



    void init(){

        powB[0] = 1;

        rep(i, sz + 3)

            powB[i + 1] = (powB[i] * base) % mod;

    }



    ll operator[](ll k){

        return powB[k];

    }

};



struct Grid2D{

    Graph graph;

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



    bool undefined_region(point p, vb2& block){

        if (p.x < 0 || p.x > Width - 1) return true;

        if (p.y < 0 || p.y > Height - 1) return true;

        if (block[p.x][p.y]) return true;

        return false;

    }



    void build(vb2& block, ll val = 1){

        rep(x, Width) rep(y, Height){

            point p = {x, y};

            ll idx1 = pos_to_idx(p); ll idx2;



            if (block[x][y]) continue;

            rep(i, 4){

                point nxt = p + dirs[i];

                idx2 = pos_to_idx(nxt);

                if (!undefined_region(nxt, block))

                    graph[idx1].pb({idx2, val}); // dist[idx1][idx2] = val; (warshall-floyd)

            }

        }

    }

};



struct Cumulative2D{

    vl2 cum;

    ll w, h;



    Cumulative2D(ll w, ll h) : w(w), h(h){

        cum = vl2(w + 1, vl(h + 1, 0));

    }



    template<typename T>

    void build(vector<T>& vec){

        // never forget building

        rep(x, w + 1) cum[x][0] = 0;

        rep(y, h + 1) cum[0][y] = 0;

        rep(y, h) rep(x, w)

            cum[x + 1][y + 1] = cum[x][y + 1] + vec[x][y];

        rep(x, w + 1) rep(y, h)

            cum[x][y + 1] += cum[x][y];

    }



    ll func(ll x, ll y, ll dx, ll dy){

        // 1-indexed

        // the rectangle of (x, y), (x + dx, y), (x, y + dy) and (x + dx, y + dy)

        // think about the case of (1, 1, 1, 1).

        if (x + dx > w || y + dy > h) return - INF;

        ll val = cum[x + dx][y + dy];

        val += cum[x][y];

        val -= cum[x][y + dy];

        val -= cum[x + dx][y];

        return val;

    }

};



ll gcd(ll m, ll n){

    ll a = max(m, n);

    ll b = min(m, n);

    while(b != 1 && b != 0){ a %= b; swap(a, b);}

    return b == 1 ? 1 : a;

}



ll lcm(ll m, ll n){ return m / gcd(m, n) * n;}



ll power_normal(ll a, ll power){

    ll value = 1;

    while(power != 0){

        if(power & 1) value = value * a;

        a = a * a;

        power = power >> 1;

    }

    return value;

}



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



vl2 pascal_triangle(ll n){

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



    vl2 comb(n + 1, vl(n + 1));

    comb[0][0] = 1;

    For(i, 1, n + 1) rep(j, i + 1){

        comb[i][j] += comb[i - 1][j];

        if (j > 0) comb[i][j] += comb[i - 1][j - 1];

    }



    return comb;

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



string bin_expression(ll n, ll dig){

    string s = "";

    rep(i, dig){

        s += to_string(n % 2);

        n /= 2;

    }

    reverse(all(s));

    return s;

}



bool is_prime(ll n){

    if (n <= 1) return false;

    for(ll i = 2; i * i <= n; i++){

        if (n % i == 0) return false;

    }

    return true;

}



map<ll, ll> prime_factorization(ll n){

    ll i = 2;

    map<ll, ll> table;

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



ll next_combination(ll sub){

    /*

    nCk

    ll bit = (1 << k) - 1;

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



    if (x != 0)

        return (((sub & ~y) / x) >> 1) | y;

    else

        return INF;

}



// just change the input if you want to change the target.

// If you want to check the common sequences in two strings,

// combine them. e.g. ABC150F

template<typename T>

vl z_algorithm(T& s, ll n){

    /*

    Paramters

    ---------

    T: the string or list of interest

    n: the size of string or list



    Returns

    -------

    res[i] is the maximum number of K which satisfies

    s[:K] == s[i:i + K]

    for each i = 0, 1, 2, ..., n - 1.

    */

    vl res(n);

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



ll string_to_ll(string s){

    ll l = s.length(); ll idx = 0;

    ll val = 0; ll tenth = 1;

    while (idx < l){

        ll m = s[l - 1 - idx] - '0';

        val += (m * tenth);

        tenth *= 10; idx++;

    }



    return val;

}



string reflected_string(string s){

    string t, u; ll n = s.length();

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



template<typename T>

bool isColinear(T p1, T p2, T p3){

    T v1 = p2 - p1, v2 = p3 - p1;

    return v1.x * v2.y == v1.y * v2.x;

}



template<typename T>

T PerpendicularBisector(T p1, T p2){

    T vec = p2 - p1;

    assert(!vec.is_zero());

    T ret = {vec.y, -vec.x};



    return ret;

}



template<typename T>

ld Distance2DPoints(T p1, T p2){

    T vec = (p1 - p2) * (p1 - p2);

    return sqrt(vec.x + vec.y);

}



ll SquaredDistance2DPoints(point p1, point p2){

    point vec = (p1 - p2) * (p1 - p2);

    return vec.x + vec.y;

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



pair<point, ll> OuterCenter(point p1, point p2, point p3){

    // the center of circle on the given three points

    // return the determinant value and the product of center points and 2 * determinant value

    point ret;



    if (isColinear(p1, p2, p3)){

        ll d1 = SquaredDistance2DPoints(p1, p2);

        ll d2 = SquaredDistance2DPoints(p2, p3);

        ll d3 = SquaredDistance2DPoints(p3, p1);

        if (d1 >= d2 && d1 >= d3) {ret = p1 + p2; return mp(ret, 2);}

        else if (d2 >= d1 && d2 >= d3) {ret = p2 + p3; return mp(ret, 2);}

        else {ret = p3 + p1; return mp(ret, 2);}

    }



    point pv1 = PerpendicularBisector(p1, p2);

    point pv2 = PerpendicularBisector(p1, p3);

    point cv1_2x = p1 + p2, cv2_2x = p1 + p3;

    // cv1 + k pv1 == cv2 + m pv2

    // (pv1x -pv2x) (k) = (cv2x - cv1x)

    // (pv1y -pv2y) (m) = (cv2y - cv1y)

    ll det_inv = - pv1.x * pv2.y + pv1.y * pv2.x;

    ll x1_2x = cv2_2x.x - cv1_2x.x, x2_2x = cv2_2x.y - cv1_2x.y;

    pl c_2x_det = {-pv2.y * x1_2x + pv2.x * x2_2x, -pv1.y * x1_2x + pv1.x * x2_2x};

    

    // ret.x = ld(cv1_2x.x * det_inv + pv1.x * c_2x_det.e1) / ld(2 * det_inv);

    // ret.y = ld(cv1_2x.y * det_inv + pv1.y * c_2x_det.e1) / ld(2 * det_inv);

    ret.x = cv1_2x.x * det_inv + pv1.x * c_2x_det.e1;

    ret.y = cv1_2x.y * det_inv + pv1.y * c_2x_det.e1;



    ll jacobian = 2 * det_inv;

    return mp(ret, jacobian);

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

        // by subtracting these two, the residual number is the number of elements that have larger value.

        val += i - bit.query(a[i] - 1);// cumulative sum from 0 to a[i] - 1

        bit.update(a[i], 1);

    }

    return val;

}



ld bin_search(ld left, ld right, bool lb, function<bool(ld)> judge){

    ld mid;

    while(right - left > EPS){

        mid = (right + left) / 2;

        if (lb){

            if (judge(mid)) right = mid;

            else left = mid + EPS;

        }else{

            if (judge(mid)) left = mid;

            else right = mid - EPS;

        }

    }

    return right;

}



ll bin_search(ll left, ll right, bool lb, function<bool(ll)> judge){

    ll mid;

    while(right > left){

        if (lb){

            // if true (satisfies the condition), range shifts smaller direction

            mid = (right + left) / 2;

            if (judge(mid)) right = mid;

            else left = mid + 1;

        }else{

            // if true (satisfies the condition), range shitfs larger direction

            mid = (right + left + 1) / 2;

            if (judge(mid)) left = mid;

            else right = mid - 1;

        }

    }

    return right;

}



ld trinary_search(ld left, ld right, function<ld(ld)> func){

    // Care the value EPS!!! Compare to the condition

    while(abs(right - left) > EPS){

        ld left2 = (2.0 * left + right) / 3.0;

        ld right2 = (left + 2.0 * right) / 3.0;

        ld f1 = func(left2);

        ld f2 = func(right2);

        if (f1 <= f2) right = right2;

        else if (f2 <= f1) left = left2;

    }



    return right;

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

        for (j = 0; j < n; j++) if (j != rank) bs[j] = min(bs[j], bs[j] ^ bs[rank]);

        rank++;

    }

}



ll kruskal(vector<undirected_edge>& es, ll n_vertex){

    // O(ElogE)

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



ll LongestIncreasedSequence(vl& v){

    ll n = v.size();

    vl dp(n, INF);

    rep(i, n)

        *lower_bound(all(dp), v[i]) = v[i];

    return lower_bound(all(dp), INF) - dp.begin();

}



void dijkstra(ll start, Graph& graph, vl& dist,

              vl& vertex_pre, bool trace = false){

    priority_queue<pl, vpl, greater<pl>> edge_costs;

    ll n = graph.size();

    dist = vl(n, INF);

    if (trace) vertex_pre = vl(n, -1);

    dist[start] = 0;

    edge_costs.push(pl(0, start));



    while (!edge_costs.empty()){

        ll idx, cost;

        tie(cost, idx) = edge_costs.top();

        edge_costs.pop();

        if (dist[idx] < cost) continue;



        for (auto e: graph[idx]){

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



void warshall_floyd(vl2& dist){

    ll n = dist.size();

    // Dont forget the initialization

    // rep(i, n) rep(j, n) dist[i][j] = INF * (i != j);

    rep(k, n) rep(i, n) rep(j, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

}



// ABC061D

bool find_negative_cycle(ll n, ll goal, Graph& graph, vl& dist){

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



bool bellman_ford(ll start, ll goal, Graph& graph, vl& dist){

    // if there is a closed circuit, it returns false. (when goal == -1)

    // if the distance to goal cannot be obtained, it returns false (when goal != -1)

    ll n = graph.size();

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



void Euler_Tour(Graph& tree, vl& euler_tour, vl& in, vl& out, ll anc = 0){

    // record only when we first reach a node and leave the node.

    ll n = tree.size();

    vb visited(n, false);

    in = out = vl(n);



    auto dfs = [&](auto dfs, ll source) -> void{

        visited[source] = true;

        in[source] = euler_tour.size();

        euler_tour.pb(source);



        bool is_leaf = true;

        for (auto& e: tree[source]){

            ll target = e.to;

            if (visited[target]) continue;

            else is_leaf = false;

            dfs(dfs, target);

        }

        

        euler_tour.pb(- source);

        out[source] = euler_tour.size() - 1;

    };



    dfs(dfs, anc);

}



void Euler_Tour2(Graph& tree, vl& euler_tour, vl& in, vl& out, ll anc = 0){

    // record everytime we reach a node

    ll n = tree.size();

    vb visited(n, false);

    in = out = vl(n);



    auto dfs = [&](auto dfs, ll source) -> void{

        visited[source] = true;

        in[source] = euler_tour.size();

        euler_tour.pb(source);



        bool is_leaf = true;

        for (auto& e: tree[source]){

            ll target = e.to;

            if (visited[target]) continue;

            else is_leaf = false;

            dfs(dfs, target);

            euler_tour.pb(source);

        }



        out[source] = euler_tour.size() - 1;

    };



    dfs(dfs, anc);

}



std::mt19937 create_rand_engine(){

    std::random_device rnd;

    std::vector<std::uint_least32_t> v(10);

    std::generate(v.begin(), v.end(), std::ref(rnd));

    std::seed_seq seed(v.begin(), v.end());

    return std::mt19937(seed);

}





vl generate_unique_array(const size_t sz, ll vm, ll vM){

    const size_t range = static_cast<size_t>(vM - vm + 1);

    const size_t num = static_cast<size_t>(sz * 1.2);

    assert(vm <= vM);

    assert(sz <= range);



    vl ret;

    auto engine = create_rand_engine();

    std::uniform_int_distribution<ll> distribution(vm, vM);



    while (ret.size() < sz){

        while (ret.size() < num) ret.pb(distribution(engine));

        sort(all(ret));



        auto unique_end = unique(all(ret));

        if (sz < distance(ret.begin(), unique_end)) 

            unique_end = next(ret.begin(), sz);



        ret.erase(unique_end, ret.end());

    }



    return ret;

}



vl generate_array(const size_t sz, ll vm, ll vM){

    const size_t range = static_cast<size_t>(vM - vm + 1);

    assert(vm <= vM);



    vl ret;

    auto engine = create_rand_engine();

    std::uniform_int_distribution<ll> distribution(vm, vM);



    while (ret.size() < sz)

        ret.pb(distribution(engine));



    return ret;

}



void read_vector(ll n, vl& v, ll offset = 0){

    v.resize(n);

    rep(i, n){

        in1(v[i]);

        v[i] += offset;

    }

}



void read_points(ll n, points& ps, ll offset = 0){

    ps.resize(n);

    rep(i, n){

        ll x, y; in2(x, y);

        ps[i] = {x, y};

        ps[i] += offset;

    }

}



void read_2DMap(ll w, ll h, vb2& block, char b){

    block = vb2(w, vb(h, false));

    string s;

    rep(y, h){

        in1(s);

        rep(x, w) block[x][y] = (s[x] == b);

    }

}



/*



diameter of tree

Graph tree;

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

    #5. shakutori method (syakutori, two pointers technique)

    // 1. strech right side while the condition is met.

    // 2. renew the answer

    // 3. increments left side

    // 4. Back to 1. (l <= r must be satisfied all the time.)



    ll l = 0; ll r = 0;

    while (l < n){

        if (l == r) r++;

        while(r < n && cond) r++;

        l++;

    }

    prl(answer);



    #11. bfs ABC146D, ABC007C

    1. first create a graph.

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

*/



/*

     x1: 0000 0001 0010 0101 0110 0111 0111

     x2: xxxx 0001 0011 0100 0101 1000 0110

x1 & x2: 0000 0001 0010 0100 0100 0000 0110



      x: 1001 1010  1100 1011 1101  1111

x & ~ x: 0001 0010  0100 0001 0001  0001

    sum: 1010 1100 10000 1100 1100 10000



####### Attention #######

S & (1 << i) -> if true, i in S

S | (1 << i) -> S union {i}

S & ~(1 << i) -> S - {i}

__builtin_popcountl(i) -> the number of 1 in binary



#Conditional Operator

condition ? true : false;



# inclusion-exclusion principle

|U[i = 1 to n] Ai| = sum[i = 1 to n] |Ai| - sum[i < j]|Ai ^ Aj| + ... + (-1)^(n - 1) |^[i = 1 to n]Ai|

*/



const ll MAX_N = 200005;

const size_t MAX_BIT = 160 * 160 + 10;

typedef bitset<MAX_BIT> bts;

typedef vector<bts> vbt;

typedef vector<vbt> vbt2;

typedef vector<vbt2> vbt3;



struct LinearSystemIncidence{

    struct Edge{ll idx, to; bool fwd;};

    /*

    Ax = c

    A: A in R^(V * E) <- given

    x: x in R^E <- estimate this

    c: c in R^V <- given

    */

    ll n_vertex, n_edge;

    bool mod2;

    vl x;

    vb visited;

    vector<vector<Edge>> graph;

  

    LinearSystemIncidence(ll n, vpl& es, bool mod2 = false) : 

        n_vertex(n), n_edge(es.size()), mod2(mod2){

        graph.resize(n); visited.resize(n);

        rep(i, n_edge){

            auto& e = es[i];

            graph[e.e1].pb({i, e.e2, true});

            graph[e.e2].pb({i, e.e1, false});

        }

    }

 

    ll dfs(vl& c, ll src){

        visited[src] = true;

        ll ret = c[src];

        for (Edge& e : graph[src]){

            if (visited[e.to]) continue;

            ll tmp = dfs(c, e.to);

            x[e.idx] = e.fwd ? tmp : -tmp;

            ret += tmp;

            if (mod2) x[e.idx] = ((x[e.idx] % 2) + 2) % 2;

        }

        return mod2 ? ret % 2 : ret;

    }

 

    bool solve(vl& c){

        x.assign(n_edge, 0);

        visited.assign(n_vertex, false);

        rep(src, n_vertex){

            if (visited[src]) continue;

            if (dfs(c, src)) return false;

        }

        return true;

    }

};



void solve(){

    // generate_array(size, min, max);



    ll n, m;

    in2(n, m);

    vpl es(m); vl c(n);

    rep(i, m){

        ll u, v; in2(u, v); u--, v--;

        es[i] = {u, v};

        c[u] ^= 1;

    }



    LinearSystemIncidence lsi(n, es, true);

    if (lsi.solve(c)){

        rep(i, m){

            if (lsi.x[i]) swap(es[i].e1, es[i].e2);

            prl2(es[i].e1 + 1, es[i].e2 + 1);

        }

    }else prl(-1);



    



    // ### DEBUG PART ###

    auto naive_solver = [&](){



    };

    #ifdef _LOCAL

        naive_solver();

    #endif

}



void test(ll num = 0, bool verbose = false){

    rep(i, max(1LL, num)){

        ll t = clock();

        if (verbose) prl4("\n#####", i + 1, "#####", "\n## Answer ##");

        solve();

        if (verbose) {prl(""); prl_time(t);}

    }

}



int main(void){

    #ifdef _LOCAL

        test(6, true);

    #else

        test(0, false);

    #endif



    return 0;

}
