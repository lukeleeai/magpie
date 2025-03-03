#include "stdc++.h"



using namespace std;



#define BOUND 27182818284

#define MAT 2



typedef long long ll;

typedef long long int lli;

typedef pair<ll, ll> P;



ll MOD = 1000000007;

const ll INF = ( 1ll << 60);

const int INFint = (1 << 30);



#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#define repi(i, a, b) for(int i=int(a);i<int(b);++i)



template<class T>

bool umax(T &a, const T &b) {

    if (a < b) {

        a = b;

        return true;

    }

    return false;

}



template<class T>

bool umin(T &a, const T &b) {

    if (b < a) {

        a = b;

        return true;

    }

    return false;

}



// gcd

template<typename T>

T gcd(T a, T b) {

    if (a == 0)

        return b;

    return gcd(b % a, a);

}



ll findGCD(vector<ll> arr) {

    ll result = arr[0];

    for (auto a : arr) {

        result = gcd(a, result);

    }

    return result;

}



template<typename T>

T getlcm(T m, T n) {

    // 引数に0がある場合は0を返す

    if ((0 == m) || (0 == n))

        return 0;

    return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)

}



template<typename A, size_t N, typename T>

void Fill(A (&array)[N], const T &val) {

    fill((T *) array, (T *) (array + N), val);

}





// v.front() = -BOUND;

// v.back() = BOUND;



//struct edge{

//    int cost, to;

//

//    edge(int in_cost, int in_to){

//        cost=in_cost;

//        to=in_to;

//    }

//    bool operator<(const edge &a) const

//    {

//        return cost > a.cost;

//    }

//};

ll euler_phi(ll n) {

    ll ret = n;

    for (ll i = 2; i * i <= n; i++) {

        if (n % i == 0) {

            ret -= ret / i;

            while (n % i == 0) n /= i;

        }

    }

    if (n > 1) ret -= ret / n;

    return ret;

}



class Combination {

    long long powmod(long long a, long long p) {

        long long ans = 1LL;

        long long mul = a;

        while (p > 0) {

            if ((p & 1) == 1) {

                ans = (ans * mul) % mod;

            }

            mul = (mul * mul) % mod;

            p >>= 1;

        }

        return ans;

    }



public:

    int N;

    long long mod;

    vector<long long> fact;

    vector<long long> revfact;



    Combination(int n, long long m) : N(n), mod(m), fact(n + 1), revfact(n + 1) {

        fact[0] = 1;

        for (int i = 1; i <= N; i++) {

            fact[i] = fact[i - 1] * i;

            fact[i] %= mod;

        }



        revfact[N] = powmod(fact[N], mod - 2);

        for (int i = N - 1; i >= 0; i--) {

            revfact[i] = revfact[i + 1] * (i + 1) % mod;

        }

    }



    long long getCombination(int a, int b) {

        if (a < 0 || b < 0) return 0;

        if (b > a)return 0;

        return (fact[a] * revfact[b]) % mod * revfact[a - b] % mod;

    }

};





struct mint {

    const int mod = 1000000007;

    ll x; // typedef long long ll;

    mint(ll x = 0) : x((x % mod + mod) % mod) {}



    mint &operator+=(const mint a) {

        if ((x += a.x) >= mod) x -= mod;

        return *this;

    }



    mint &operator-=(const mint a) {

        if ((x += mod - a.x) >= mod) x -= mod;

        return *this;

    }



    mint &operator*=(const mint a) {

        (x *= a.x) %= mod;

        return *this;

    }



    mint operator+(const mint a) const {

        mint res(*this);

        return res += a;

    }



    mint operator-(const mint a) const {

        mint res(*this);

        return res -= a;

    }



    mint operator*(const mint a) const {

        mint res(*this);

        return res *= a;

    }



    mint pow(ll t) const {

        if (!t) return 1;

        mint a = pow(t >> 1);

        a *= a;

        if (t & 1) a *= *this;

        return a;

    }



    // for prime mod

    mint inv() const {

        return pow(mod - 2);

    }



    mint &operator/=(const mint a) {

        return (*this) *= a.inv();

    }



    mint operator/(const mint a) const {

        mint res(*this);

        return res /= a;

    }

};



struct UnionFind {

    int n, cnt;

    vector<int> par, rank, sz;



    UnionFind(int n) : n(n), cnt(n), par(n), rank(n), sz(n, 1) { iota(par.begin(), par.end(), 0); }



    int find(int x) {

        if (x == par[x]) return x;

        return par[x] = find(par[x]);

    }



