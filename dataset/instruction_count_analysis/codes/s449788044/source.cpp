#include "stdc++.h"



using namespace std;



using int64 = long long;



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

struct BiconnectedComponents {

  vector< int > ord, low;

  vector< bool > used;

  vector< vector< int > > g;

  vector< vector< pair< int, int > > > bc;

  vector< pair< int, int > > tmp;

  int n, k = 0;



  BiconnectedComponents(const G &g) : g(g) {

    n = (int) g.size();

    ord.resize(n, -1);

    low.resize(n, -1);

    used.resize(n, false);

  }



  void dfs(int u, int prev) {

    used[u] = true;

    ord[u] = k++;

    low[u] = ord[u];

    int cnt = 0;

    for(auto v : g[u])

      if(v != prev) {

        if(ord[v] < ord[u]) {

          tmp.emplace_back(min(u, v), max(u, v));

        }

        if(!used[v]) {

          cnt++;

          dfs(v, u);

          low[u] = min(low[u], low[v]);

          if(low[v] >= ord[u]) {

            bc.push_back({});

            while(true) {

              pair< int, int > e = tmp.back();

              bc.back().emplace_back(e);

              tmp.pop_back();

              if(min(u, v) == e.first && max(u, v) == e.second) {

                break;

              }

            }

          }

        } else {

          low[u] = min(low[u], ord[v]);

        }

      }

  }

};



struct UnionFind {

  vector< int > data;



  UnionFind(int sz) {

    data.assign(sz, -1);

  }



  bool unite(int x, int y) {

    x = find(x), y = find(y);

    if(x == y) return (false);

    if(data[x] > data[y]) swap(x, y);

    data[x] += data[y];

    data[y] = x;

    return (true);

  }



  int find(int k) {

    if(data[k] < 0) return (k);

    return (data[k] = find(data[k]));

  }



  int size(int k) {

    return (-data[find(k)]);

  }

};



const int mod = 1e9 + 7;



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



int64_t mod_pow(int64_t x, int64_t n, int64_t mod) {

  int64_t ret = 1;

  while(n > 0) {

    if(n & 1) (ret *= x) %= mod;

    (x *= x) %= mod;

    n >>= 1;

  }

  return ret;

}



struct Combination {

  int mod;

  vector< int64_t > mfact, rfact;



  Combination(int sz, int mod) : mfact(sz + 1), rfact(sz + 1), mod(mod) {

    mfact[0] = 1;

    for(int i = 1; i < mfact.size(); i++) {

      mfact[i] = mfact[i - 1] * i % mod;

    }

    rfact[sz] = inv(mfact[sz]);

    for(int i = sz - 1; i >= 0; i--) {

      rfact[i] = rfact[i + 1] * (i + 1) % mod;

    }

  }



  int64_t fact(int k) const {

    return (mfact[k]);

  }



  int64_t pow(int64_t x, int64_t n) const {

    int64_t ret = 1;

    while(n > 0) {

      if(n & 1) (ret *= x) %= mod;

      (x *= x) %= mod;

      n >>= 1;

    }

    return (ret);

  }



  int64_t inv(int64_t x) const {

    return (pow(x, mod - 2));

  }



  int64_t P(int n, int r) const {

    if(r < 0 || n < r) return (0);

    return (mfact[n] * rfact[n - r] % mod);

  }



  int64_t C(int p, int q) const {

    if(q < 0 || p < q) return (0);

    return (mfact[p] * rfact[q] % mod * rfact[p - q] % mod);

  }



  int64_t H(int n, int r) const {

    if(n < 0 || r < 0) return (0);

    return (r == 0 ? 1 : C(n + r - 1, r));

  }

};



int main() {

  int N, M, K;

  cin >> N >> M >> K;

  UnWeightedGraph g(N);

  Combination beet(101010, mod);

  UnionFind uf(N);

  while(M--) {

    int x, y;

    cin >> x >> y;

    --x, --y;

    g[x].push_back(y);

    g[y].push_back(x);

    uf.unite(x, y);

  }

  BiconnectedComponents< UnWeightedGraph > bcc(g);

  for(int i = 0; i < N; i++) {

    if(uf.find(i) == i) bcc.dfs(i, -1);

  }

  int64 ret = 1;

  for(auto &vs : bcc.bc) {

    set< int > vertex;

    for(auto &p : vs) vertex.emplace(p.first);

    for(auto &p : vs) vertex.emplace(p.second);

    if(vertex.size() == vs.size() + 1) {

      ret *= K;

      ret %= mod;

    } else if(vertex.size() == vs.size()) {

      int64 add = 0;

      for(int i = 1; i <= vertex.size(); i++) {

        if(vertex.size() % i == 0) {

          add += beet.pow(K, vertex.size() / i) * euler_phi(i) % mod;

          add %= mod;

        }

      }

      add *= beet.inv(vertex.size());

      add %= mod;

      ret *= add;

      ret %= mod;

    } else if(vertex.size() < vs.size()) {

      // vs.size()辺をK色で塗る組み合わせ(ほんまか？

      ret *= beet.H(K, vs.size());

      ret %= mod;

      // cout << "foo" << endl;

    } else {

      assert(0);

    }

  }



  cout << ret << endl;

}