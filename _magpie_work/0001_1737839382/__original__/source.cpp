#include "stdc++.h"

using namespace std;



using ll = long long;

using ull = unsigned long long;

using st = string;

using ch = char;

using db = double;

using bl = bool;

using vll = vector<long long>;

using vdb = vector<db>;

using vvll = vector<vll>;

using vst = vector<st>;

using vch = vector<char>;

using pll = pair<ll, ll>;

using vpll = vector<pll>;

using vvpll = vector<vpll>;

#define rep(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)

#define vrep(i, vec) for(auto& i : vec)

#define vin(vec) for(auto& i : vec) cin >> i

#define all(v) v.begin(), v.end()

template<class T> inline bool chmin(T& a, T b){if(a > b){a = b;return true;} return false;}

template<class T> inline bool chmax(T& a, T b){if(a < b){a = b;return true;} return false;}

const ll mod = 1000000007;

const ll inf = 1LL << 60;

const db pi = acos(-1.0L);



int main(){

  ll n, m, q;

  cin >> n >> m >> q;

  vll a(q), b(q), c(q), d(q);

  rep(i, 0, q) cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);



  ll ans = 0;

  vll seq(11, 1);

  for(seq.at(1) = seq.at(0); seq.at(1) < m + 1; seq.at(1)++)for(seq.at(2) = seq.at(1); seq.at(2) < m + 1; seq.at(2)++)

  for(seq.at(3) = seq.at(2); seq.at(3) < m + 1; seq.at(3)++)for(seq.at(4) = seq.at(3); seq.at(4) < m + 1; seq.at(4)++)

  for(seq.at(5) = seq.at(4); seq.at(5) < m + 1; seq.at(5)++)for(seq.at(6) = seq.at(5); seq.at(6) < m + 1; seq.at(6)++)

  for(seq.at(7) = seq.at(6); seq.at(7) < m + 1; seq.at(7)++)for(seq.at(8) = seq.at(7); seq.at(8) < m + 1; seq.at(8)++)

  for(seq.at(9) = seq.at(8); seq.at(9) < m + 1; seq.at(9)++)for(seq.at(10) = seq.at(9); seq.at(10) < m + 1; seq.at(10)++){

    ll summ = 0;

    rep(i, 0, q) if(seq.at(b.at(i)) - seq.at(a.at(i)) == c.at(i)) summ += d.at(i);

    chmax(ans, summ);

  }

  cout << ans << endl;

}