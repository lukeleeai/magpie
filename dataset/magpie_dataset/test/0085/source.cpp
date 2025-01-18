#include "stdc++.h"

using namespace std;

int n, k;

long long h[100005];

long long dp[100005];



long long solve(int i){

	if(i >= n-1) return 0;

	if(dp[i] != -1) return dp[i];



	dp[i] = 1e17;

	for(int j = 1; j <= k; ++j)

		if(i+j <= n-1)

			dp[i] = min(dp[i], abs(h[i] - h[i+j]) + solve(i+j));

	return dp[i];

}



int main(){

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)

		scanf("%lld", &h[i]);

	memset(dp, -1, sizeof dp);

	cout<<solve(0)<<endl;

	return 0;

}