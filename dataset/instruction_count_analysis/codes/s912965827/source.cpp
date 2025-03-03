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

#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

using edge = struct {ll to; ll cost;};

using point = struct {ll x; ll y;};

typedef string str;

typedef std::pair<ll,ll> pl;

typedef std::pair<ll,pl> pl3;

typedef std::map<string, ll> msl;

typedef std::map<char, ll> mcl;

typedef std::map<ll, ll> mll;

typedef std::vector<ll> vl;

typedef std::vector<pl> vpl;

typedef std::vector<point> vxy;

typedef std::vector<pl3> vpl3;

typedef std::priority_queue<ll> pq;

typedef std::priority_queue<ll, vl, greater<ll>> pql; // priority queue taking from the lower value.

typedef std::vector<edge> gr;

const ll MOD = 1e9 + 7;

const ll INF = MOD * MOD;

const long double EPS = 1e-9;

const long double PI = 3.14159265358979323846;



#define rep(i, n) for(ll (i) = 0; (i) < (n) ; (i)++ )

#define revrep(i, n) for(ll (i) = n - 1; (i) >= 0 ; (i)--)

#define For(i, a, b) for(ll (i) = (a); (i) < (b) ; (i)++ )

#define revFor(i, b, a) for(ll (i) = (b) - 1; (i) >= (a) ; (i)--)

#define all(a) (a).begin(), (a).end()

#define rall(a) (a).rbegin(), (a).rend()

#define isUpper(c) ('a' - c > 0)

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



class UnionFind {

    vl parents, set_size;

public:

    UnionFind(){}

    UnionFind(ll n){

        parents = set_size = vl(n);

        rep(i, n) {parents[i] = i; set_size[i] = 1LL;}

    }



    ll root_find(ll x){

        if (parents[x] == x) return x;

        return parents[x] = root_find(parents[x]);

    }



    void unite(ll x, ll y){

        x = root_find(x); y = root_find(y);

        if (x == y) return;

        if (set_size[x] < set_size[y]){

            parents[y] = x; set_size[x] += set_size[y];

        }else{

            parents[x] = y; set_size[y] += set_size[x];

        }

    }



    bool is_same(ll x, ll y) {// connected or not

        return root_find(x) == root_find(y);

    }



    ll size(ll x) {

        return set_size[root_find(x)];

    }

};



/*

class LCA{

public:

    ll N, logN;

    vl depth, len;

    gr tree[200005]; // global declaration later.

    vector<vl> parents;



    LCA(ll n){

        N = n;

        logN = 0;

        while (N > (1LL << logN)) logN++;

        depth = vl(N); len = vl(N);

        parents = vector<vl>(logN, vl(N));

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

*/



struct BIT{

    ll n; vl dat;

    BIT(ll n): dat(n + 1), n(n){};



    //       x: 1001 1010  1100 1011 1101  1111

    // x & - x: 0001 0010  0100 0001 0001  0001

    //      ->: 1010 1100 10000 1100 1100 10000



    ll sum(ll i){

        ll s = 0;

        while(i > 0){s += dat[i]; i -= i & -i;}

        return s;

    }



    ll sum(ll i, ll j){

        return sum(j - 1) - sum(i - 1);

    }



