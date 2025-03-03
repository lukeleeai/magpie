#define MOD_TYPE 1



#pragma region Macros

#include "stdc++.h"

using namespace std;

/*

#include <boost/multiprecision/cpp_int.hpp>

using multiInt = boost::multiprecision::cpp_int;

*/

/*

#pragma GCC target("avx2")

#pragma GCC optimize("O3")

#pragma GCC optimize("unroll-loops")

*/

using ll = long long int;

using ld = long double;

using pii = pair<int, int>;

using pll = pair<ll, ll>;

using pld = pair<ld, ld>;

template <typename Q_type>

using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;



constexpr ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);

constexpr int INF = (int)1e9;

constexpr ll LINF = (ll)4e18;

constexpr ld PI = acos(-1.0);

constexpr ld EPS = 1e-11;

constexpr int Dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

constexpr int Dy[] = {1, -1, 0, 0, -1, -1, 1, 1, 0};



#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)

#define rep(i, n) REP(i, 0, n)

#define MP make_pair

#define MT make_tuple

#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"

#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"

#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"

#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"

#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"

#define all(v) v.begin(), v.end()

#define NP(v) next_permutation(all(v))

#define dbg(x) cerr << #x << ":" << x << "\n";



inline void init_main()

{

  cin.tie(0);

  ios::sync_with_stdio(false);

  cout << setprecision(30) << setiosflags(ios::fixed);

}

template <typename T>

inline bool chmin(T &a, T b)

{

  if (a > b)

  {

    a = b;

    return true;

  }

  return false;

}

template <typename T>

inline bool chmax(T &a, T b)

{

  if (a < b)

  {

    a = b;

    return true;

  }

  return false;

}

inline ll CEIL(ll a, ll b)

{

  return (a + b - 1) / b;

}

#pragma endregion



int main()

{

  init_main();



  int h, w;

  cin >> h >> w;

  string s[50];

  rep(i, h) cin >> s[i];

  rep(i, h) rep(j, w)

  {

    if (s[i][j] == '.')

      continue;

    bool black = false;

    if (i + 1 != h && s[i + 1][j] == '#')

      black = true;

    if (i - 1 >= 0 && s[i - 1][j] == '#')

      black = true;

    if (j + 1 != w && s[i][j + 1] == '#')

      black = true;

    if (j - 1 >= 0 && s[i][j - 1] == '#')

      black = true;

    if (!black)

    {

      Yes(0);

      return 0;

    }

  }

  Yes(1);

  return 0;

}
