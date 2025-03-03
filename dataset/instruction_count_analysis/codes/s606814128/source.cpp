#include<cstdio>

#include<string.h>

#include<algorithm>

#include<vector>

#include<functional>

#include<queue>

using namespace std;



const double INF = 1e9;

const int IINF = 100000000;

typedef double Weight;



struct Node{

  int use,to;

  Weight cost;

  Node() {;}

  Node(int use,int to,Weight cost) : to(to), use(use), cost(cost) {;}

  bool operator<(const Node &rhs) const { return cost > rhs.cost; }

};



typedef vector<Node> Graph;



int n,m,p,a,b,ts,t,x,y,z;

int road[30][30];

bool visited[1<<8][30];

double dist[1<<8][30];

int tickets[8];



int main() {



  while(scanf("%d %d %d %d %d", &n, &m, &p, &a, &b)) {

    if(n==0 && m==0 && p==0 && a==0 && b==0) break;

    a--,b--;

    memset(visited, false, sizeof(visited));



    for(int i=0; i<30; ++i)

      for(int j=0; j<30; ++j)

	road[i][j] = IINF;



    for(int i=0; i<(1<<8); ++i)

      for(int j=0; j<30; ++j)

	dist[i][j] = INF;



    for(int i=0; i<n; ++i)

      scanf("%d", &tickets[i]);



    for(int i=0; i<p; ++i) {

      scanf("%d %d %d", &x, &y, &z);

      x--,y--;

      road[x][y] = road[y][x] = z;

    }



    priority_queue<Node> Q;

    Q.push(Node(0, a, 0));

    while(!Q.empty()) {

      Node now = Q.top(); Q.pop();

      //printf("now : %d\n", now.to);

      if(visited[now.use][now.to])

	continue;

      visited[now.use][now.to] = true;

      if(now.to == b) {

	printf("%.4f\n", now.cost);

	goto NEXT;

      }

      int from = now.to;

      for(int to=0; to<m; ++to) {

	if(road[from][to] == IINF)

	  continue;

	for(int i=0; i<n; ++i) {

	  if((1<<i) & now.use) continue;

	  int nuse = now.use | (1<<i);

	  if(visited[nuse][to]) continue;

	  double newcost = now.cost + road[from][to]/(double)tickets[i];

	  if( newcost >= dist[nuse][to]) continue;

	  dist[nuse][to] = newcost;

	  //printf("     next : %d\n", to);

	  Q.push(Node(nuse, to, newcost));

	}

      }

    }

    printf("Impossible\n");

  NEXT:

    ;

  }

}