#include"stdc++.h"



using namespace std;



using int64 = long long;

const int mod = 1e9 + 7;



const int64 infll = (1LL << 62) - 1;

const int inf = (1 << 30) - 1;



struct IoSetup {

  IoSetup() {

    cin.tie(nullptr);

    ios::sync_with_stdio(false);

    cout << fixed << setprecision(10);

    cerr << fixed << setprecision(10);

  }

} iosetup;





template< typename T1, typename T2 >

ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {

  os << p.first << " " << p.second;

  return os;

}



template< typename T1, typename T2 >

istream &operator>>(istream &is, pair< T1, T2 > &p) {

  is >> p.first >> p.second;

  return is;

}



template< typename T >

ostream &operator<<(ostream &os, const vector< T > &v) {

  for(int i = 0; i < (int) v.size(); i++) {

    os << v[i] << (i + 1 != v.size() ? " " : "");

  }

  return os;

}



template< typename T >

istream &operator>>(istream &is, vector< T > &v) {

  for(T &in : v) is >> in;

  return is;

}



template< typename T1, typename T2 >

inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }



template< typename T1, typename T2 >

inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }



template< typename T = int64 >

vector< T > make_v(size_t a) {

  return vector< T >(a);

}



template< typename T, typename... Ts >

auto make_v(size_t a, Ts... ts) {

  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));

}



template< typename T, typename V >

typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {

  t = v;

}



template< typename T, typename V >

typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {

  for(auto &e : t) fill_v(e, v);

}



template< typename T >

struct edge {

  int src, to;

  T cost;



  edge(int to, T cost) : src(-1), to(to), cost(cost) {}



  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}



  edge &operator=(const int &x) {

    to = x;

    return *this;

  }



  operator int() const { return to; }

};



template< typename T >

using Edges = vector< edge< T > >;

template< typename T >

using WeightedGraph = vector< Edges< T > >;

using UnWeightedGraph = vector< vector< int > >;

template< typename T >

using Matrix = vector< vector< T > >;



template< typename G >

struct LowLink {

  const G &g;

  vector< int > used, ord, low;

  vector< int > articulation;

  vector< pair< int, int > > bridge;



  LowLink(const G &g) : g(g) {}



  int dfs(int idx, int k, int par) {

    used[idx] = true;

    ord[idx] = k++;

    low[idx] = ord[idx];

    bool is_articulation = false;

    int cnt = 0;

    for(auto &to : g[idx]) {

      if(!used[to]) {

        ++cnt;

        k = dfs(to, k, idx);

        low[idx] = min(low[idx], low[to]);

        is_articulation |= ~par && low[to] >= ord[idx];

        if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int) to));

      } else if(to != par) {

        low[idx] = min(low[idx], ord[to]);

      }

    }

    is_articulation |= par == -1 && cnt > 1;

    if(is_articulation) articulation.push_back(idx);

    return k;

  }



  virtual void build() {

    used.assign(g.size(), 0);

    ord.assign(g.size(), 0);

    low.assign(g.size(), 0);

    int k = 0;

    for(int i = 0; i < g.size(); i++) {

      if(!used[i]) k = dfs(i, k, -1);

    }

  }

};





template< typename G >

struct BiConnectedComponents : LowLink< G > {

  using LL = LowLink< G >;



  vector< int > used;

  vector< vector< pair< int, int > > > bc;

  vector< pair< int, int > > tmp;



  BiConnectedComponents(const G &g) : LL(g) {}



  void dfs(int idx, int par) {

    used[idx] = true;

    for(auto &to : this->g[idx]) {

      if(to == par) continue;

      if(!used[to] || this->ord[to] < this->ord[idx]) {

        tmp.emplace_back(minmax(idx, to));

      }

      if(!used[to]) {

        dfs(to, idx);

        if(this->low[to] >= this->ord[idx]) {

          bc.emplace_back();

          for(;;) {

            auto e = tmp.back();

            bc.back().emplace_back(e);

            tmp.pop_back();

            if(e.first == min(idx, to) && e.second == max(idx, to)) {

              break;

            }

          }

        }

      }

    }

  }



