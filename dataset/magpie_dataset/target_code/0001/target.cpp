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



ll n, m, q;

vll a, b, c, d;

ll ans = 0;

vll seq {1};

void dfs(ll v){

  if(seq.size()== n){

    ll summ = 0;

    rep(i, 0, q) if(seq.at(b.at(i) - 1) - seq.at(a.at(i) - 1) == c.at(i)) summ += d.at(i);

    chmax(ans, summ);

    return;

  }

  rep(nv, seq.back(), m + 1){

    seq.push_back(nv);

    dfs(nv);

    seq.pop_back();

  }

  return;

}



int main(){

  cin >> n >> m >> q;

  a.assign(q, 0), b.assign(q, 0), c.assign(q, 0), d.assign(q, 0);

  rep(i, 0, q) cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);

  dfs(1);

  cout << ans << endl;

}