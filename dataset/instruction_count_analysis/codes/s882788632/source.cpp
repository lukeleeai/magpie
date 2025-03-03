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



    for(int i=0;i<n;i++){

      for(int j=0;j<3;j++){

	dp[j][d[i][0]] = max(dp[j][d[i][0]],d[i][j+1]);

      }

    }



    for(int i=0;i<3;i++){

      for(int j=1;j<=m;j++){

	for(int k=0;k<=j/2;k++){

	  dp[i][j] = max(dp[i][j],dp[i][k]+dp[i][j-k]);

	}

      }

    }



    int ans = 0;

    for(int i=0;i<3;i++)ans = max(ans,dp[i][m]);

    cout << ans << endl;

  }

}