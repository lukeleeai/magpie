#include "stdc++.h"

using namespace std;

// #define int long long

// #define endl '\n'



//TEMPLATE START---------------8<---------------8<---------------8<---------------8<---------------//



/* TYPE */

typedef long long ll;       typedef long double ld;

typedef pair<int, int> pii; typedef pair<ll, ll> pll;

typedef vector<pii> vpii;   typedef vector<pll> vpll;

typedef vector<int> vi;     typedef vector<ll> vl;

typedef vector<string> vst; typedef vector<bool> vb;

typedef vector<ld> vld;     typedef vector<vector<int>> vvi;

template<typename T, typename Cmp = less<>> using prique = priority_queue<T, vector<T>, Cmp>;

template<typename T> using prique_r = prique<T, greater<>>;

/* CONSTANT */

#define ln '\n'

const int INF = 1 << 30;    const ll INFF = 1LL << 60;  const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const int MOD = 1e9 + 7;    const int MODD = 998244353; const string alphabet = "abcdefghijklmnopqrstuvwxyz";

const double EPS = 1e-9;    const ld PI = 3.14159265358979323846264338327950288;

const int dx[] = { 1, 0, -1,  0,  1, -1, -1, 1, 0 };

const int dy[] = { 0, 1,  0, -1, -1, -1,  1, 1, 0 };

/* CONTAINER */

#define PB              emplace_back

#define ALL(v)          (v).begin(), (v).end()

#define RALL(v)         (v).rbegin(), (v).rend()

#define SORT(v)         sort(ALL(v))

#define RSORT(v)        sort(RALL(v))

#define LESS(x, val)    (lower_bound(x.begin(), x.end(), val) - x.begin())

#define LEQ(x, val)     (upper_bound(x.begin(), x.end(), val) - x.begin())

#define GREATER(x, val) (int)(x).size() - LEQ((x), (val))

#define GEQ(x, val)     (int)(x).size() - LESS((x), (val))

#define UNIQUE(v)       sort(ALL(v)); (v).erase(unique(ALL(v)), (v).end())

template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }

template<typename T, typename U, typename... V> enable_if_t<is_same<T, U>::value != 0> fill_v(U &u, const V... v) { u = U(v...); }

template<typename T, typename U, typename... V> enable_if_t<is_same<T, U>::value == 0> fill_v(U &u, const V... v) { for (auto &e : u) fill_v<T>(e, v...); }

/* LOOP */

#define _overload3(_1, _2, _3, name, ...) name

#define _REP(i, n)      REPI(i, 0, n)

#define REPI(i, a, b)   for (ll i = (ll)a; i < (ll)b; ++i)

#define REP(...)        _overload3(__VA_ARGS__, REPI, _REP,)(__VA_ARGS__)

#define _RREP(i, n)     RREPI(i, n, 0)

#define RREPI(i, a, b)  for (ll i = (ll)a; i >= (ll)b; --i)

#define RREP(...)       _overload3(__VA_ARGS__, RREPI, _RREP,)(__VA_ARGS__)

#define EACH(e, v)      for (auto& e : v)

#define PERM(v)         sort(ALL(v)); for (bool c##p = true; c##p; c##p = next_permutation(ALL(v)))

/* INPUT */

template<typename T> void SSS(T& t) { cin >> t; }

template<typename Head, typename... Tail> void SSS(Head&& head, Tail&&... tail) { cin >> head; SSS(tail...); }

#define SS(T, ...)      T __VA_ARGS__; SSS(__VA_ARGS__);

#define SV(T, v, n)     vector<T> v(n); for (auto& i : v) cin >> i;

#define SVV(T, v, n, m) vector<vector<T>> v(n, vector<T>(m)); for (auto& r : v) for (auto& i : r) cin >> i;

/* OUTPUT */

// PROTOTYPE DECLARATION

template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &j);

template<typename... T> ostream &operator<<(ostream &os, const tuple<T...> &t);

