#include "stdc++.h"



using namespace std;



const int MAX_N = 55;



long long dp[2][MAX_N*MAX_N][MAX_N],ans;



int main()

{

	int n,a,x;

	cin >> n >> a;

	dp[0][0][0]=dp[1][0][0]=1;

	for (int i=1; i<=n; i++)

	{

		cin >> x;

		copy(&dp[1][0][1],&dp[1][n*a][n]+1,

				&dp[0][0][1]);

		for (int k=1; k<=n; k++)	

			for (int s=x; s<=n*a; s++)

				dp[0][s][k]+=dp[1][s-x][k-1];

	

//		copy(&dp[1][0][1],&dp[1][n*a][n]+1,&dp[0][0][1]);

//		transform(&dp[0][x][1],&dp[0][n*a][n]+1,&dp[1][0][0],&dp[0][x][1],plus<>());

		swap(dp[0],dp[1]);

	}

	for (int k=1; k<=n; k++)

		ans+=dp[1][a*k][k];

	cout << ans;

	return 0;

}