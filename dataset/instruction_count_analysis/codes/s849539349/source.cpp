#include <iostream>

#include <sstream>

#include <string>

#include <algorithm>

#include <vector>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cmath>

#include <cassert>



using namespace std;



#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)

#define REP(i,n) FOR(i,0,n)

#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)



template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }

inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }



typedef long long ll;

const int INF = 100000000;

const double EPS = 1e-8;

const int MOD = 1000000007;

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};

int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

typedef vector<int> Node;

typedef vector<Node> Graph;

int V1, V2;

Graph G;

int dist[1002];

int match[1002];

const int NIL = 1001;

bool BFS(){

  queue<int> que;

  REP(v, V1){

    if(match[v] == NIL){

      dist[v] = 0;

      que.push(v);

    }else{

      dist[v] = INF;

    }

  }

  dist[NIL] = INF;

  while(!que.empty()){

    int v = que.front(); que.pop();

    if(dist[v] < dist[NIL]){

      for(int i = 0; i < G[v].size(); i++){

        int u = G[v][i];

        if(dist[match[u]] == INF){

          dist[match[u]] = dist[v] + 1;

          que.push(match[u]);

        }

      }

    }

  }

  return dist[NIL] != INF;

}



bool DFS(int v){

  if(v != NIL){

    for(int i = 0; i < G[v].size(); i++){

      int u = G[v][i];

      if(dist[match[u]] == dist[v] + 1 && DFS(match[u])){

        match[u] = v;

        match[v] = u;

        return true;

      }

    }

    dist[v] = INF;

    return false;

  }

  return true;

}



int Hopcroft_Karp(){

  REP(v, G.size()) match[v] = NIL;

  int matching = 0;

  while(BFS()){

    REP(v, V1){

      if(match[v] == NIL && DFS(v)){

        matching ++;

      }

    }

  }

  return matching;

}

int main(){

  while(scanf("%d %d", &V1, &V2) && (V1 != 0 || V2 != 0)){

    G = Graph(V1 + V2);

    static int blue[500];

    static int red[500];

    REP(i, V1) scanf("%d", blue + i);

    REP(i, V2) scanf("%d", red + i);

    REP(u, V1) REP(v, V2){

      if(__gcd(blue[u], red[v]) != 1) {

        G[u].push_back(V1 + v);

        //G[V1 + v].push_back(u);

      }

    }

    printf("%d\n", Hopcroft_Karp());

  }

  return 0;

}