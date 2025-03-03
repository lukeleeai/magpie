#define _USE_MATH_DEFINES

#include "stdc++.h"

using namespace std;

// #define int long long

// #define double long double

#define rep(i,n) for (int i=0; i<(int)(n); ++i)

#define rep1(i,n) for (int i=1; i<(int)(n); ++i)

#define repeq(i,n) for (int i=0; i<=(int)(n); ++i)

#define rep1eq(i,n) for (int i=1; i<=(int)(n); ++i)

#define rrep(i,n) for (int i=(int)(n)-1; i>=0; --i)

#define rrep1(i,n) for (int i=(int)(n)-1; i>0; --i)

#define rrepeq(i,n) for (int i=(int)(n); i>=0; --i)

#define rrep1eq(i,n) for (int i=(int)(n); i>0; --i)

#define REP(i,a,b) for (int i=(int)(a); i<=(int)(b); ++i)

#define RREP(i,a,b) for (int i=(int)(a); i>=(int)(b); --i)

#define ALL(a) (a).begin(), (a).end()

#define RALL(a) (a).rbegin(), (a).rend()

using ll = long long;

using vi = vector<int>;

using vl = vector<ll>;

using vb = vector<bool>;

template<typename T> using Graph = vector<vector<T>>;

template<typename T> using Spacial = vector<vector<vector<T>>>;

using pii = pair<int, int>;

using pll = pair<ll, ll>;

template<typename T> using greater_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int MOD = 1e9+7;

const int MOD2 = 998244353;

// const double EPS = 1e-9;

const int dx[4] = {1, 0, -1, 0};

const int dy[4] = {0, 1, 0, -1};

string interval[2] = {" ", "\n"}; // {" ", "\n"}



template<typename T> struct is_plural : false_type{};

template<typename T1, typename T2> struct is_plural<pair<T1, T2>> : true_type{};

template<typename T> struct is_plural<vector<T>> : true_type{};

template<typename T> struct is_plural<complex<T>> : true_type{};

 

template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second; }

template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << " " << p.second; }

template<typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto itr = vec.begin(); itr != vec.end(); ++itr) is >> *itr; return is; }

template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { if (vec.empty()) return os; bool pl = is_plural<T>(); os << vec.front(); for (auto itr = ++vec.begin(); itr != vec.end(); ++itr) os << interval[pl] << *itr; return os; }

 

bool CoutYN(bool a, string y = "Yes", string n = "No") { cout << (a ? y : n) << "\n"; return a; }



template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }



long long modpow(int a, long long n, int mod = MOD) { long long ret = 1; do { if (n & 1) ret = ret * a % mod; a = 1LL * a * a % mod; } while (n >>= 1); return ret; }



template<typename T> T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }

template<typename T> T LCM(T a, T b) { return a / GCD(a, b) * b; }



template<typename T1, typename T2> bool CompareBySecond(pair<T1, T2> a, pair<T1, T2> b) { return a.second != b.second ? a.second < b.second : a.first < b.first; }

template<typename T1, typename T2> bool CompareByInverse(pair<T1, T2> a, pair<T1, T2> b) { return a.first != b.first ? a.first < b.first : a.second > b.second; }





/* -------- <templates end> -------- */





pii operator+(pii a, pii b) {

  return {a.first + b.first, a.second + b.second};

}



void solve() {

  int n; cin >> n;

  vector<pii> g(n); cin >> g;



  const int num = 9;

  const int sz = 1 << num;



  vector<map<int, int>> calc(sz);

  calc[0][0] = 0;

  rep(i,num) {

    int x = 1 << i;

    for (int j = x; j < 2 * x; ++j) {

      for (auto &p : calc[j / 2]) {

        chmax(calc[j][p.first], p.second);

        chmax(calc[j][p.first + g[j-1].second], p.second + g[j-1].first);

      }

      vi erase;

      int MAX = -1;

      for (auto &p : calc[j]) {

        if (p.second <= MAX) erase.emplace_back(p.first);

        else MAX = p.second;

      }

      for (auto &v : erase) {

        calc[j].erase(v);

      }

    }

  }



  int q; cin >> q;



  while (q--) {

    int v, L; cin >> v >> L;

    vector<pii> vec(1);

    while (v >= sz) {

      int s = vec.size();

      rep(i,s) vec.emplace_back(vec[i] + g[v-1]);

      v >>= 1;

    }



    int ans = 0;

    for (auto &p : vec) {

      if (L < p.second) continue;

      auto itr = --calc[v].upper_bound(L - p.second);

      chmax(ans, itr->second + p.first);

    }

    cout << ans << '\n';

  }

}





/* -------- <programs end> -------- */





signed main() {

  cin.tie(nullptr);

  ios::sync_with_stdio(false);

  cout << fixed << setprecision(10);

  solve();

  return 0;

}
