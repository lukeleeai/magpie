#include "stdc++.h"

using namespace std;

//#include <boost/multiprecision/cpp_int.hpp>

//using multiInt = boost::multiprecision::cpp_int;



using ll = long long int;

using ld = long double;

using pii = pair<int, int>;

using pll = pair<ll, ll>;

template <typename Q_temp>

using smaller_queue = priority_queue<Q_temp, vector<Q_temp>, greater<Q_temp>>;



const ll MOD = (ll)(1e9 + 7);

const int INF = (int)1e9;

const ll LINF = (ll)4e18;

const double PI = acos(-1.0);



#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)

#define rep(i, n) REP(i, 0, n)

#define MP make_pair

#define MT make_tuple

#define YES(n) cout << ((n) ? "YES" : "NO") << endl

#define Yes(n) cout << ((n) ? "Yes" : "No") << endl

#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl

#define all(v) v.begin(), v.end()

#define NP(v) next_permutation(all(v))

#define dbg(x) cerr << #x << ":" << x << endl;



vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};

vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};



pll calc(ll num, ll one_cnt)

{

  if (one_cnt == 0)

    return MP(0, num);

  pll res = calc((num + one_cnt) % 10, (num + one_cnt) / 10);

  res.first += one_cnt;

  return res;

}



int main()

{

  cin.tie(0);

  ios::sync_with_stdio(false);

  cout << setprecision(20) << setiosflags(ios::fixed);



  ll m;

  cin >> m;

  ll d[200010], c[200010];

  rep(i, m) cin >> d[i] >> c[i];

  ll ans = 0;

  ll a[200010];

  rep(i, m)

  {

    pll p = calc((d[i] * c[i]) % 10, (d[i] * c[i]) / 10);

    p.first += c[i] - 1;

    ans += p.first;

    a[i] = p.second;

  }



  rep(i, m - 1)

  {

    if (a[i] + a[i + 1] >= 10)

    {

      ans++;

      a[i + 1] = (a[i] + a[i + 1]) % 10 + 1;

    }

    else

    {

      a[i + 1] = a[i] + a[i + 1];

    }

    ans++;

  }

  cout << ans << endl;

  return 0;

}
