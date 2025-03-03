// includes {{{

// #include<iostream>

// #include<iomanip>

// #include<algorithm>

// #include<vector>

// #include<stack>

// #include<queue>

// #include<map>

// #include<set>

// #include<tuple>

// #include<cmath>

// #include<random>

// #include<cassert>

// #include<bitset>

// #include<cstdlib>

// #include<deque>

// #include<multiset>

// #include<cstring>

// #include"stdc++.h"

// }}}

// using namespace std;

// using ll = long long;



/// --- ReRooting {{{ ///



#include <cassert>

#include <functional>

#include <queue>

#include <stack>

#include <tuple>

#include <utility>

#include <vector>

template < class Monoid >

struct ReRooting {

  using size_type = std::size_t;

  using edge_type = std::tuple< size_type, size_type, size_type >;

  using graph_type = std::vector< std::vector< edge_type > >;

  using T = typename Monoid::T;

  using dig_f_type =

      std::function< T(T, size_type edge_id, size_type from, size_type to) >;

  using after_f_type =

      std::function< T(T, size_type vertex_id, size_type degree_of_this) >;

  using vector_bool_type = std::vector< int >;

  graph_type graph;



  size_type n;



  std::vector< size_type > start;

  std::vector< T > dp;

  vector_bool_type did;

  std::vector< T > L;

  std::vector< T > R;



  dig_f_type dig;

  after_f_type after;

  static T default_dig(const T &a, ...) { return a; }

  static T default_after(const T &a, ...) { return a; }



  bool built;



  ReRooting() {}

  ReRooting(size_type n, dig_f_type dig = default_dig, after_f_type after = default_after)

      : dig(dig), after(after) {

    clear(n);

  }

  ReRooting(std::vector< std::vector< int > > graph, dig_f_type dig = default_dig,

            after_f_type after = default_after)

      : ReRooting(graph.size(), dig, after) {

    for(size_type from = 0; from < n; from++) {

      for(auto to : graph[from])

        if(static_cast< size_type >(to) < from) {

          add_edge(from, to);

        }

    }

  }



  void clear() { clear(n); }



  void clear(size_type n) {

    this->n = n;

    graph.resize(3 * n);

    dp.resize(3 * n);

    did.resize(3 * n);

    did.assign(3 * n, 0);

    L.resize(3 * n);

    R.resize(3 * n);

    start.resize(n);

    built = 0;

  }



  size_type added = 0;

  void add_edge(size_type a, size_type b, size_type id = static_cast< size_type >(-1)) {

    assert(!built);

    assert(a < n && b < n && a != b);

    if(id == static_cast< size_type >(-1)) id = added;

    graph[a].emplace_back(b, graph[b].size(), id);

    graph[b].emplace_back(a, graph[a].size() - 1, id);

    added++;

  }



  void set_dig(dig_f_type dig = default_dig) { this->dig = dig; }



  void set_after(after_f_type after = default_after) { this->after = after; }



  void build() {

    assert(!built);

    built = 1;

    if(n == 0) return;



    assert(added == n - 1);

    for(size_type i = 0; i + 1 < n; i++) {

      start[i + 1] = start[i] + graph[i].size() + 1;

    }

    dfs_first(0, graph[0].size());

  }



public:

  T dfs(size_type i) {

    return dfs(i, graph[i].size());

  }



  T dfs_from(size_type i, size_type j) {

    assert(built);

    assert(j < n);

    // TODO : どうする?

    // return dfs(i, , 0);

  }



private:

  T proceed_root(size_type i) {

    for(size_type x = 0; x < graph[i].size(); x++) {

      auto to = graph[i][x];

      size_type j, rev, edge_id;

      std::tie(j, rev, edge_id) = to;

      R[start[i] + x] = L[start[i] + x] = dig(dp[start[j] + rev], edge_id, i, j);

    }

    for(int x = 1; x < static_cast<int>(graph[i].size()); x++) L[start[i] + x] = Monoid::op(L[start[i] + x - 1], L[start[i] + x]);

    for(int x = static_cast<int>(graph[i].size()) - 2; x >= 0; x--) R[start[i] + x] = Monoid::op(R[start[i] + x], R[start[i] + x + 1]);

    return L[start[i] + graph[i].size() - 1];

  }



