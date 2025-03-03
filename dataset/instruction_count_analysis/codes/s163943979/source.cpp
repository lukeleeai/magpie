#include"stdc++.h"

#define MOD (long long)(1e9+7)

using namespace std;

long long n,k,dp[100005],c[105],sum[100005];

int main()

{

	cin >> n >> k;

	for(int i=1; i<=n; i++) cin >> c[i];

	dp[0]=sum[0]=1;

	for(int i=1; i<=n; i++)

	{

		for(int j=1; j<=k; j++) sum[j]=(dp[j]+sum[j-1]);

		for(int j=1; j<=k; j++) dp[j]=(sum[j]-(j<=c[i]?0:sum[j-c[i]-1]))%MOD;

	}

	//for(int j=0; j<=k; j++) cout << sum[j] << ' ';cout<<'\n';

	cout << dp[k];

	return 0;

}