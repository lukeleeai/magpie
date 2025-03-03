#include<iostream>

#include<string.h>

using namespace std;



const int INF = 100000000;

int adj[100][100];

int radj[100][100];



int main() {

  int n,m,s,g1,g2,b1,b2,c;



  while(cin>>n>>m>>s>>g1>>g2, n|m|s|g1|g2) {

    memset(adj, INF, sizeof(adj));

    memset(radj, INF, sizeof(radj));

    s--,g1--,g2--;



    for(int i=0; i<100; ++i)

      for(int j=0; j<100; ++j) {

	adj[i][j] = INF;

	radj[i][j] = INF;

      }



    for(int i=0; i<100; ++i)

      adj[i][i] = 0;



    for(int i=0; i<m; ++i) {

      cin>>b1>>b2>>c;

      b1--,b2--;

      adj[b1][b2] = c;

      radj[b2][b1] = c;

    }





    for(int k=0; k<n; ++k) {

      for(int i=0; i<n; ++i) {

	for(int j=0; j<n; ++j) {

	  adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

	  radj[i][j] = min(radj[i][j], radj[i][k]+radj[k][j]);

	}

      }

    }



    int minc = INF;

    for(int i=0; i<n; ++i) {

      minc = min(minc, (adj[s][i]+adj[i][g1]+adj[i][g2]));

    }



    cout<<minc<<endl;

  }

}