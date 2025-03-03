#include <cstdio>

#include <algorithm>

#include <vector>

using namespace std;

 

int n,dp[100005][5],a[100005][5],k; 

int main(){

	scanf("%d",&n);

	for (int i=1;i<=n;i++){

		scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);

	}

	dp[1][1]=a[1][1]; dp[1][2]=a[1][2]; dp[1][3]=a[1][3];

	for (int i=2;i<=n;i++){

		dp[i][1]=max(dp[i-1][2]+a[i][1],dp[i-1][3]+a[i][1]);

		dp[i][2]=max(dp[i-1][1]+a[i][2],dp[i-1][3]+a[i][2]);

		dp[i][3]=max(dp[i-1][1]+a[i][3],dp[i-1][2]+a[i][3]);

	}

	printf("%d\n",max(max(dp[n][1],dp[n][2]),dp[n][3]));

	return 0;

} 