  void build() override {

    LL::build();

    used.assign(this->g.size(), 0);

    for(int i = 0; i < used.size(); i++) {

      if(!used[i]) dfs(i, -1);

    }

  }

};



template< int mod >

struct ModInt {

  int x;



  ModInt() : x(0) {}



  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}



  ModInt &operator+=(const ModInt &p) {

    if((x += p.x) >= mod) x -= mod;

    return *this;

  }



  ModInt &operator-=(const ModInt &p) {

    if((x += mod - p.x) >= mod) x -= mod;

    return *this;

  }



  ModInt &operator*=(const ModInt &p) {

    x = (int) (1LL * x * p.x % mod);

    return *this;

  }



  ModInt &operator/=(const ModInt &p) {

    *this *= p.inverse();

    return *this;

  }



  ModInt operator-() const { return ModInt(-x); }



  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }



  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }



  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }



  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }



  bool operator==(const ModInt &p) const { return x == p.x; }



  bool operator!=(const ModInt &p) const { return x != p.x; }



  ModInt inverse() const {

    int a = x, b = mod, u = 1, v = 0, t;

    while(b > 0) {

      t = a / b;

      swap(a -= t * b, b);

      swap(u -= t * v, v);

    }

    return ModInt(u);

  }



  ModInt pow(int64_t n) const {

    ModInt ret(1), mul(x);

    while(n > 0) {

      if(n & 1) ret *= mul;

      mul *= mul;

      n >>= 1;

    }

    return ret;

  }



  friend ostream &operator<<(ostream &os, const ModInt &p) {

    return os << p.x;

  }



  friend istream &operator>>(istream &is, ModInt &a) {

    int64_t t;

    is >> t;

    a = ModInt< mod >(t);

    return (is);

  }

};



using modint = ModInt< mod >;



template< typename T >

struct Combination {

  vector< T > _fact, _rfact;



  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1) {

    _fact[0] = _rfact[sz] = 1;

    for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;

    _rfact[sz] /= _fact[sz];

    for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);

  }



  inline T fact(int k) const { return _fact[k]; }



  inline T rfact(int k) const { return _rfact[k]; }



  T P(int n, int r) const {

    if(r < 0 || n < r) return 0;

    return fact(n) * rfact(n - r);

  }



  T C(int p, int q) const {

    if(q < 0 || p < q) return 0;

    return fact(p) * rfact(q) * rfact(p - q);

  }



  T H(int n, int r) const {

    if(n < 0 || r < 0) return (0);

    return r == 0 ? 1 : C(n + r - 1, r);

  }

};



int64_t euler_phi(int64_t n) {

  int64_t ret = n;

  for(int64_t i = 2; i * i <= n; i++) {

    if(n % i == 0) {

      ret -= ret / i;

      while(n % i == 0) n /= i;

    }

  }

  if(n > 1) ret -= ret / n;

  return ret;

}



int main() {

  int N, M, K;

  cin >> N >> M >> K;

  UnWeightedGraph g(N);

  Combination< modint > beet(101010);

  while(M--) {

    int x, y;

    cin >> x >> y;

    --x, --y;

    g[x].push_back(y);

    g[y].push_back(x);

  }

  BiConnectedComponents< UnWeightedGraph > bcc(g);

  bcc.build();

  modint ret = 1;

  for(auto &vs : bcc.bc) {

    set< int > vertex;

    for(auto &p : vs) vertex.emplace(p.first);

    for(auto &p : vs) vertex.emplace(p.second);

    if(vertex.size() == vs.size() + 1) {

      ret *= K;

    } else if(vertex.size() == vs.size()) {

      modint add = 0;

      for(int i = 1; i <= vertex.size(); i++) {

        if(vertex.size() % i == 0) {

          add += modint(K).pow(vertex.size() / i) * euler_phi(i);

        }

      }

      add /= vertex.size();

      ret *= add;

    } else {

      ret *= beet.H(K, vs.size());

    }

  }

  cout << ret << endl;

}