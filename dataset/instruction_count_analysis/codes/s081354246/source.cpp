#include "stdc++.h"

using namespace std;



using i32 = std::int_fast32_t;

using i64 = std::int_fast64_t;

template <typename T> constexpr T inf = numeric_limits<T>::has_infinity ? numeric_limits<T>::infinity() : numeric_limits<T>::max() / 4;



#define REP(i, stop) FOR(i, 0, stop)

#define FOR(i, start, stop) for (int i = start, i##_len = stop; i < i##_len; ++i)

#define RREP(i, n) for (int i = n; i-- > 0;)

#define ALL(v) (v).begin(), (v).end()

#define RALL(v) (v).rbegin(), (v).rend()

#define COMP(key) [](const auto& a, const auto& b) { return a.key < b.key; }



template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& a) { return is >> a.first >> a.second; }

template<typename T> istream& operator>>(istream& is, vector<T>& a) { for (T& x : a) is >> x; return is; }



void LOG(const int& x) { cerr << x << "\n"; }

template<typename T> void LOG(const vector<T>& a) { for (const T& x : a) cerr << x << " "; cerr << "\n"; }

template<typename T, std::size_t S> void LOG(const T (&a)[S]) { REP(i, S) cerr << a[i] << " "; cerr << "\n"; }

template<typename T, std::size_t S, std::size_t R> void LOG(const T (&a)[S][R]) { REP(i, S) { REP(j, R) cerr << a[i][j] << " "; cerr << "\n"; } }



i64 ceil(i64 a, i64 b) { return (a - 1) / b + 1; }

i64 gcd(i64 a, i64 b) { while (b != 0) { i64 t = b; b = a % b; a = t; } return a; }

i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }

i64 gcd(const vector<i64>& v) { return accumulate(ALL(v), 1LL, static_cast<i64(*)(i64, i64)>(gcd)); }

i64 lcm(const vector<i64>& v) { return v.empty() ? 0LL : accumulate(v.begin() + 1, v.end(), v[0], static_cast<i64(*)(i64, i64)>(lcm)); }

i64 pow(i64 x, i64 y, i64 z) { i64 a = 1; while (y > 0) { if (y & 1) a = a * x % z; x = x * x % z; y /= 2; } return a; }

i64 inv(i64 x, i64 m) { return pow(x, m - 2, m); }



struct InitCpp { InitCpp() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(10); } } initCpp;



signed main() {

  i64 n, k;

  cin >> n >> k;

  if (k > (n - 2) * (n - 1) / 2) {

    cout << -1 << endl;

  } else {

    cout << ((n - 1) + (n - 2) * (n - 1) / 2 - k) << endl;

    for (i64 i = 1; i <= n - 1; ++i) {

      cout << i << " " << n << endl;

    }

    i64 c = (n - 2) * (n - 1) / 2 - k;

    for (i64 i = 1; i <= n - 2; ++i) {

      for (i64 j = i + 1; j <= n - 1; ++j) {

        if (c > 0) {

          cout << i << " " << j << endl;

          c -= 1;

        } else {

          return 0;

        }

      }

    }

  }

}
