#include <iostream>

#include <cstdio>

#include <vector>

#include <algorithm>

#include <complex>

#include <queue>

#include <map>

#include <set>

#include <cstring>

#include <cstdlib>

#include <string>

#include <cmath>

using namespace std;



#define REP(i,n) for(int i=0;i<(int)n;++i)

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

#define ALL(c) (c).begin(), (c).end()

const int INF = 1<<29;



typedef double Weight;

struct Edge {

  int src, dst;

  Weight weight;

  int c;                        // c ÍOtÅÍ§À¬xAqueue ÅÍ¬x

  Edge(int src, int dst, Weight weight, int c) :

    src(src), dst(dst), weight(weight), c(c){ }

};



bool operator < (const Edge &e, const Edge &f) {

  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!

    e.src != f.src ? e.src < f.src :

    e.dst != f.dst ? e.dst < f.dst : e.c < f.c;

}



typedef vector<Edge> Edges;

typedef vector<Edges> Graph;

typedef pair<int,int> pii;



double dist[30][30][32];           // dist[i][j][k] = Xs[h k ÌóÔÅ j ©ç i ÉÂ­ÅZ£



double dijkstra(const Graph &g, int s, int t) {

  int n = g.size();

  REP(i,n) REP(j,n) REP(k,32) dist[i][j][k] = INF;

  priority_queue<Edge> Q;

  Q.push(Edge(s,s,0,0));

  int cnt = 0;

  while(!Q.empty()) {

    Edge e = Q.top(); Q.pop();

    if (e.dst == t && e.c == 1) break;

    REP(k,3) {

      int v = e.c - 1 + k;

      if (v<=0) continue;

      if (dist[e.dst][e.src][v] < e.weight) continue;

      FOR(f, g[e.dst]) {

        if (v > f->c) continue;

        if (f->dst == e.src) continue;

        double hoge = e.weight + f->weight / v;

        if (dist[f->dst][f->src][v] > hoge) {

          dist[f->dst][f->src][v] = hoge;

          Q.push(Edge(f->src, f->dst, hoge, v));

        }

      }

    }

    if (cnt++ > 200000) break;

  }



  double res = INF;

  REP(i,n)

    res = min(res, dist[t][i][1]);

  return res;

}



int main() {

  int n,m;

  while(cin >> n>>m,n||m) {

    int s,t;

    cin >> s >> t;

    s--;t--;

    Graph g(n);

    REP(i,m) {

      int x,y,d,c;

      cin >> x>>y>>d>>c;

      x--;y--;

      g[x].push_back(Edge(x,y,d,c));

      g[y].push_back(Edge(y,x,d,c));

    }

    double res = dijkstra(g,s,t);

    if (res == INF)

      cout << "unreachable" << endl;

    else

      printf("%.5f\n",res);

  }

}