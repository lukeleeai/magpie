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

 

int N;

vector<vector<pair<int, int64_t>>> g;

vector<int64_t> dist;

 

void dfs(int curr, int par) {

  for (auto e: g[curr]) {

    int dest; int64_t cost; tie(dest, cost) = e;

    if (dest == par) continue;

    dist[dest] = dist[curr] + cost;

    dfs(dest, curr);

  }

}

 

int main() {

  cin >> N; g.resize(N);

  dist.resize(N);

  rep(i, N - 1) {

    int a, b, c; cin >> a >> b >> c;

    a--, b--;

    g[a].emplace_back(b, c);

    g[b].emplace_back(a, c);

  }

  int Q, K; cin >> Q >> K;

  K--;

  dfs(K, -1);

  rep(_, Q) {

    int x, y; cin >> x >> y;

    x--, y--;

    cout << dist[x] + dist[y] << "\n";

  }

}