template<class C, enable_if_t<!is_same<C, string>::value, decltype(declval<const C &>().begin(), nullptr)> = nullptr> ostream& operator<<(ostream &os, const C &c);

template<typename T> ostream &operator<<(ostream &os, const stack<T> &j);

template<typename T> ostream &operator<<(ostream &os, const queue<T> &j);

template<typename T, typename C, typename Cmp> ostream &operator<<(ostream &os, const priority_queue<T, C, Cmp> &j);

// IMPLEMENTATION

template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &j) { return os << '{' << j.first << ", " << j.second << '}'; }

template<size_t num = 0, typename... T> enable_if_t<num == sizeof...(T)> PRINT_TUPLE(ostream &os, const tuple<T...> &t) {}

template<size_t num = 0, typename... T> enable_if_t<num <  sizeof...(T)> PRINT_TUPLE(ostream &os, const tuple<T...> &t) { os << get<num>(t); if (num + 1 < sizeof...(T)) os << ", "; PRINT_TUPLE<num + 1>(os, t); }

template<typename... T> ostream &operator<<(ostream &os, const tuple<T...> &t) { PRINT_TUPLE(os << '{', t); return os << '}'; }

template<class C, enable_if_t<!is_same<C, string>::value, decltype(declval<const C &>().begin(), nullptr)>> ostream& operator<<(ostream &os, const C &c) { os << '{'; for (auto it = begin(c); it != end(c); it++) { if (begin(c) != it) os << ", "; os << *it; } return os << '}'; }

template<typename T> ostream &operator<<(ostream &os, const stack<T> &j) { deque<T> d; for (auto c = j; !c.empty(); c.pop()) d.push_front(c.top());  return os << d; }

template<typename T> ostream &operator<<(ostream &os, const queue<T> &j) { deque<T> d; for (auto c = j; !c.empty(); c.pop()) d.push_back(c.front()); return os << d; }

template<typename T, typename C, typename Cmp> ostream &operator<<(ostream &os, const priority_queue<T, C, Cmp> &j) { deque<T> d; for (auto c = j; !c.empty(); c.pop()) d.push_front(c.top());  return os << d; }

// OUTPUT FUNCTION

template<typename T> int PV(T &v) { int sz = v.size(); for (int i = 0; i < sz; ++i) cout << v[i] << " \n"[i == sz - 1]; return 0; }

inline int print() { cout << endl; return 0; }

template<typename Head> int print(Head&& head){ cout << head; return print(); }

template<typename Head, typename... Tail> int print(Head&& head, Tail&&... tail) { cout << head << " "; return print(forward<Tail>(tail)...); }

#ifdef LOCAL

inline void dump() { cerr << endl; }

template<typename Head> void dump(Head&& head) { cerr << head; dump(); }

template<typename Head, typename... Tail> void dump(Head&& head, Tail&&... tail) { cerr << head << ", "; dump(forward<Tail>(tail)...); }

#define debug(...) do {cerr << __LINE__ << ":	" << #__VA_ARGS__ << " = "; dump(__VA_ARGS__); } while (false)

#else

#define dump(...)

#define debug(...)

#endif

/* OTHER */

#define MP              make_pair

#define MT              make_tuple

#define tmax(x, y, z)   max((x), max((y), (z)))

#define tmin(x, y, z)   min((x), min((y), (z)))

template<typename T, typename A, typename B> inline bool between(T x, A a, B b) { return ((a <= x) && (x < b)); }

template<typename A, typename B> inline bool chmax(A &a, const B &b) { if (a < b) { a = b; return true; } return false; }

template<typename A, typename B> inline bool chmin(A &a, const B &b) { if (a > b) { a = b; return true; } return false; }

inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

inline ll POW(ll a, ll b)                    { ll r = 1; do { if (b & 1)  r *= a;        a *= a; }       while (b >>= 1); return r; }

inline ll MOP(ll a, ll b, const ll &m = MOD) { ll r = 1; do { if (b & 1) (r *= a) %= m; (a *= a) %= m; } while (b >>= 1); return r; }

struct abracadabra {

