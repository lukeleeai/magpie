#include<cstdio>

#include<vector>

#include<set>



using namespace std;





typedef vector<vector<int> > graph_t;





void dfs(int u, int previous, 

      const graph_t& g, int &timer, vector<bool>& visited, 

      vector<int>& parent, vector<int>& prenum, vector<int>& lowest) {

  prenum[u] = lowest[u] = timer;

  timer++;



  visited[u] = true;



  for (size_t i = 0; i < g[u].size(); ++i) {

    int next = g[u][i];

    if (!visited[next]) {

      parent[next] = u;



      dfs(next, u, g, timer, visited, parent, prenum, lowest);



      lowest[u] = min(lowest[u], lowest[next]);

    }

    else if (next != previous) {

      lowest[u] = min(lowest[u], prenum[next]);

    }

  }

}



void solve(int n, int k) {

  graph_t g(n);



  for (int i = 0; i < k; ++i) {

    int u, v;

    scanf("%d %d", &u, &v);

    g[u].push_back(v);

    g[v].push_back(u);

  }



  vector<bool> visited(n, false);

  vector<int> prenum(n, -1), lowest(n, -1), parent(n, -1);

  int timer = 1;

  dfs(0, -1, g, timer, visited, parent, prenum, lowest);



  set<int> ap;

  int np = 0;

  for (int i = 1; i < n; ++i) {

    int p = parent[i];

    if (p == 0) np++;

    else if (prenum[p] <= lowest[i]) ap.insert(p);

  }

  if (np > 1) ap.insert(0);

  for (set<int>::iterator iter = ap.begin(); iter != ap.end(); ++iter)

    printf("%d\n", *iter);

}



int main() {



  int n, k;

  scanf("%d %d", &n, &k);



  solve(n, k);

  return 0;

}


