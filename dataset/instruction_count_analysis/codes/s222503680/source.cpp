#include<stdio.h>

#include<algorithm>

using namespace std;

int n, a, b, c;

int dp[3][2];//一维：3个项目的选择   二维：切换今天 和 昨天  今天i=0  昨天  1-i  i = i-1



int main(){

//	freopen("inf.txt","r",stdin);

	scanf("%d", &n);

	int i = 0;

	while(n--){

		scanf("%d%d%d", &a, &b, &c);

		dp[0][i] = max(dp[1][1-i]+a,dp[2][1-i]+a);

		dp[1][i] = max(dp[0][1-i]+b,dp[2][1-i]+b);

		dp[2][i] = max(dp[0][1-i]+c,dp[1][1-i]+c);

		i = 1-i;

	}

	printf("%d\n", max(dp[0][1-i],max(dp[1][1-i],dp[2][1-i])));

	return 0;

}