    abracadabra() {

        cin.tie(nullptr); ios::sync_with_stdio(false);

        cout << fixed << setprecision(20);

        cerr << fixed << setprecision(5);

    };

} ABRACADABRA;



//TEMPLATE END---------------8<---------------8<---------------8<---------------8<---------------//



const int MAX_ROW = 100100;

const int MAX_COL = 62;

struct BitMatrix {

    int H, W;

    bitset<MAX_COL> val[MAX_ROW];

    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}

    inline bitset<MAX_COL>& operator[](int i) { return val[i]; }

};

ostream& operator<<(ostream& s, BitMatrix A) {

    s << endl;

    for (int i = 0; i < A.H; ++i) {

        for (int j = 0; j < A.W; ++j) {

            s << A[i][j] << ", ";

        }

        s << endl;

    }

    return s;

}

inline BitMatrix operator*(BitMatrix A, BitMatrix B) {

    BitMatrix R(A.H, B.W), tB(B.W, B.H);

    for (int i = 0; i < tB.H; ++i) for (int j = 0; j < tB.W; ++j) tB[i][j] = B[j][i];

    for (int i = 0; i <  R.H; ++i) for (int j = 0; j <  R.W; ++j)  R[i][j] = ((A[i] & tB[j]).count() & 1);

    return R;

}

inline BitMatrix pow(BitMatrix A, unsigned long long n) {

    BitMatrix R(A.H, A.H);

    for (int i = 0; i < A.H; ++i) R[i][i] = 1;

    while (n > 0) {

        if (n & 1) R = R * A;

        A = A * A;

        n >>= 1;

    }

    return R;

}

int gaussian_elimination(BitMatrix &A, bool is_extended = false) {

    int rank = 0;

    for (int col = 0; col < A.W; ++col) {

        if (is_extended and col == A.W - 1) break;

        int pivot = -1;

        for (int row = rank; row < A.H; ++row) {

            if (A[row][col]) {

                pivot = row;

                break;

            }

        }

        if (pivot == -1) continue;

        swap(A[pivot], A[rank]);

        for (int row = 0; row < A.H; ++row) {

            if (row != rank and A[row][col]) A[row] ^= A[rank];

        }

        ++rank;

    }

    return rank;

}

int linear_equation(BitMatrix A, vector<int> b, vector<int> &res) {

    int m = A.H, n = A.W;

    BitMatrix M(m, n + 1);

    for (int i = 0; i < m; ++i) {

        for (int j = 0; j < n; ++j) M[i][j] = A[i][j];

        M[i][n] = b[i];

    }

    int rank = gaussian_elimination(M, true);

    for (int row = rank; row < m; ++row) if (M[row][n]) return -1;

    res.assign(n, 0);

    for (int i = 0; i < rank; ++i) res[i] = M[i][n];

    return rank;

}



/*

・BitMatrix

[備考] F_2上の行列操作

[注意] MAX_ROW, MAX_COLを問題ごとに変えること

[使用例]

BitMatrix mat(N, M);            // N行M列の行列を作成

gaussian_elimination(mat);      // matに対してガウスの消去法を適用

linear_equation(A, b, res);     // 連立方程式 A * res = b を解く

*/



signed main() {



    SS(int, N);

    SV(ll, A, N);



    ll allxor = 0;

    EACH(e, A) allxor ^= e;



    const int MAXBIT = 61;



    BitMatrix mat(N, MAXBIT);

    REP(i, N) {

        ll n = A[i] & ~allxor;

        REP(j, MAXBIT) {

            mat[i][MAXBIT - 1 - j] = (n >> j) & 1;

        }

    }



    // print(mat);

    gaussian_elimination(mat);

    // print(mat);



    ll ans = 0, res = 0;

    REP(i, N) {

        ll tmp = res;

        REP(j, MAXBIT) {

            tmp ^= (ll)(mat[i][MAXBIT - 1 - j] > 0) << j;

        }

        chmax(res, tmp);

        chmax(ans, res << 1);

    }



    print(ans + allxor);



}