    void add(ll i, ll x){

        while(i <= n){dat[i] += x; i += i & -i;}

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



ll comb_memo[55][55];



ll pascal_triangle(ll n){

    comb_memo[0][0] = 1;

    For(i, 1, n + 1) rep(j, i + 1){

        comb_memo[i][j] += comb_memo[i - 1][j];

        if (j > 0) comb_memo[i][j] += comb_memo[i - 1][j - 1];

    }

}



ll combination(ll n, ll r, ll mod){

    if (n == r && n == 0) return 1;

    else if (n <= 0 || r < 0 || r > n) return 0;

    ll numerator = 1;

    ll denomenator = 1;

    for(ll i = 0; i < r ; i++){

        (numerator *= ll(n - i)) %= mod;

        (denomenator *= modinv(i + 1, mod)) %= mod;

    }



    return (numerator * denomenator) % mod;

}



ll combination_memo(ll n, ll r, ll pre, ll mod){

    if (n == r && n == 0) return 1;

    else if (n <= 0 || r < 0 || r > n) return 0;

    ll numerator = ll(n - r + 1) % mod;

    ll denomenator = modinv(r, mod) % mod;

    ll val = (numerator * denomenator) % mod;

    val *= pre;

    return val % mod;

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

*/



ll lower_bound_bin_search_temp(ll key, ll A[], ll left, ll right){

    // Pay attention to the return value -1.

    // For example, sometimes you may want the value right instead of -1.

    if (A[left] >= key) return left;

    ll mid = left + (right - left) / 2;



    while(right >= left){

        mid = left + (right - left) / 2;

        if (mid == left) {

            if (A[left] < key && key <= A[left + 1]) return left + 1;

            else return -1;

        }

        if (A[mid - 1] < key && key <= A[mid]) return mid;

        else if (A[mid - 1] >= key) right = mid - 1;

        else if (A[mid] < key) left = mid;

    }



    return -1; // all the elements < key

}



ll inf_bin_search_temp(ll key, ll A[], ll left, ll right){

    // Pay attention to the return value -1.

    // For example, sometimes you may want the value right instead of -1.

    if (A[left] > key) return left;

    ll mid = left + (right - left) / 2;



    while(right >= left){

        mid = left + (right - left) / 2;

        if (mid == left) {

            if (A[left] <= key && key < A[left + 1]) return left + 1;

            else return -1;

        }

        if (A[mid - 1] <= key && key < A[mid]) return mid;

        else if (A[mid - 1] > key) right = mid - 1;

        else if (A[mid] <= key) left = mid;

    }



    return -1; // all the elements <= key

}



ll upper_bound_bin_search_temp(ll key, ll A[], ll left, ll right){

    // Pay attention to the return value -1.

    // For example, sometimes you may want the value left instead of -1.

    if (A[right] <= key) return right;

    ll mid = left + (right - left) / 2;



    while(right >= left){

        mid = left + (right - left) / 2;

        if (mid == right) {

            if (A[right - 1] <= key && key < A[right]) return right - 1;

            else return -1;

        }

        if (A[mid] <= key && key < A[mid + 1]) return mid;

        else if (A[mid] > key) right = mid;

        else if (A[mid + 1] <= key) left = mid + 1;

    }



    return -1; // all the elements > key

}



ll sup_bin_search_temp(ll key, ll A[], ll left, ll right){

    // Pay attention to the return value -1.

    // For example, sometimes you may want the value left instead of -1.

    if (A[right] < key) return right;

    ll mid = left + (right - left) / 2;



    while(right >= left){

        mid = left + (right - left) / 2;

        if (mid == right) {

            if (A[right - 1] < key && key <= A[right]) return right - 1;

            else return -1;

        }

        if (A[mid] < key && key <= A[mid + 1]) return mid;

        else if (A[mid] >= key) right = mid;

        else if (A[mid + 1] < key) left = mid + 1;

    }



    return -1; // all the elements >= key

}



ll bin_search_vector(ll key, vl v, ll left, ll right){

    // return the index idx where v[idx] = key.

    // v[left] is start and v[right] is end..

    // In other words, v[right], not v[right - 1], must be defined.

    while(right >= left){

        ll mid = left + (right - left) / 2;

        if (v[mid] == key) return mid;

        else if (v[mid] > key) right = mid - 1;

        else if (v[mid] < key) left = mid + 1;

    }

    return -1;

}



ll lower_bound_bin_search_vector(ll key, vl v){

    // the return value N satisfies

    // v[N - 1] < key <= v[N]

    // N == -1 if all the elements < key

    return lower_bound(all(v), key) - v.begin();

}



ll inf_bin_search_vector(ll key, vl v){

    // the return value N satisfies

    // v[N - 1] <= key < v[N] <= key + 1

    // N == -1 if all the elements <= key

    return lower_bound(all(v), key + 1) - v.begin();

}



ll upper_bound_bin_search_vector(ll key, vl v){

    // the return value N satisfies

    // v[N] <= key < v[N + 1]

    // N == -1 if all the elements > key

    return upper_bound(all(v), key) - v.begin() - 1;

}



ll sup_bin_search_vector(ll key, vl v){

    // the return value N satisfies

    // v[N] <= key - 1 < key <= v[N + 1]

    // N == -1 if all the elements >= key

    return upper_bound(all(v), key - 1) - v.begin() - 1;

}



ll fact(ll n){

    if (n == 0) return 1;

    return n * fact(n - 1);

}



bool is_prime(ll n){

    if (n <= 1) return false;

    for(ll i = 2; i * i <= n; i++){

        if (n % i == 0) return false;

    }

    return true;

}



ll bool_sum(ll a1, ll a2){

    if (a1 == 1 || a2 == 1) return 1;

    return 0;

}



mll prime_decomposition(ll n){

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



ll char_to_idx(char c){

    ll idx = 0;

    Forchar(cc, 'a', 'z'){

        if (c == cc) return idx;

        else idx ++;

    }

}



bool is_cross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4){

    ll val1 = (x1 - x2) * (y3 - y1) + (y1 - y2) * (x1 - x3);

    ll val2 = (x1 - x2) * (y4 - y1) + (y1 - y2) * (x1 - x4);

    ll val3 = (x3 - x4) * (y1 - y3) + (y3 - y4) * (x3 - x1);

    ll val4 = (x3 - x4) * (y2 - y3) + (y3 - y4) * (x3 - x2);



    return val1 * val2 < 0 && val3 * val4 < 0;

}



/*

const ll N_VERTEX = 310;

ll a, b, t;

ll dist[N_VERTEX][N_VERTEX];



void warshall_floyd(ll n){

    // rep(i, n) rep(j, n) dist[i][j] = INF * (i != j);

    rep(k, n) rep(i, n) rep(j, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

}



int main(void){

    in2(n, m);

    rep(i, n) rep(j, n) dist[i][j] = INF * (i != j);

    rep(i, m){

        in3(a, b, t);

        a--; b--;

        dist[a][b] = t;

        dist[b][a] = t;

    }



    warshall_floyd(n);

}



const ll N_VERTEX = 310;

gr graph[N_VERTEX];

ll dist[N_VERTEX], a, b, t, n, m;



void dijkstra(ll start, ll n) {

    priority_queue<pl, vector<pl>, greater<pl>> edge_costs;

    fill(dist, dist + n, INF);

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

                edge_costs.push(pl(dist[e.to], e.to));

            }

        }

    }

}



int main(void){

    in2(n, m);

    rep(i, m){

        in3(a, b, t);

        a--; b--;

        G[a].pb({b, t});

        G[b].pb({a, t});

    }



    dijkstra(0, n);

}





# ABC061D



bool bellman_ford(ll start, ll n, ll goal){

    // if there is a closed circuit, it returns false. (when goal == -1)

    // if the distance to goal cannot be obtained, it returns false (when goal != -1)

    fill(dist, dist + n, INF);

    dist[start] = 0;

    rep(i, n) rep(v, n) rep(k, graph[v].size()){

        edge e = graph[v][k];

        if (dist[e.to] > dist[v] + e.cost){

            dist[e.to] = dist[v] + e.cost;

            if (i == n - 1 && (e.to == goal || goal == -1)) return false;

        }

    }

    return true;

}



*/



/*

    # 1. The usage of map pair

    map<pl, ll> cnt;

    cnt[{i, j}] = 0;

    items(kv, cnt){

        prl2(kv.first, kv.second);

    }



    # 2. The usage of next_permutation and combination (factorial search)

    ll a[8];

    rep(i, 8) a[i] = i;

    sort(a, a + 8);

    do{

    }while(next_permutation(a, a+n));



    // here, combination

    ll n, r;

    ll i1, i2, ..., ir;

    For(i1, n - r, n) For(i2, n - r - 1, i1) ... For(ir, n - 2 * r + 1, irr){ process;}



    # 3. bit search

    ll n;

    in1(n);

    const ll base = 3;

    ll upper = power_normal(base, n);

    

    rep(i, upper){

        ll tmp = i;

        rep(j, n){

            rep(k, base) if (tmp % base == k) prl(k);

            tmp /= base;

        }

    }



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



    #5. shakutori method (syakutori)

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



    #6. priority queue



    pq q;

    ll answer = 0;

    ll v;



    rep(i, n) q.push(a[i]);

    rep(i, m){

        v = q.top(); q.pop(); // get the top value and dump the value from queue

        v /= 2; q.push(v); // add the new value

    }



    while(!q.empty()){

        answer += q.top();

        q.pop();

    }



    #7. The shortest path between the k-th edge and another edge (Tree)

    ll depth[MAX_N];

    gr tree[MAX_N];



    void path(ll source, ll parent, ll all_cost){

        depth[source] = all_cost;

        items(e, tree[source]){

            if (e.to == parent) continue;

            dfs(e.to, source, all_cost + e.cost);

        }

    }



    ll n, k, a, b, c;



    in2(n, k);

    rep(i, n - 1){

        in3(a, b, c);

        a--; b--;

        tree[a].pb({b, c});

        tree[b].pb({a, c});

    }



    k--;

    dfs(k, -1, 0);



    #10. Visiting Subtree using recurrent function (ABC138D)



    gr tree[MAX_N];

    ll c[MAX_N];

    bool visited[MAX_N];



    void dfs(ll source, ll parent, ll val){

        visited[source] = true;

        c[source] += val;

        rep(i, tree[source].size()){

            rep(i, m){ll res = n % match[i].e1;}

            ll vertex = tree[source][i].to;

            if (vertex == parent) continue;

            dfs(vertex, source, c[source]);

        }

    }



    #11. bfs ABC146D, ABC007C

    1. first create a tree.

    2. start searching from a node.

    3. do some processes and push nodes connected with a given target node in BFS.

    4. repeat a series of procedure until queue is empty.



    queue<pl> q;



    void bfs(ll source, ll parents){

        ll n_edge = G[source].size();

        if (parents != -1) dist[source] = min(dist[source], dist[parents] + 1);

        if (visited[source]) return;

        visited[source] = true;



        rep(idx, n_edge){

            ll target = G[source][idx].to;

            if (target == parents) continue;

            q.push(mp(target, source)); 

        }

    }



    q.push(mp(sg.e1, -1));

    while(!q.empty()){

        pl source = q.front(); q.pop();

        bfs(source.e1, source.e2);

    }



    #12. grid to distance matrix (dx, dy)

    ll w, h;

    ll pos_to_idx(ll x, ll y){

        return y * w + x;

    }



    pl idx_to_pos(ll idx){

        return mp(idx % w, idx / w); 

    }



    int main(void){

        in2(h, w);

        rep(y, h){

            in1(s);

            rep(x, w){

                if (s[x] == '#') wall[x][y] = true;

                else wall[x][y] = false;

            }

        }



        rep(i1, h * w)rep(i2, h * w) dist[i1][i2] = INF * (i1 != i2);



        rep(x, w)rep(y, h){

            ll idx1 = pos_to_idx(x, y); ll idx2;

            if (wall[x][y]) continue;

            if (x != 0 && !wall[x - 1][y]){

                idx2 = pos_to_idx(x - 1, y);

                // if warshall floyd

                dist[idx1][idx2] = 1;

                // if dijkstra

                // graph[idx1].pb({idx2, 1});

            }

            if (x != w - 1 && !wall[x + 1][y]){

                idx2 = pos_to_idx(x + 1, y);

                dist[idx1][idx2] = 1;

                // graph[idx1].pb({idx2, 1});

            }

            if (y != 0 && !wall[x][y - 1]){

                idx2 = pos_to_idx(x, y - 1);

                dist[idx1][idx2] = 1;

                // graph[idx1].pb({idx2, 1});

            }

            if (y != h - 1 && !wall[x][y + 1]){

                idx2 = pos_to_idx(x, y + 1);

                dist[idx1][idx2] = 1;

                // graph[idx1].pb({idx2, 1});

            }

        }

    }





*/



/*

the operators regarding bit

& (AND), | (OR), ^ (XOR)

- (REVERSE), >> (SMALLER SHIFT)

<< (BIGGER SHIFT)





     x1: 0000 0001 0010 0101 0110 0111

     x2: xxxx 0001 0011 0100 0101 1000

x1 & x2: 0000 0001 0010 0100 0100 0000



      x: 1001 1010  1100 1011 1101  1111

x & - x: 0001 0010  0100 0001 0001  0001

    sum: 1010 1100 10000 1100 1100 10000



x << y is x * 2 ** y

x >> y is rep(i, y) x = x // 2 

*/



const ll MAX_N = 100005;

bool okay = false;

ll answer = 0;

ll n, m;

gr graph[MAX_N * 3];

ll dist[MAX_N * 3];



void dijkstra(ll start, ll n) {

    priority_queue<pl, vector<pl>, greater<pl>> edge_costs;

    fill(dist, dist + n, INF);

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

                edge_costs.push(pl(dist[e.to], e.to));

            }

        }

    }

}



void solve(){

    rep(i, m){

        ll u, v;

        in2(u, v); u--; v--;

        graph[u * 3].pb({v * 3 + 1, 1});

        graph[u * 3 + 1].pb({v * 3 + 2, 1});

        graph[u * 3 + 2].pb({v * 3, 1});

    }

    ll start, target;

    in2(start, target); start--; target--;

    dijkstra(start * 3, n * 3);



    if (dist[target * 3] % 3 == 0) prl(dist[target * 3] / 3);

    else prl(-1);



    // check negative MOD

    // check index flow

    // check overwrite of the input variables

}

 

int main(void){

    in2(n, m);

    // assert(n <= 1000);

    solve();

    

    return 0;

}
