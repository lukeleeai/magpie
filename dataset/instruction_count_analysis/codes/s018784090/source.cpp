#define __USE_MINGW_ANSI_STDIO 0

#include "stdc++.h"



using namespace std;

using ll = long long;

#define int ll

using VI = vector<int>;

using VVI = vector<VI>;

using PII = pair<int, int>;



#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)

#define REP(i, n) FOR(i, 0, n)

#define ALL(x) x.begin(), x.end()

#define PB push_back



const ll LLINF = (1LL<<60);

const int INF = (1LL<<30);

const int MOD = 1000000007;



template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }

template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

template <typename T> bool IN(T a, T b, T x) { return a<=x&&x<b; }

template<typename T> T ceil(T a, T b) { return a/b + !!(a%b); }

template<class S,class T>

ostream &operator <<(ostream& out,const pair<S,T>& a){

  out<<'('<<a.first<<','<<a.second<<')';

  return out;

}

template<class T>

ostream &operator <<(ostream& out,const vector<T>& a){

  out<<'[';

  REP(i, a.size()) {out<<a[i];if(i!=a.size()-1)out<<',';}

  out<<']';

  return out;

}



int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};



VI g[100010];

signed main(void)

{

  int n;

  cin >> n;

  REP(i, n-1) {

    int u, v;

    cin >> u >> v;

    u--, v--;

    g[u].PB(v);

    g[v].PB(u);

  }



  VI dist(n);

  function<void(int,int)> dfs1 = [&](int v, int p) {

    for(int &i: g[v]) if(i != p) {

      dfs1(i, v);

      chmax(dist[v], dist[i] + 1);

    }

  };



  dfs1(0, -1);

  // cout << dist << endl;



  // ans[i] = (頂点iから最も遠い頂点)

  VI ans(n);

  function<void(int,int,int)> dfs2 = [&](int v, int pval, int p) {

    // vの子の情報を集める

    vector<PII> d_child;

    // d_child[0], d_child[1]が存在しないのを防ぐ

    d_child.PB({0, -1});

    for(int &i: g[v]) {

      if(i == p) d_child.PB({pval+1, i});

      else d_child.PB({dist[i]+1, i});

    }

    sort(ALL(d_child), greater<>());

    ans[v] = d_child[0].first;

    for(int &i: g[v]) if(i != p) {

      // pvalはd_childの最大が基本

      // 最大が頂点iの部分木ならそれがpvalにはならないので次に大きいのをpvalにする

      dfs2(i, d_child[d_child[0].second == i].first, v);

    }

  };



  dfs2(0, 0, -1);

  // cout << ans << endl;



  // 全ての辺を2回通るのが基本で最大の深さのところだけ行って戻らないので片道分でいい

  REP(i, n) cout << 2*(n-1) - ans[i] << endl;



  return 0;

}


