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



#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)

#define REP(i,n) FOR(i,0,n)

#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)



template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }



typedef long long ll;

const int INF = 100000000;

const double EPS = 1e-8;

const int MOD = 1000000007;

struct edge{

  int to, cap, rev;

  edge(){}

  edge(int to, int cap, int rev):

    to(to), cap(cap), rev(rev) {}

};

typedef vector<edge> edges;

int gcd(int m,int n){

  return (m%n)?gcd(n, m%n):n;

}

void add_edge(vector<edges>& g, int from, int to, int cap){

  g[from].push_back(edge(to, cap, g[to].size()));

  g[to].push_back(edge(from, 0, g[from].size()-1));

}

bool used[1002];

int dfs(vector<edges>& g, int u, int end, int f){

  if(u == end) return f;

  used[u] = true;

  REP(i,g[u].size()){

    edge& e = g[u][i];

    if(used[e.to] || e.cap <= 0) continue;

    int t = dfs(g, e.to, end, min(f,e.cap));

    if(t > 0){

      e.cap -= t;

      g[e.to][e.rev].cap += t;

      return t;

    }

  }

  return 0;

}

int maxflow(vector<edges>& g, int s, int e){

  int res = 0;

  while(true){

    memset(used, 0, sizeof(used));

    int f = dfs(g, s, e, 1);

    if(f == 0) return res;

    else res += f;

  }

  return -1;

}



int main(){

  int m,n;

  while(cin>>m>>n,m||n){

    vector<int> v1(m);

    vector<int> v2(n);

    REP(i,m)cin>>v1[i];

    REP(i,n)cin>>v2[i];

    const int start = m + n;

    const int end = m + n + 1;;

    vector<edges> graph(end + 1);

    REP(i,m)add_edge(graph, start, i, 1);

    REP(i,n)add_edge(graph, m + i, end, 1);

    REP(i,m)REP(j,n)if(gcd(v1[i],v2[j])!=1){

      add_edge(graph, i, m + j, 1);

    }

    cout<<maxflow(graph,start,end)<<endl;

  }

  return 0;

}