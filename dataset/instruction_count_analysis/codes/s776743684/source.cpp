#include "stdc++.h"

 

#define M_PI       3.14159265358979323846

 

using namespace std;



 

//typedef

//-------------------------#include "stdc++.h"

 

#define M_PI       3.14159265358979323846

 

using namespace std;

 

//conversion

//------------------------------------------

inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }

template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

inline int readInt() { int x; scanf("%d", &x); return x; }

 

//typedef

//------------------------------------------

typedef vector<int> VI;

typedef vector<VI> VVI;

typedef vector<string> VS;

typedef pair<int, int> PII;

typedef pair<int, PII> TIII;

typedef long long LL;

typedef unsigned long long ULL;

typedef vector<LL> VLL;

typedef vector<VLL> VVLL;

 

 

//container util

 

//------------------------------------------

#define ALL(a)  (a).begin(),(a).end()

#define RALL(a) (a).rbegin(), (a).rend()

#define PB push_back

#define MP make_pair

#define SZ(a) int((a).size())

#define SQ(a) ((a)*(a))

#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

#define EXIST(s,e) ((s).find(e)!=(s).end())

#define SORT(c) sort((c).begin(),(c).end())

 

//repetition

//------------------------------------------

#define FOR(i,s,n) for(int i=s;i<(int)n;++i)

#define REP(i,n) FOR(i,0,n)

#define MOD 1000000007

 

#define rep(i, a, b) for(int i = a; i < (b); ++i)

#define trav(a, x) for(auto& a : x)

#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()

 

 

 

typedef long long ll;

typedef pair<int, int> pii;

typedef vector<int> vi;

const double EPS = 1E-8;

 

#define chmin(x,y) x=min(x,y)

#define chmax(x,y) x=max(x,y)

const int INF = 100000000;

 

struct Edge {

    int to, from;

    ll cost;

    Edge(int from, int to, ll cost): from(from), to(to), cost(cost) {}

};

 

class UnionFind {

public:

    vector <ll> par; 

    vector <ll> siz; 

    

    vector <ll> maxv;

    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {

        for (ll i = 0; i < sz_; ++i) par[i] = i;

    }

    void init(ll sz_) {

        par.resize(sz_);

        siz.assign(sz_, 1LL);

        for (ll i = 0; i < sz_; ++i) par[i] = i;

    }

 

    ll root(ll x) { 

        while (par[x] != x) {

            x = par[x] = par[par[x]];

        }

        return x;

    }

 

    bool merge(ll x, ll y) {

        x = root(x);

        y = root(y);

        if (x == y) return false;

        if (siz[x] < siz[y]) swap(x, y);

        siz[x] += siz[y];

        par[y] = x;

        return true;

    }

 

    bool issame(ll x, ll y) { 

        return root(x) == root(y);

    }

 

    ll size(ll x) { 

        return siz[root(x)];

    }

};

 

typedef vector<vector<Edge>> AdjList;

AdjList graph;

 

ll mod_pow(ll x, ll n, ll mod){

    ll res = 1;

    bool c = false;

    while(n){

        if(n&1) res = res * x;

 

        if(res > mod){

            c = true;

            res %= mod;

        }

        x = x * x %mod;

        n >>= 1;

    }

    if(c) return mod;

    return res;

}

 

#define SIEVE_SIZE 5000000+10

bool sieve[SIEVE_SIZE];

void make_sieve(){

    for(int i=0; i<SIEVE_SIZE; ++i) sieve[i] = true;

    sieve[0] = sieve[1] = false;

    for(int i=2; i*i<SIEVE_SIZE; ++i) if(sieve[i]) for(int j=2; i*j<SIEVE_SIZE; ++j) sieve[i*j] = false;

}

 

bool isprime(ll n){

    if(n == 0 || n == 1) return false;

    for(ll i=2; i*i<=n; ++i) if(n%i==0) return false;

    return true;

}

 

template<typename T>

vector<T> gauss_jordan(const vector<vector<T>>& A, const vector<T>& b){

    int n = A.size();

    vector<vector<T>> B(n, vector<T>(n+1));

 

    for(int i=0; i<n; ++i){

        for(int j=0; j<n; ++j){

            B[i][j] = A[i][j];

        }

    }

 

    for(int i=0; i<n; ++i) B[i][n] = b[i];

 

    for(int i=0; i<n; ++i){

        int pivot = i;

        for(int j=i; j<n; ++j){

            if(abs(B[j][i]) > abs(B[pivot][i])) pivot = j;

        }

        swap(B[i], B[pivot]);

 

        if(abs(B[i][i]) < EPS) return vector<T>(); //解なし

 

        for(int j=i+1; j<=n; ++j) B[i][j] /= B[i][i];

        for(int j=0; j<n; ++j){

            if(i != j){

                for(int k=i+1; k<=n; ++k) B[j][k] -= B[i][j] * B[i][k];

            }

        }

    }

 

    vector<T> x(n);

 

    for(int i=0; i<n; ++i) x[i] = B[i][n];

    return x;

    

}

 

 

 

 

