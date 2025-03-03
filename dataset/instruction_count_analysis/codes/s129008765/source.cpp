#include <iostream>

#include <algorithm>

#include <string>

#include <cmath>

#include <vector>

#include <queue>

#include <stack>

#include <utility>

#include <map>

using namespace std;



using ll = long long;



constexpr int limit = 1e5;

int n, m;



class V{

public:

  int tag;

  vector<V*> to;

};



int type[limit+1];

bool visited[limit+1];

int x[limit+1], y[limit+1];

V graph[limit+1];



void bfs(int, int);



int main(){

  cin >> n >> m;

  int p[n+1];

  for(int i=1; i<=n; i++) {

    cin >> p[i];

    graph[i].tag = i;

  }



  for(int i=1; i<=m; i++) {

    cin >> x[i] >> y[i];

    graph[x[i]].to.push_back(&graph[y[i]]);

    graph[y[i]].to.push_back(&graph[x[i]]);

  }



  int cnt=0;

  for(int i=1; i<=n; i++){

    if(!visited[i]){

      bfs(i, cnt);

      cnt++;

    }

  }



  int ans = n;

  for(int i=1; i<=n; i++){

    if(type[i] != type[p[i]]) ans--;

  }



  cout << ans << endl;



  return 0;

}



void bfs(int s, int t){

  type[s] = t;

  visited[s] = true;

  for(int i=0; i<graph[s].to.size(); i++){

    int nx = graph[s].to[i]->tag;

    if(!visited[nx]){

      bfs(nx, t);

    }

  }

}
