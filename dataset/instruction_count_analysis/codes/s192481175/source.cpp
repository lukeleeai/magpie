#include<iostream>

using namespace std;



int main(){

  int n,m;

  int d[300][4];

  int dp[3][301];

  string tmp;



  while(cin >> n >> m){

    for(int i=0;i<n;i++){

      cin.ignore();

      getline(cin,tmp);

      for(int j=0;j<4;j++)cin >> d[i][j];

    }



    



    for(int i=0;i<3;i++){

      for(int j=0;j<=m;j++)dp[i][j] = 0;

    }



    for(int i=0;i<3;i++){

      for(int j=1;j<=m;j++){

	for(int k=0;k<=j;k++){

	  dp[i][j] = max(dp[i][j],dp[i][k]+dp[i][j-k]);

	  for(int l=0;l<n;l++){

	    if(d[l][0] == j-k)dp[i][j] = max(dp[i][j],dp[i][k]+d[l][i+1]);

	  }

	}

      }

    }



    int ans = 0;

    for(int i=0;i<3;i++)ans = max(ans,dp[i][m]);

    cout << ans << endl;

  }

}