typedef vector<ll> vec;

typedef vector<vec> mat;

 

mat mul(mat &A, mat &B) {

    mat C(A.size(), vec((int)B[0].size()));

    for(int i=0; i<A.size(); ++i){

        for(int k=0; k<B.size(); ++k){

            for(int j=0; j<B[0].size(); ++j){

                C[i][j] = (C[i][j] + A[i][k] * B[k][j] %MOD) % MOD;

            }

        }

    }

    return C;

}

mat mat_pow(mat A, ll n) {

    mat B(A.size(), vec((int)A.size()));

 

    for(int i=0; i<A.size(); ++i){

        B[i][i] = 1;

    }

 

    while(n > 0) {

        if(n & 1) B = mul(B, A);

        A = mul(A, A);

        n >>= 1;

    }

    return B;

}

 

bool operator<(const pii& a, const pii& b){

    if(a.first == b.first) return a.second < b.second;

    return a.first < b.first;

}

 

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

 

// テーブルを作る前処理

void COMinit() {

    fac[0] = fac[1] = 1;

    finv[0] = finv[1] = 1;

    inv[1] = 1;

    for (int i = 2; i < MAX; i++){

        fac[i] = fac[i - 1] * i % MOD;

        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;

        finv[i] = finv[i - 1] * inv[i] % MOD;

    }

}

 

// 二項係数計算

long long COM(int n, int k){

    if (n < k) return 0;

    if (n < 0 || k < 0) return 0;

    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;

}

 

int bit[1000010];

int sums(int i){

    i++;

    int s = 0;

    while(i > 0){

        s += bit[i];

        i -= i & -i;

    }

    return s;

}

void add(int i, int x){

    i++;

    while(i <= 1000010){

        bit[i] += x;

        i += i & -i;

    }

}

long long extGCD(long long a, long long b, long long &x, long long &y) {

    if (b == 0) {

        x = 1;

        y = 0;

        return a;

    }

    long long d = extGCD(b, a%b, y, x);

    y -= a/b * x;

    return d;

}

 

ll GCD(ll a, ll b){

    

    if(b == 0) return a;

    return GCD(b, a%b);

}

 

struct BipartiteMatching {

  vector< vector< int > > graph;

  vector< int > match, alive, used;

  int timestamp;

 

  BipartiteMatching(int n) : graph(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}

 

  void add_edge(int u, int v) {

    graph[u].push_back(v);

    graph[v].push_back(u);

  }

 

  bool dfs(int idx) {

    used[idx] = timestamp;

    for(auto &to : graph[idx]) {

      int to_match = match[to];

      if(alive[to] == 0) continue;

      if(to_match == -1 || (used[to_match] != timestamp && dfs(to_match))) {

        match[idx] = to;

        match[to] = idx;

        return true;

      }

    }

    return false;

  }

 

  int bipartite_matching() {

    int ret = 0;

    for(int i = 0; i < graph.size(); i++) {

      if(alive[i] == 0) continue;

      if(match[i] == -1) {

        ++timestamp;

        ret += dfs(i);

      }

    }

    return ret;

  }

 

  void output() {

    for(int i = 0; i < graph.size(); i++) {

      if(i < match[i]) {

        cout << i << "-" << match[i] << endl;

      }

    }

  }

};



bool used[100010];

int A[100010];

int cnt[100010];

vector<vector<int>> G(100010);

int main() {

    cin.tie(0);

    ios::sync_with_stdio(false);

    cout << fixed << setprecision(15);

    

    int n; cin >> n;



    vector<int> nums;

    REP(i,n){

        int a; cin >> a;

        A[i] = a;

        G[a].push_back(i);

        nums.push_back(a);

        used[i] = false;

    }

    sort(all(nums));

ll ans = 1;

    reverse(all(nums));

    int v1 = nums[0];

    int v2 = nums[1];

    int v3 = nums[2];

    

    int t1 = v1;

    int t2 = v2;

    int t3 = v3;





    int s = 3;

    

    for(int i=0; i<n; i++){

        if(A[i] == 0){

            ans *= s;

            ans %= MOD;

            s--;

            cnt[A[i]]++;

        }else{

            ans *= cnt[A[i]-1];

            cnt[A[i]]++;

            cnt[A[i]-1]--;

            ans %= MOD;

        }

    }

    cout << ans << endl;

    return 0;

}