    bool same(int x, int y) { return find(x) == find(y); }



    int size(int x) { return sz[find(x)]; }



    void unite(int x, int y) {

        x = find(x), y = find(y);

        if (x == y) return;

        if (rank[x] < rank[y]) {

            par[x] = y;

            sz[y] += sz[x];

        } else {

            par[y] = x;

            sz[x] += sz[y];

            if (rank[x] == rank[y]) {

                rank[x]++;

            }

        }

        cnt--;

    }

};



const string Yes = "Yes";

const string YES = "YES";

const string No = "No";

const string NO = "NO";





long long modpow(long long a, long long n, long long mod) {

    long long res = 1;

    while (n > 0) {

        if (n & 1) res = res * a % mod;

        a = a * a % mod;

        n >>= 1;

    }

    return res;

}



template<typename Monoid>

struct SegmentTree {

    using F = function<Monoid(Monoid, Monoid)>;



    int sz;

    vector<Monoid> seg;



    const F f;

    const Monoid M1;



    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {

        sz = 1;

        while (sz < n) sz <<= 1;

        seg.assign(2 * sz, M1);

    }



    void set(int k, const Monoid &x) {

        seg[k + sz] = x;

    }



    void build() {

        for (int k = sz - 1; k > 0; k--) {

            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);

        }

    }



    void update(int k, const Monoid &x) {

        k += sz;

        seg[k] = x;

        while (k >>= 1) {

            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);

        }

    }



    Monoid query(int a, int b) {

        Monoid L = M1, R = M1;

        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {

            if (a & 1) L = f(L, seg[a++]);

            if (b & 1) R = f(seg[--b], R);

        }

        return f(L, R);

    }



    Monoid operator[](const int &k) const {

        return seg[k + sz];

    }



    template<typename C>

    int find_subtree(int a, const C &check, Monoid &M, bool type) {

        while (a < sz) {

            Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);

            if (check(nxt)) a = 2 * a + type;

            else M = nxt, a = 2 * a + 1 - type;

        }

        return a - sz;

    }





    template<typename C>

    int find_first(int a, const C &check) {

        Monoid L = M1;

        if (a <= 0) {

            if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);

            return -1;

        }

        int b = sz;

        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {

            if (a & 1) {

                Monoid nxt = f(L, seg[a]);

                if (check(nxt)) return find_subtree(a, check, L, false);

                L = nxt;

                ++a;

            }

        }

        return -1;

    }



    template<typename C>

    int find_last(int b, const C &check) {

        Monoid R = M1;

        if (b >= sz) {

            if (check(f(seg[1], R))) return find_subtree(1, check, R, true);

            return -1;

        }

        int a = sz;

        for (b += sz; a < b; a >>= 1, b >>= 1) {

            if (b & 1) {

                Monoid nxt = f(seg[--b], R);

                if (check(nxt)) return find_subtree(b, check, R, true);

                R = nxt;

            }

        }

        return -1;

    }

};



template<typename T>

vector<T> DIVISOR(T n) {

    vector<T> v;

    for (T i = 1; i * i <= n; ++i) {

        if (n % i == 0) {

            v.push_back(i);

            if (i != n / i) {

                v.push_back(n / i);

            }

        }

    }

    sort(v.begin(), v.end());

    return v;

}



ll permutation(ll n){

    ll ans = 1LL;

    if(n<=0){

        return ans;

    }

    for(ll i=1; i<=n; i++){

        ans *= i;

    }



    return ans;

}





template <typename T>

struct PrimeFact {

    vector<T> spf;

    PrimeFact(T N) { init(N); }

    void init(T N) { // 前処理。spf を求める

        spf.assign(N + 1, 0);

        for (T i = 0; i <= N; i++) spf[i] = i;

        for (T i = 2; i * i <= N; i++) {

            if (spf[i] == i) {

                for (T j = i * i; j <= N; j += i) {

                    if (spf[j] == j) {

                        spf[j] = i;

                    }

                }

            }

        }

    }

    map<T, T> get(T n) { // nの素因数分解を求める

        map<T, T> m;

        while (n != 1) {

            m[spf[n]]++;

            n /= spf[n];

        }

        return m;

    }

};







int main() {

    ll K;

    cin >> K;



    ll ans = 0LL;

    for(ll i=1; i<=K; i++){

        for(ll j=1; i*j<=K; j++){

            ans += i*j;

        }

    }



    cout << ans << endl;

    return 0;

}
