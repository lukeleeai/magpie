#include"stdc++.h"

#define MOD (long long)(1e9+7)

using namespace std;

long long n,k,dp[105][100005],c[105];

int main()

{

	cin >> n >> k;

	dp[0][0]=1;

	for(int i=1; i<=n; i++)

	{

		cin >> c[i];

		long long sum=0;

		for(int j=0; j<=c[i]; j++)

		{

			sum+=dp[i-1][j];

			dp[i][j]=(dp[i][j]+sum)%MOD;

		}

		sum-=dp[i-1][0];

		for(int j=c[i]+1; j<=k; j++)

		{

			sum+=dp[i-1][j];

			dp[i][j]=(dp[i][j]+sum)%MOD;

			sum-=dp[i-1][j-c[i]];

		}

	}

	//for(int i=1; i<=n; cout<<'\n',i++)

	//	for(int j=0; j<=k; j++) cout << dp[i][j] << ' ';

	cout << dp[n][k];

	return 0;

}