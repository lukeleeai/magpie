/*

 * Author : Andrew J

*/

#include "stdc++.h"

using namespace std;

#define rall(x) x.rbegin() , x.rend()

#define all(x) x.begin() , x.end()

#define fi first

#define se second

#define pb push_back

using ll = long long;

using ii = pair <int , int>;

using di = pair <double , int>;

using minHeap = priority_queue <di , vector <di> , greater <di>>;

void in(int &x);

const double INF = 1e18;

const int N = 1050;

#define singleCase

// #define multipleCase

int xs, ys, xf, yf, n;

double dist[N][N], x[N], y[N], r[N], d[N];

bool vis[N];



double distBetweenPoints(double x1 , double y1 , double x2 , double y2) {

  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

}



double getDist(int u , int v) {

  double shortestPath = distBetweenPoints(x[u] , y[u] , x[v] , y[v]);

  return max(0.0 , shortestPath - r[u] - r[v]);

}



void work() {

  scanf("%d%d%d%d%d" , &xs , &ys , &xf , &yf , &n);

  x[0] = xs, y[0] = ys, r[0] = 0;

  x[n + 1] = xf, y[n + 1] = yf, r[n + 1] = 0;

  for (int i = 1 ; i <= n ; i++) {

    scanf("%lf%lf%lf" , &x[i] , &y[i] , &r[i]);

  }

  fill (d , d + N , INF);

  for (int i = 0 ; i <= n + 1 ; i++) {

    for (int j = 1 + i ; j <= n + 1 ; j++) {

      dist[i][j] = getDist(i , j);

      dist[j][i] = dist[i][j];

    }

  }

  minHeap pq;

  pq.push({0 , 0});

  double sol = -1;

  while (pq.size()) {

    di cur = pq.top(); pq.pop();

    double cd = cur.fi;

    int u = cur.se;

    if (vis[u]) continue;

    vis[u] = 1, d[u] = cd;

    if (u == n + 1) {

      sol = cd;

      break;

    }

    for (int v = 0 ; v <= n + 1 ; v++) {

      if (d[v] > cd + dist[u][v]) {

        pq.push({cd + dist[u][v] , v});

      }

    }

  }

  printf("%.10lf\n" , sol);

  return;

}



int main() {

  #ifdef multipleCase

    int nQ; in(nQ);

    while (nQ--)

      work();

  #endif

  #ifdef singleCase

    work();

  #endif

  return 0;

}



void in(int &x) {

	bool neg = false;

	register int c;

	x = 0;

	c = getchar();

	if(c == '-') {

		neg = true;

		c = getchar();

	}

	for (; c > 47 && c < 58; c = getchar())

	  x = (x << 1) + (x << 3) + c - 48;

	if (neg) x *= -1;

}