  void dfs_first(size_type i0, size_type p0) {

    std::vector< std::tuple< size_type, size_type, bool > > stk;

    stk.reserve(n);

    stk.emplace_back(i0, p0, 0);

    while(stk.size()) {

      size_type i, p;

      bool up;

      std::tie(i, p, up) = stk.back();

      stk.pop_back();

      int deg = graph[i].size() - (p != graph[i].size() ? 1 : 0);

      if(up) {

        did[start[i] + p] = 1;

        T res = Monoid::identity();

        if(p == graph[i].size()) {

          res = proceed_root(i);

        } else {

          for(size_type x = 0; x < graph[i].size(); x++)

            if(x != p) {

              size_type j, rev, edge_id;

              std::tie(j, rev, edge_id) = graph[i][x];

              res = Monoid::op(res, dig(dp[start[j] + rev], edge_id, i, j));

            }

        }

        dp[start[i] + p] = after(res, i, deg);

      } else {

        stk.emplace_back(i, p, 1);

        for(size_type x = 0; x < graph[i].size(); x++)

          if(x != p) {

            size_type j, rev, edge_id;

            std::tie(j, rev, edge_id) = graph[i][x];

            stk.emplace_back(j, rev, 0);

          }

      }

    }

  }



  T dfs(size_type i0, size_type p0) {

    assert(built);

    assert(i0 < n);

    assert(p0 <= graph[i0].size());

    if(did[start[i0] + p0]) return dp[start[i0] + p0];



    std::vector< std::tuple< size_type, size_type, bool > > stk;

    stk.reserve(n);

    stk.emplace_back(i0, p0, 0);

    while(stk.size()) {

      size_type i, p;

      bool up;

      std::tie(i, p, up) = stk.back();

      stk.pop_back();

      if(up) {

        int deg = graph[i].size() - (p != graph[i].size() ? 1 : 0);

        did[start[i] + p] = 1;

        T res = Monoid::identity();

        if(p == graph[i].size()) {

          res = proceed_root(i);

        } else {

          res = Monoid::op(p >= 1 ? L[start[i] + p - 1] : Monoid::identity(),

              p + 1 < graph[i].size() ? R[start[i] + p + 1] : Monoid::identity());

        }

        dp[start[i] + p] = after(res, i, deg);

      } else {

        stk.emplace_back(i, p, 1);

        if(p == graph[i].size()) {

          for(size_type x = 0; x < graph[i].size(); x++) {

            size_type j, rev, edge_id;

            std::tie(j, rev, edge_id) = graph[i][x];

            if(!did[start[j] + rev]) stk.emplace_back(j, rev, 0);

          }

        } else {

          if(!did[start[i] + graph[i].size()]) {

            stk.emplace_back(i, graph[i].size(), 0);

          }

        }

      }

    }

    return dp[start[i0] + p0];

  }

};



/// }}}--- ////





// includes {{{

#include <algorithm>

#include <bitset>

#include <cassert>

#include <cmath>

#include <cstdlib>

#include <iomanip>

#include <iostream>

#include <map>

#include <queue>

#include <random>

#include <set>

#include <stack>

#include <tuple>

#include <vector>

// #include<deque>

// #include<multiset>

// #include<cstring>

// #include"stdc++.h"

// }}}

using namespace std;

using ll = long long;



// my monoid, m-act {{{

struct MyMonoid {

  using T = double;

  static T op(const T &a, const T &b) { return a + b; }

  static constexpr T identity() { return 0; }

};

// }}}



using rerooting = ReRooting< MyMonoid >;

using T = rerooting::T;



T dig(T a, int id, int from, int to) { return a + 1; }



T after(T a, int i, int deg) {

  if(deg == 0) return a;

  return a / deg;

}



const int N = 1e5;

std::vector< std::vector< int > > g;

int n;

int main() {

  std::ios::sync_with_stdio(false), std::cin.tie(0);

  cin >> n;

  g.resize(n);

  for(int i = 0; i < n - 1; i++) {

    int a, b;

    std::cin >> a >> b;

    a--;

    b--;

    g[a].emplace_back(b);

    g[b].emplace_back(a);

  }

  rerooting rr(g, dig, after);

  rr.build();

  cout << fixed << setprecision(8);

  for(int i = 0; i < n; i++) cout << rr.dfs(i) << "\n";

  return 0;

}
