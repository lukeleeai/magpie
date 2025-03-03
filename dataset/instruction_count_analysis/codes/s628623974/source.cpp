#include <iostream>

#include <cstring>

#include <algorithm>

#define MAX 1000

using namespace std;



int main(void){



  int n,W;

  int w[MAX+1];

  int v[MAX+1];

  int dp[MAX+1][MAX+1];

  char ten;

  int cnt = 1;



  while( cin >> W , W ){

    cin >> n;

    for( int i = 0 ; i < n ; i++ ){

      cin >> v[i] >> ten >> w[i];

    }



    for( int i = 0 ; i < MAX ; i++ ){

      for( int j = 0 ; j < MAX ; j++ ){

	dp[i][j] = 0;

      }

    }



    for( int i = 0 ; i < n ; i++ ){

      for( int j = 0 ; j <= W ; j++ ){

	if(j < w[i] ) dp[i+1][j] = dp[i][j];

	else dp[i+1][j] = max( dp[i][j] , dp[i][j-w[i]] + v[i] );

      }

    }

    

    cout << "Case " << cnt++ << ":" << endl;

    for( int i = W ; i >= 0 ; i-- ){

      if( dp[n][i] != dp[n][W] ){

	cout << dp[n][W] << endl << i+1 << endl;

	break;

      }

    }

  }  

  return 0;

}