#include "stdc++.h"



#define rep(i, n) for (int i = 0; i < int(n); i++)

#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)

#define reps(i, n) for (int i = 1; i <= int(n); i++)

#define rreps(i, n) for (int i = int(n); i >= 1; i--)

#define repc(i, n) for (int i = 0; i <= int(n); i++)

#define rrepc(i, n) for (int i = int(n); i >= 0; i--)

#define repi(i, a, b) for (int i = int(a); i < int(b); i++)

#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)

#define each(x, y) for (auto &x : y)

#define all(a) (a).begin(), (a).end()

#define bit32(x) (1 << (x))

#define bit64(x) (1ll << (x))

#define sz(v) ((int) v.size())



using namespace std;



using i64 = long long;

using f80 = long double;

using vi32 = vector<int>;

using vi64 = vector<i64>;

using vf80 = vector<f80>;

using vstr = vector<string>;



inline void yes() { cout << "Yes" << endl; exit(0); }

inline void no() { cout << "No" << endl; exit(0); }

template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};

template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};

template <typename T> inline void amax(T &x, T y) { x = max(x, y); }

template <typename T> inline void amin(T &x, T y) { x = min(x, y); }

template <typename T> inline T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }

template <typename T> istream& operator>>(istream &is, vector<T> &v) { each(x, v) is >> x; return is; }

template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }

void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }



struct Prime {

  int n;

  vector<int> pri;

  Prime() : n(0) {}

  Prime(int n) : n(n) {

    vector<bool> f(n, true);

    f[0] = f[1] = false;

    for (int i = 2; i < n; i++) {

      if (!f[i]) continue;

      pri.push_back(i);

      for (int j = i * 2; j < n; j += i) {

        f[j] = false;

      }

    }

  }

  bool is(int x) {

    if (n > x) {

      return binary_search(pri.begin(), pri.end(), x);

    }

    if (x < 2) return 0;

    for (int i = 2; i * i <= x; i++) {

      if (x % i == 0) return false;

    }

    return true;

  }

  map<int, int> factor(int k) {

    map<int, int> so;

    for (auto p : pri) {

      while (k % p == 0) k /= p, so[p]++;

    }

    if (k != 1) so[k] = 1;

    return so;

  }

};



auto prime = Prime(1000);



void solve() {

  int len = 0;

  each(p, prime.pri) {

    if (p >= 100) break;

    len++;

  }

  vi32 cnt(len);

  int n;

  cin >> n;

  reps(i, n) {

    int x = i;

    rep(j, len) {

      int p = prime.pri[j];

      while (x % p == 0) cnt[j]++, x /= p;

    }

  }

  int ans = 0;

  rep(i, len) {

    if (cnt[i] >= 74) ans++;

  }

  rep(i, len) rep(j, len) {

    if (i == j) continue;

    if (cnt[i] >= 24 && cnt[j] >= 2) ans++;

  }

  rep(i, len) rep(j, len) {

    if (i == j) continue;

    if (cnt[i] >= 14 && cnt[j] >= 4) ans++;

  }

  set<tuple<int, int, int>> se;

  rep(i, len) rep(j, len) rep(k, len) {

    if (i == j || j == k || k == i) continue;

    if (se.count(make_tuple(min(i, j), max(i, j), k)) >= 1) continue;

    if (cnt[i] >= 4 && cnt[j] >= 4 && cnt[k] >= 2) ans++;

    se.insert(make_tuple(min(i, j), max(i, j), k));

  }

  cout << ans << endl;

}