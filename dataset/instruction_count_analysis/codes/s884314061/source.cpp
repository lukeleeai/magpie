#include "stdc++.h"



using namespace std;



#define REP(i,a,b) for(int i=a;i<(int)b;i++)

#define rep(i,n) REP(i,0,n)

#define all(c) (c).begin(), (c).end()

#define zero(a) memset(a, 0, sizeof a)

#define minus(a) memset(a, -1, sizeof a)

#define watch(a) { std::cout << #a << " = " << a << "\n"; }

template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }

template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }

template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }

template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }



typedef long long ll;

int const inf = 1<<29;



#define MAX_V 100010

#define MAX_LOG_V 40



vector<int> G[MAX_V];

int root;

int deg[MAX_V];



int parent[MAX_LOG_V][MAX_V];  

int depth[MAX_V];



void dfs(int v, int p, int d)

{

    parent[0][v] = p;

    depth[v] = d;

    for (int i = 0; i < (int)G[v].size(); i++) { 

  if(G[v][i] != p) {

      dfs(G[v][i], v, d+1);

  }

    }

}



int getRoot(int V)

{

    for (int i = 0; i < V; i++) {

  if (deg[i] == 0) {

      return i;

  }

    }

    return -1;

}



void init(int V)

{

    root = getRoot(V);

    dfs(root, -1, 0);

    for (int k = 0; k + 1 < MAX_LOG_V; k++) {

  for (int v = 0; v < V; v++) {

      if (parent[k][v] < 0) {

    parent[k+1][v] = -1;

      } else {

    parent[k+1][v] = parent[k][parent[k][v]];

      }

  }

    }

}



int lca(int u, int v)

{

    if(depth[u] > depth[v]){

  swap(u, v);

    }

    for (int k = 0; k < MAX_LOG_V; k++) {

  if ((depth[v] - depth[u]) >> k & 1) {

      v = parent[k][v];

  }

    }

    if (u == v) {

        return u;

    }

    for (int k = MAX_LOG_V-1; k >= 0; k--) {

  if (parent[k][u] != parent[k][v]) {

      u = parent[k][u];

      v = parent[k][v];

  }

    }

    return parent[0][u];

}



int64_t val[100005];

vector<vector<pair<int, int64_t>>> g(100005);



int64_t walk(int from, int to) {

  return val[from] - val[to];

}



void dfs_val(int curr, int parent, int64_t sum) {

  rep(i, G[curr].size()) {

    if (g[curr][i].first == parent) continue;

    val[g[curr][i].first] = sum + g[curr][i].second;

    dfs_val(g[curr][i].first, curr, val[g[curr][i].first]);

  }

}



int main() {

  int N; cin >> N;

  rep(i, N - 1) {

    int a, b; int64_t c; cin >> a >> b >> c;

    a--, b--;

    G[a].push_back(b);

    G[b].push_back(a);

    g[a].emplace_back(b, c);

    g[b].emplace_back(a, c);

  }



  // 頂点を0とする

  int root = 0;

  dfs_val(root, -1, 0);

//  rep(i, N) { cout << val[i] << " "; }cout << "\n";

  init(N);



  int Q, K; cin >> Q >> K; K--;

  rep(i, Q) {

    int x, y; cin >> x >> y; x--, y--;

    // 探索を上に上がっていくだけで良いようする

    auto calc = [&](int x) {

      int64_t sum = 0;

      if (lca(x, K) == K) {

        sum += walk(x, K);

      } else if (lca(x, K) == x) {

        sum += walk(K, x);

      } else {

        int m = lca(x, K);

        sum += walk(x, m) + walk(K, m);

      }

      return sum;

    };

    int64_t a = calc(x);

    int64_t b = calc(y);

    cout << a + b << "\n";

  }

}
