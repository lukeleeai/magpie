#include "stdc++.h"

#define rep(i,n) for(int i=0; i < (n); i++)

#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)

using namespace std;

using ll = long long;

int INF = 1001001001;



vector<int> to[200005];



int main() {

  int n, m;

  cin >> n >> m;

  rep(i, m) {

    int a, b;

    cin >> a >> b;

    a--;b--;

    to[a].push_back(b);

    to[b].push_back(a);

  }



  vector<int> dist(n, INF);

  vector<int> prev(n);

  queue<int> q;

  q.push(0);



  while(!q.empty()) {

    int v = q.front(); q.pop();

    for(int u : to[v]) {

      if(dist[u] != INF) {

        continue;

      }

      prev[u] = v;

      dist[u] = dist[v] + 1;

      q.push(u);

    }

  }

  cout << "Yes" << endl;

  rep(i, n) {

    if(i==0) continue;

    int ans = prev[i];

    ans++;

    cout << ans << endl;

  }

  return 0;

}