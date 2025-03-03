#define __USE_MINGW_ANSI_STDIO 0

#include "stdc++.h"



using namespace std;

typedef long long ll;

#define int ll

typedef vector<int> VI;

typedef vector<VI> VVI;

typedef pair<int, int> PII;



#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)

#define REP(i, n) FOR(i, 0, n)

#define ALL(x) x.begin(), x.end()

#define IN(a, b, x) (a<=x&&x<b)

#define PB push_back



const ll LLINF = (1LL<<60);

const int INF = (1LL<<30);

const int MOD = 1000000007;



template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }

template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

template<typename T> T ceil(T a, T b) { return a/b + !!(a%b); }

template<class S,class T>

ostream &operator <<(ostream& out,const pair<S,T>& a){

  out<<'('<<a.first<<','<<a.second<<')';

  return out;

}



int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};



template<unsigned MOD>

class ModInt {

public:

  unsigned x;

  ModInt(): x(0) { }

  ModInt(signed y) : x(y >= 0 ? y % MOD : MOD - (-y) % MOD) {}

  unsigned get() const { return x; }



  // 逆数

  ModInt inv() const {

    ll a = 1, p = x, e = MOD-2;

    while(e > 0) {

      if(e%2 == 0) {p = (p*p) % MOD; e /= 2;}

      else {a = (a*p) % MOD; e--;}

    }

    a %= MOD;

    return ModInt(a);

  }

  // e乗

  ModInt pow(ll e) {

    ll a = 1, p = x;

    while(e > 0) {

      if(e%2 == 0) {p = (p*p) % MOD; e /= 2;}

      else {a = (a*p) % MOD; e--;}

    }

    a %= MOD;

    return ModInt(a);

  }

  // 2のx乗

  ModInt pow2() {

    ll a = 1, p = 2, e = x;

    while(e > 0) {

      if(e%2 == 0) {p = (p*p) % MOD; e /= 2;}

      else {a = (a*p) % MOD; e--;}

    }

    a %= MOD;

    return ModInt(a);

  }



  // Comparators

  bool operator <(ModInt b) { return x < b.x; }

  bool operator >(ModInt b) { return x > b.x; }

  bool operator<=(ModInt b) { return x <= b.x; }

  bool operator>=(ModInt b) { return x >= b.x; }

  bool operator!=(ModInt b) { return x != b.x; }

  bool operator==(ModInt b) { return x == b.x; }



  // increment, decrement

  ModInt operator++() { x++; return *this; }

  // ModInt operator++(int) {ModInt a = *this; x++; return a;}

  ModInt operator--() { x--; return *this; }

  // ModInt operator--(int) {ModInt a = *this; x--; return a;}



  // Basic Operations

  ModInt &operator+=(ModInt that) {

    x = ((ll)x+that.x)%MOD;

    return *this;

  }

  ModInt &operator-=(ModInt that) {

    x = ((((ll)x-that.x)%MOD)+MOD)%MOD;

    return *this;

  }

  ModInt &operator*=(ModInt that) {

    x = (ll)x * that.x % MOD;

    return *this;

  }

  // O(log(mod))かかるので注意

  ModInt &operator/=(ModInt that) {

    x = (ll)x * that.inv() % MOD;

    return *this;

  }

  ModInt &operator%=(ModInt that) {

    x = (ll)x % that.x;

    return *this;

  }

  ModInt operator+(ModInt that)const{return ModInt(*this) += that;}

  ModInt operator-(ModInt that)const{return ModInt(*this) -= that;}

  ModInt operator*(ModInt that)const{return ModInt(*this) *= that;}

  ModInt operator/(ModInt that)const{return ModInt(*this) /= that;}

  ModInt operator%(ModInt that)const{return ModInt(*this) %= that;}

};

typedef ModInt<1000000007> mint;

// Input/Output

ostream &operator<<(ostream& os, mint a) { return os << a.x; }

istream &operator>>(istream& is, mint &a) { return is >> a.x; }



int a[200010], b[200010], c[200010], d[100010];

vector<PII> g[100010];

mint dp1[100010], dp2[100010];

signed main(void)

{

  int n, m, s, t;

  cin >> n >> m >> s >> t;

  s--, t--;

  REP(i, m) {

    cin >> a[i] >> b[i] >> c[i];

    a[i]--, b[i]--;

    g[a[i]].PB({b[i], c[i]});

    g[b[i]].PB({a[i], c[i]});

  }



  REP(i, n) d[i] = LLINF;

  d[s] = 0;

  priority_queue<PII, vector<PII>, greater<PII>> que;

  que.push({d[s], s});



  while(que.size()) {

    PII p = que.top(); que.pop();

    if(p.second == t) continue;

    if(p.first > d[p.second]) continue;

    for(PII e: g[p.second]) {

      if(d[e.first] > d[p.second] + e.second) {

        d[e.first] = d[p.second] + e.second;

        que.push({d[e.first], e.first});

      }

    }

  }



  // REP(i, n) cout << d[i] << (i==n-1?"\n":" ");



  vector<PII> vec;

  REP(i, n) vec.PB({d[i], i});

  sort(ALL(vec));



  dp1[s] = 1;

  REP(i, n) {

    for(PII e: g[vec[i].second]) {

      if(d[vec[i].second] + e.second == d[e.first]) {

        dp1[e.first] += dp1[vec[i].second];

      }

    }

  }

  dp2[t] = 1;

  for(int i=n-1; i>=0; --i) {

    for(PII e: g[vec[i].second]) {

      if(d[vec[i].second] == d[e.first] + e.second) {

        dp2[e.first] += dp2[vec[i].second];

      }

    }

  }



  mint ret = dp1[t]*dp1[t];

  // cout << ret << endl;

  REP(i, n) {

    if(d[i]*2 == d[t]) {

      ret -= dp1[i]*dp1[i]*dp2[i]*dp2[i];

    }

  }

  // cout << ret << endl;

  REP(i, m) {

    int u = a[i], v = b[i];

    if(d[u] > d[v]) swap(u, v);

    if(2*d[u] < d[t] && 2*d[v] > d[t] && d[u] + c[i] == d[v]) {

      ret -= dp1[u]*dp1[u]*dp2[v]*dp2[v];

    }

  }

  cout << ret << endl;



  return 0;

}
