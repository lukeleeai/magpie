#include "stdc++.h"



using namespace std;



const int N = 123456;

int n, f[N][2], g[N][2], cnt[N];

map<int, int> ind;

vector<int> e[N];



void dfs(int u, int p, int& res, int& pos) {

  f[u][0] = f[u][1] = 1;

  g[u][0] = g[u][1] = 0;

  for (int i = 0; i < e[u].size(); ++i) {

    int v = e[u][i];

    if (v == p) continue;

    dfs(v, u, res, pos);

    if (f[u][0] < f[v][0] + 1) {

      f[u][1] = f[u][0];

      g[u][1] = g[u][0];

      f[u][0] = f[v][0] + 1;

      g[u][0] = v;

    } else if (f[u][1] < f[v][0] + 1) {

      f[u][1] = f[v][0] + 1;

      g[u][1] = v;

    }

  }

  if (res < f[u][0] + f[u][1]) {

    res = f[u][0] + f[u][1] - 1;

    pos = u;

  }

}



vector<int> sol(int m, int a[]) {

  vector<int> r;

  int beg = 1;

  for (int i = 0; i < m; ++i) {

    int end = beg + a[i] - 1;

    

    for (int j = beg + 1; j <= end; ++j) r.push_back(j);

    r.push_back(beg);



    beg = end + 1;

  }

  return r;

}



int cmp(vector<int>& a, vector<int>& b) {

  for (int i = 0; i < a.size(); ++i) {

    if (a[i] != b[i]) return a[i] - b[i];

  }

  return 0;

}



int main() {

  cin >> n;

  for (int i = 0, u, v; i < n - 1; ++i) {

    cin >> u >> v;

    e[u].push_back(v);

    e[v].push_back(u);

  }



  int res = 0, pos;

  dfs(1, 0, res, pos);



//  cout << res << "," << pos << endl;



  deque<int> path;

  for (int i = pos; i; i = g[i][0]) path.push_back(i);

  for (int i = g[pos][1]; i; i = g[i][0]) path.push_front(i);



//  for (int i = 0; i < path.size(); ++i) cout << path[i] << endl;

  for (int i = 0; i < path.size(); ++i) ind[path[i]] = i;

  memset(cnt, 0x00, sizeof(cnt));

  for (int i = 1; i <= n; ++i) {

    if (ind.count(i)) cnt[ind[i]]++;

    else {

      bool found = false;

      for (int j = 0; j < e[i].size(); ++j) {

        int v = e[i][j];

        if (ind.count(v)) {

          cnt[ind[v]]++;

          found = true;

          break;

        }

      }

      if (!found) {

        cout << "-1" << endl;

        return 0;

      }

    }

  }

  

  //for (int i = 0; i < path.size(); ++i) cout << cnt[i] << endl; 



  vector<int> r0 = sol(path.size(), cnt);



  reverse(cnt, cnt + path.size());

  vector<int> r1 = sol(path.size(), cnt);



  if (cmp(r0, r1) <= 0) {

    for (int i = 0; i < r0.size(); ++i) cout << r0[i] << (i == r0.size() - 1 ? "\n" : " ");

  } else {

    for (int i = 0; i < r1.size(); ++i) cout << r1[i] << (i == r0.size() - 1 ? "\n" : " ");

  }



  return 0;



}