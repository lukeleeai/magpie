#include "stdc++.h"

using namespace std;



int n;

int a[100010];

int dp[100010][3];



int main()

{

  cin >> n;

  for (int i = 0; i < n; i++){

    cin >> a[i + 1];

  }

  a[0] = a[1] ^ 1;

  a[n + 1] = a[n] ^ 1;



  for (int i = 1; i <= n; i++){

    if (a[i - 1] ^ a[i]){

      dp[i][0] = dp[i - 1][0] + 1;

      dp[i][1] = dp[i - 1][1] + 1;

      dp[i][2] = dp[i - 1][2] + 1;

    }

    else {

      dp[i][0] = 1;

      dp[i][1] = dp[i - 1][0] + 1;

      dp[i][2] = dp[i - 1][1] + 1;

    }

  }



  cout << *max_element(dp[0], dp[100010]) << endl;

}