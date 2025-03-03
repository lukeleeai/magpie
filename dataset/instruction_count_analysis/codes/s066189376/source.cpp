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



// VI tsort(VVI g) {

//   int n = g.size();

//   vector<bool> used(n, false);

//   vector<int> ans;

//

//   function<void(int)> dfs = [&](int u) {

//     if(used[u]) return;

//     used[u] = true;

//     for(auto& i: g[u]) dfs(i);

//     ans.push_back(u);

//   };

//

//   for(int i=0; i<n; ++i) dfs(i);

//   reverse(ans.begin(), ans.end());

//   return ans;

// }



VI tsort(VVI g) {

  const int n = g.size();

  VI h(n, 0);

  REP(i, n) for(int j: g[i]) h[j]++;



  stack<int> st;

  REP(i, n) if(h[i] == 0) st.push(i);



  VI ans;

  while(st.size()) {

    int i = st.top(); st.pop();

    ans.push_back(i);

    for(auto& j: g[i]) {

      h[j]--;

      if(h[j] == 0) st.push(j);

    }

  }



  return ans;

}



signed main(void)

{

  cin.tie(0);

  ios::sync_with_stdio(false);



  int n, m;

  cin >> n >> m;

  VVI g(n, VI(0));

  REP(i, m) {

    int a, b;

    cin >> a >> b;

    g[a].PB(b);

  }



  VI ans = tsort(g);

  for(int i: ans) cout << i << endl;



  return 0;

}


