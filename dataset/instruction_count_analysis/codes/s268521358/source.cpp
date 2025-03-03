#include <queue>

#include <algorithm>

#include <cstring>

#include <cstdio>

using namespace std;



typedef int W;

const int MAXV = 1005;

const int MAXE = 5005;

const int INF = 100000000;

int adj[100][100];



int main() {

  int n,m,s,g1,g2,b1,b2,c;



  while(~scanf("%d%d%d%d%d", &n, &m, &s, &g1, &g2),

        n|m|s|g1|g2) {

    s--,g1--,g2--;



    for(int i = 0; i < 100; ++i) {

      for (int j = 0; j < 100; ++j)

        adj[i][j] = INF;

      adj[i][i] = 0;

    }



    for(int i=0; i<m; ++i) {

      scanf("%d%d%d", &b1, &b2, &c);

      b1--,b2--;

      adj[b1][b2] = c;

    }



    for (int k = 0; k < n; ++k)

      for (int i = 0; i < n; ++i) {

        const int p = adj[i][k];

        for (int j = 0; j < n; ++j)

          adj[i][j] = min(adj[i][j], p + adj[k][j]);

      }



    int minc = INF;

    for(int i=0; i<n; ++i)

      minc = min(minc, adj[s][i]+adj[i][g1]+adj[i][g2]);



    printf("%d\n", minc);

  }

}