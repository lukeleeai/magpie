#pragma region Macros

#include "stdc++.h"

using namespace std;

//#include <boost/multiprecision/cpp_int.hpp>

//using multiInt = boost::multiprecision::cpp_int;



using ll = long long int;

using ld = long double;

using pii = pair<int, int>;

using pll = pair<ll, ll>;

using pld = pair<ld, ld>;

template <typename Q_type>

using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;



const int MOD_TYPE = 1;

const ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);

const int INF = (int)1e9;

const ll LINF = (ll)4e18;

const ld PI = acos(-1.0);

const ld EPS = 1e-11;



#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)

#define rep(i, n) REP(i, 0, n)

#define MP make_pair

#define MT make_tuple

#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"

#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"

#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"

#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"

#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"

#define all(v) v.begin(), v.end()

#define NP(v) next_permutation(all(v))

#define dbg(x) cerr << #x << ":" << x << "\n";



vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};

vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};



#pragma endregion



class UnionFind

{

private:

  vector<int> par, sizes;



public:

  UnionFind(int n = 200010) : par(n), sizes(n, 1)

  {

    rep(i, n) par[i] = i;

  }



  int root(int x)

  {

    if (x == par[x])

      return x;

    return par[x] = root(par[x]);

  }



  void unite(int x, int y)

  {

    x = root(x);

    y = root(y);

    if (x == y)

      return;

    if (sizes[x] < sizes[y])

      swap(x, y);

    par[y] = x;

    sizes[x] += sizes[y];

  }



  bool same(int x, int y)

  {

    return root(x) == root(y);

  }



  int size(int x)

  {

    return sizes[root(x)];

  }

};



int main()

{

  cin.tie(0);

  ios::sync_with_stdio(false);

  cout << setprecision(30) << setiosflags(ios::fixed);



  int n, m;

  cin >> n >> m;

  string s[50];

  rep(i, n) cin >> s[i];

  UnionFind uf;

  rep(i, n) rep(j, m - 1)

  {

    if (s[i][j] == '#' && s[i][j + 1] == '#')

      uf.unite(i * m + j, i * m + j + 1);

  }

  rep(j, m) rep(i, n - 1)

  {

    if (s[i][j] == '#' && s[i + 1][j] == '#')

      uf.unite(i * m + j, (i + 1) * m + j);

  }

  rep(i, n) rep(j, m)

  {

    if (s[i][j] == '.')

      continue;

    if (uf.size(i * m + j) == 1)

    {

      Yes(false);

      return 0;

    }

  }

  Yes(true);

  return 0;

}
