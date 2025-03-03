#include <iostream>

#include <queue>

using namespace std;



vector<vector<int>> adj;

vector<int> visited;

vector<int> ans;

vector<int> deg;

int v;



void topologicalOrder() {

  queue<int> q;

  for (int i = 0; i < v; i++) {

    if (deg[i] == 0) q.push(i);

  }

  while (!q.empty()) {

    int x = q.front();

    q.pop();

    ans.push_back(x);

    for (auto y : adj[x]) {

      if (visited[y] == 0) {

        deg[y]--;

        if (deg[y] == 0) {

          visited[y] = 1;

          q.push(y);

        }

      }

    }

  }

}



int main() {

  ios_base::sync_with_stdio(false);

  cin.tie(0);

  

  int e;

  cin >> v >> e;

  adj.resize(v);

  visited.resize(v);

  deg.resize(v);

  for (int i = 0; i < e; i++) {

    int a, b;

    cin >> a >> b;

    adj[a].push_back(b);

    deg[b]++;

  }

  topologicalOrder();

  for (auto i : ans) {

    cout << i << endl;

  }

  return 0;

}
