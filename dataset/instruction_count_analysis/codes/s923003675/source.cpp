#include"stdc++.h"

using namespace std;

using ll = long long;



const int N = 150000;

vector<int> g[N];

double dp[N];

double dp1[N];

double dp2[N];

double ans[N];



// †全方位木DP†はO(N)頂点からやると落とされちゃうめう



void dfs(int i, int p = -1) {

  int sz = (g[i].size() - (p != -1));

  for(int j : g[i]) if(j != p) {

    dfs(j, i);

    dp[i] += (1 + dp1[j]);

    dp1[i] += (1 + dp1[j]) / sz;

  }

}



void dfs2(int i, int p = -1) {

  ans[i] = dp[i] + (p != -1 ? dp2[i] : 0);

  for(int j : g[i]) if(j != p) {

    dp2[j] = 1 + (ans[i] - (1 + dp1[j])) / (g[i].size() - 1); /// コーナーに気をつけよう

    dfs2(j, i); ////

  }

  ans[i] /= g[i].size();

}



int main() {

  ios::sync_with_stdio(false), cin.tie(0);

  int n;

  cin >> n;

  if(n == 1) { //

    cout << 0.0 << endl;

    return 0;

  }

  if(n == 2) { //

    cout << 1.0 << endl;

    cout << 1.0 << endl;

    return 0;

  }

  for(int i = 0; i < n - 1; i++) {

    int a, b; cin >> a >> b; a--; b--;

    g[a].emplace_back(b);

    g[b].emplace_back(a);

  }

  int t = 0;

  for(int i = 0; i < n; i++) if(g[i].size() >= 2) t = i; /// はい

  dfs(t);

  dfs2(t);

  cout << fixed << setprecision(7);

  for(int i = 0; i < n; i++) cout << ans[i] << endl;

}


