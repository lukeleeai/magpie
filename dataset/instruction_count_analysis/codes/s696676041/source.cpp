#include<iostream>

#include<algorithm>



using namespace std;



#define INF 100000000



int s, e, r, m;



int dijk(int d[][101]) {

  int mi, i, j;

  int c[m + 1] = {};

    

  for(i = 0; i <= m; i++) {

    c[i] = INF;

  }

    

  int f[m + 1] = {};

  mi = s;

  c[s] = 0;



  for(i = 0; i < m; i++){

    f[mi] = 1;



    for(j = 0; j <= m; j++) {

      if(f[j] == 1) continue;

      if(c[j] > d[mi][j] + c[mi]) {

	c[j] = d[mi][j] + c[mi];

      }

    }



    int MIN = INF * 2;



    for(j = 0; j <= m; j++) {

      if(f[j] == 1) continue;

      if(MIN > c[j]) {

	MIN = c[j];

	mi = j;

      }

    }

  }

  if(c[e] == INF) return -1;

  return c[e];

}



  

int main() {

  int i, j, r, k, a,b, cost;

  while(cin >> m >> k, k != 0 || m != 0) {

    int d[101][101] = {};

    

    for(i = 0; i <= m; i++) {

      for(j = 0;j <= m; j++) {

	d[i][j]  = INF;

      }

    }

    

    for(i = 0; i < k; i++) {

      cin >> r;

      if(r == 1) {

	cin >> a >> b >> cost;

	d[a][b] = d[b][a] = min(cost, d[a][b]);

     }

      else {

	cin >> s >> e;

	cout << dijk(d) << endl;

      }

    }

    

  }

  return 0;

}