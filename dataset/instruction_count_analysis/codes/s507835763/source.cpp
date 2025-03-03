#include<stdio.h>



long long int dp[87];

int main()

{

	int n;

	scanf("%d",&n);

	dp[0] = 2;

	dp[1] = 1;

	for (int i = 2; i <= n; i++)

	{

		dp[i] = dp[i-1] + dp[i-2];

	}

	printf("%lld",dp[n]);

	return 0;

}