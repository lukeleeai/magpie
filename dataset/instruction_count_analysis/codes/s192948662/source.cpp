#include "stdc++.h"

using namespace std;

using i64 = long long;

#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)

#define all(x) x.begin(),x.end()



int N;



i64 dp[1010][1010];

vector<i64> c,w;



i64 ret[1010];



int main(){

  cin >> N;

  c.resize(N + 1);

  w.resize(N + 1);

  rep(i,1,N) cin >> c[i] >> w[i];

  rep(i,1,N) w[i] += w[i - 1];





  rep(i,1,N) dp[i][i] = 1;

  for(int d = 1;d <= N;d++){

    for(int l = 1;l + d <= N;l++){

      int r = l + d;

      if(dp[l][r - 1] == 1 && (w[r - 1] - w[l - 1]) <= c[r]){

        dp[l][r] = 1;

      }

      if(dp[l + 1][r] == 1 && (w[r] - w[l + 1 - 1]) <= c[l]){

        dp[l][r] = 1;

      }

    }

  }



  for(int i = 1;i <= N;i++) ret[i] = 1e9;

  for(int i = 1;i <= N;i++){

    for(int j = i;j <= N;j++){

      if(dp[i][j] == 1){

        ret[j] = min(ret[j] , ret[i - 1] + 1);

      }

    }

  }



  cout << ret[N] << endl;

}


