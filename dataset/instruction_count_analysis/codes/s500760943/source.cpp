#include "stdc++.h"

#define rep(i,a,b) for(int i=int(a);i<int(b);++i)

#define SIZE 15

#define INF 1000000005LL

//#define INF 1e18

#define MOD 1000000007



using namespace std;

typedef long long int ll;

typedef pair <int,int> P;



ll d[SIZE][SIZE];

int V;



void warshall_floyd_init(){

  fill(d[0],d[SIZE],INF);

  rep(i,0,SIZE) d[i][i] = 0;

}



//trueなら負の閉路が存在,0_indexed

bool warshall_floyd(){

  rep(k,0,V) rep(i,0,V){

    if(d[i][k]==INF)continue;

    rep(j,0,V){

      if(d[k][j]==INF)continue;

      d[i][j] = min(d[i][j],d[i][k]+d[k][j]);

    }

  }

  rep(i,0,V) if(d[i][i] < 0) return true;

  return false;

}



void add_edge(int a,int b,ll c){

  d[a][b] = c;

}



int h,w;



int main(){

  V=10;

  cin >> h >> w;

  warshall_floyd_init();

  rep(i,0,10){

    rep(j,0,10){

      ll a;

      cin >> a;

      if(i!=j)add_edge(i,j,a);

    }

  }

  warshall_floyd();

  ll ans=0;

  rep(i,0,h) rep(j,0,w){

    int a;

    cin >> a;

    if(a!=1 && a!=-1){

      ans += d[a][1];

    }

  }

  cout << ans << endl;



  return 0;

}
