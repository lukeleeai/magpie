#include <algorithm>

#include <iostream>

#include <math.h>

#include <stdio.h>

#include <string>

#include <sstream>

#include <vector>

#include <set>

#include <stack>

#include <map>

#include <cmath>

#include <queue>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

typedef unsigned long long ll;

#define MAX_N 100







int main()

{

	int n,maxWeight;

	cin>>n>>maxWeight;

	int *value = new int[n];

	int *weight = new int[n];

	vector<vector<int>> dp(n+1,vector<int>(maxWeight+1));

	rep(i,n+1){

		rep(j,maxWeight+1) dp[i][j] = 0;

	}

	rep(i,n){

		cin>>value[i]>>weight[i];

	}

	for(int i = 1; i <= n; i++){

		for(int j = 0; j <= maxWeight; j++){

			if( j >= weight[i-1]){

				dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i-1]] + value[i-1]);

			}else{

				dp[i][j] = dp[i-1][j];

			}

		}

	}

	int ans = 0;

	rep(j,maxWeight+1){

		ans = max(ans,dp[n][j]);

	}

	cout<<ans<<endl;

	return 0;

}




