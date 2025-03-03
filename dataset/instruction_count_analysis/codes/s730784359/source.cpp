#include "stdc++.h"



#define rep(i, n) for (int i = 0; i < int(n); i++)

#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)

#define reps(i, n) for (int i = 1; i <= int(n); i++)

#define rreps(i, n) for (int i = int(n); i >= 1; i--)

#define repc(i, n) for (int i = 0; i <= int(n); i++)

#define rrepc(i, n) for (int i = int(n); i >= 0; i--)

#define repi(i, a, b) for (int i = int(a); i < int(b); i++)

#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)

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

inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }

inline i64 lcm(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); return a / gcd(a, b) * b; }

template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};

template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};

template <typename T> inline void amax(T &x, T y) { x = max(x, y); }

template <typename T> inline void amin(T &x, T y) { x = min(x, y); }

template <typename T> inline T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }

template <typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }

template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }

void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }



void solve() {

  int n;

  cin >> n;

  int k = 0;

  using P = pair<int, int>;

  using vvp = vector<vector<P>>;

  auto rec = [&](auto rec, int n, int col) -> vvp {

    if (n == 1) {

      return vvp(1);

    }

    int na = (n + 0) / 2;

    int nb = (n + 1) / 2;

    vvp a = rec(rec, na, col + 1);

    vvp b = rec(rec, nb, col + 1);

    rep(i, nb) {

      for (auto& p : b[i]) {

        p.first += na;

      }

      a.emplace_back(b[i]);

    }

    rep(i, na) rep(j, nb) {

      int u = i;

      int v = na + j;

      a[u].emplace_back(v, col);

      a[v].emplace_back(u, col);

    }

    return a;

  };

  auto res = rec(rec, n, 1);

  auto ans = vector<vi32>(n, vi32(n));

  rep(u, n) {

    for (auto p : res[u]) {

      int v, c;

      tie(v, c) = p;

      ans[u][v] = c;

      ans[v][u] = c;

    }

  }

  rep(i, n - 1) repi(j, i + 1, n) {

    cout << ans[i][j] << (j == (n - 1) ? '\n' : ' ');

  }

}
