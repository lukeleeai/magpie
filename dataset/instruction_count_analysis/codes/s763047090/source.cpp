#pragma region template

#include "stdc++.h"

using namespace std;

using ll = long long;

using ull = unsigned long long;

using ld = long double;

using vi = vector<int>;

using vvi = vector<vi>;

using vvvi = vector<vvi>;

using vll = vector<ll>;

using vvll = vector<vll>;

using vvvll = vector<vvll>;

using vld = vector<ld>;

using vvld = vector<vld>;

using vvvld = vector<vvld>;

using vs = vector<string>;

using pll = pair<ll, ll>;

using vp = vector<pll>;

template <typename T>

using pqrev = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (ll i = 0, i##_end = (n); i < i##_end; i++)

#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)

#define repr(i, a, b) for (ll i = (a), i##_end = (b); i < i##_end; i++)

#define reprb(i, a, b) for (ll i = (b)-1, i##_end = (a); i >= i##_end; i--)

#define ALL(a) (a).begin(), (a).end()

#define SZ(x) ((ll)(x).size())

//*

constexpr ll MOD = 1e9 + 7;

/*/

constexpr ll MOD = 998244353;

//*/

constexpr ll INF = 1e+18;

constexpr ld EPS = 1e-12L;

constexpr ld PI = 3.14159265358979323846L;

constexpr ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }

constexpr ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }

template <typename S, typename T>

inline bool chmax(S &a, const T &b) {

  if (a < b) {

    a = b;

    return 1;

  }

  return 0;

}

template <typename S, typename T>

inline bool chmin(S &a, const T &b) {

  if (b < a) {

    a = b;

    return 1;

  }

  return 0;

}

#ifdef OJ_LOCAL

#include "dump.hpp"

#else

#define dump(...) ((void)0)

#endif

template <typename T>

bool print_(const T &a) {

  cout << a;

  return true;

}

template <typename T>

bool print_(const vector<T> &vec) {

  for (auto &a : vec) {

    cout << a;

    if (&a != &vec.back()) {

      cout << " ";

    }

  }

  return false;

}

template <typename T>

bool print_(const vector<vector<T>> &vv) {

  for (auto &v : vv) {

    for (auto &a : v) {

      cout << a;

      if (&a != &v.back()) {

        cout << " ";

      }

    }

    if (&v != &vv.back()) {

      cout << "\n";

    }

  }

  return false;

}

void print() { cout << "\n"; }

template <typename Head, typename... Tail>

void print(Head &&head, Tail &&... tail) {

  bool f = print_(head);

  if (sizeof...(tail) != 0) {

    cout << (f ? " " : "\n");

  }

  print(forward<Tail>(tail)...);

}

#pragma endregion



// v1をソートし、v2を対応する位置に移動する

template <typename T, typename U>

void pairSort(vector<T> &v1, vector<U> &v2, bool rev = false) {

  int n = v1.size();

  vector<pair<T, U>> p(n);

  for (int i = 0; i < n; i++) {

    p[i] = pair<T, U>(v1[i], v2[i]);

  }

  if (rev) {

    sort(p.begin(), p.end(), [&](const auto &l, const auto &r) {

      if (l.first == r.first)

        return l.second > r.second;

      else

        return l.first < r.first;

    });

  } else {

    sort(p.begin(), p.end());

  }

  for (int i = 0; i < n; i++) {

    v1[i] = p[i].first;

    v2[i] = p[i].second;

  }

}





int main() {

  cin.tie(0);

  ios::sync_with_stdio(false);

  cout << fixed << setprecision(20);

  ll n;

  cin >> n;

  vll a(n), b(n);

  rep(i, n){

    cin >> a[i] >> b[i];

  }

  vll c(n), d(n);

  rep(i, n){

    cin >> c[i] >> d[i];

  }

  pairSort(c, d);

  vi f(n, 1);

  rep(i, n){

    ll id = -1;

    ll pos = -INF;

    rep(j, n){

      if(f[j] && a[j] < c[i] && b[j] < d[i]){

        if(chmax(pos, b[j])){

          id = j;

        }

      }

    }

    if(id != -1){

      f[id] = 0;

    }

  }

  print(n - accumulate(ALL(f), 0));

}
