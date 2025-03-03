#pragma region Macros

#include "stdc++.h"

using namespace std;

//#include <boost/multiprecision/cpp_int.hpp>

//using multiInt = boost::multiprecision::cpp_int;



using ll = long long int;

using ld = long double;

using pii = pair<int, int>;

using pll = pair<ll, ll>;

template <typename Q_type>

using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;



const int MOD_TYPE = 2;

const ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);

const int INF = (int)1e9;

const ll LINF = (ll)4e18;

const ld PI = acos(-1.0);

const ld EPS = 1e-11;



#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)

#define rep(i, n) REP(i, 0, n)

#define MP make_pair

#define MT make_tuple

#define YES(n) cout << ((n) ? "YES" : "NO") << endl

#define Yes(n) cout << ((n) ? "Yes" : "No") << endl

#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl

#define possible(n) cout << ((n) ? "possible" : "impossible") << endl

#define Yay(n) cout << ((n) ? "Yay!" : ":(") << endl

#define all(v) v.begin(), v.end()

#define NP(v) next_permutation(all(v))

#define dbg(x) cerr << #x << ":" << x << endl;



vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};

vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};



#pragma endregion



ll dp[100010][11];



ll f(int d, int b)

{

  if (dp[d][b] != -1)

    return dp[d][b];

  if (d == 0)

    return 1;



  ll res = 0;



  if (b == 10)

  {

    for (int i = 1; i <= 9; i++)

    {

      res += f(d - 1, i);

    }

  }

  else

  {

    for (int i = max(0, b - 1); i <= min(9, b + 1); i++)

    {

      res += f(d - 1, i);

    }

  }



  return dp[d][b] = res;

}



string ans;

ll k;



void calc(int di, int b)

{

  if (di == 0)

    return;

  ll val;





  if (b == 10)

  {

    for (int i = 1; i <= 9; i++)

    {

      val = f(di - 1, i);

      if (k <= val)

      {

        ans.push_back((char)(i + '0'));

        calc(di - 1, i);

        return;

      }

      k -= val;

    }

  }

  else

  {

    for (int i = max(0, b - 1); i <= min(9, b + 1); i++)

    {

      val = f(di - 1, i);

      if (k <= val)

      {

        ans.push_back((char)(i + '0'));

        calc(di - 1, i);

        return;

      }

      k -= val;

    }

  }

  assert(false);

}



int main()

{

  cin.tie(0);

  ios::sync_with_stdio(false);

  cout << setprecision(30) << setiosflags(ios::fixed);



  cin >> k;

  rep(i, 100010) rep(j, 11) dp[i][j] = -1;



  for (int d = 1; d <= 100010; d++)

  {

    ll val = f(d, 10);

    if (k <= val)

    {

      calc(d, 10);

      cout << ans << endl;

      return 0;

    }

    k -= val;

  }

  assert(false);

  return 0;

}
