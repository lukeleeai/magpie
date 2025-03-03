#include<iostream>

#include<algorithm>

#include<string>

using namespace std;

#define rep(i,n) for(int i = 0 ; i < n ; ++i)

#define INF ( 1 << 30 )

int C[301],V[3][301],N,M;

int solve(){

  int rec = 0,dp[301][301];

  rep(a,3){

    fill_n(dp[0],301*301,0);

    rep(i,N) rep(j,M+1){

      if(j < C[i]) dp[i+1][j] = dp[i][j];

      else dp[i+1][j] = max(dp[i][j],dp[i+1][j-C[i]] + V[a][i]);

    }

    rec = max(rec,dp[N][M]);

  }

  return rec;

}

int main(){

  string nop;

  while(cin >> N >> M){

    rep(i,N){

      rep(j,2)getline(cin,nop);

      cin >> C[i] >> V[0][i] >> V[1][i] >> V[2][i];

    }

    cout << solve() << endl;

  }

}