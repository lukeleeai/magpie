#include<cstdio>

#include<string.h>

#include<algorithm>

#include<vector>

#include<functional>

#include<queue>

using namespace std;



const double INF = 1e9;

typedef double Weight;



struct Edge{

  int src,dst;

  Weight weight;

  Edge(int src,int dst,Weight weight) : src(src), dst(dst), weight(weight) {;}

};

bool operator<(const Edge &e, const Edge &f) {

  return e.weight != f.weight ? e.weight > f.weight :

    e.src != f.src ? e.src < f.src : e.dst < f.dst;

}



typedef vector<Edge> Edges;

typedef vector<Edges> Graph;



void dijkstra(const Graph &g,const int s, vector<Weight> &dist, vector<int> &prev) {

  const int n = g.size();

  dist.assign(n, INF);

  dist[s] = 0;

  prev.assign(n, -1);

  priority_queue<Edge> Q;



  for(Q.push(Edge(-2, s, 0)); !Q.empty(); ) {

    Edge e = Q.top();

    Q.pop();

    if(prev[e.dst] != -1) continue;

    prev[e.dst] = e.src;

    for(Edges::const_iterator it = g[e.dst].begin(); it != g[e.dst].end(); ++it) {

      if(dist[it->dst] > e.weight + it->weight) {

	dist[it->dst] = e.weight + it->weight;

	Q.push(Edge(it->src, it->dst, e.weight + it->weight));

      }

    }

  }

}



int main() {

  int n,m,p,a,b,ts,t,x,y,z;

  vector<int> tickets(8);

  vector<int> prev((1<<8)*30);

  vector<Weight> dist((1<<8)*30);



  while(scanf("%d %d %d %d %d", &n, &m, &p, &a, &b)) {

    if(n==0 && m==0 && p==0 && a==0 && b==0) break;

    ts = 1<<n;

    Graph g(ts*m);

    a--,b--;



    tickets.clear();

    for(int i=0; i<n; ++i) {

      scanf("%d", &t);

      tickets.push_back(t);

    }



    for(int i=0; i<p; ++i) {

      scanf("%d %d %d", &x, &y, &z);

      x--,y--;

      for(int j=0; j<ts; ++j) {

	for(int k=0; k<n; ++k) {

	  if((j&(1<<k)) == 0) {

	    g[x*ts+j].push_back( Edge(x*ts+j, y*ts+(j|(1<<k)), (double)z/(double)tickets[k]) );

	    g[y*ts+j].push_back( Edge(y*ts+j, x*ts+(j|(1<<k)), (double)z/(double)tickets[k]) );

	  }

	}

      }

    }



    dist.clear();

    prev.clear();

    dijkstra(g, a*ts, dist, prev);



    double minw = INF;

    for(int i=0; i<ts; ++i)

      minw = min(dist[b*ts+i], minw);



    if(minw == INF)

      printf("Impossible\n");

    else

      printf("%f\n", minw);

  }

}