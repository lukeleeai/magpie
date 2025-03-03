#include <cstdio>

#include <algorithm>

#include <cstring>

const int maxn = 3e5 + 5;

using namespace std;



int N;

int a[maxn][4];

int dp[maxn][4];

int main()

{

	scanf("%d", &N);

	for(int i = 1;i <= N;i++)

	{

		for(int j = 1;j <= 3;j++)		

		{

			scanf("%d", &a[i][j]);

		}

	}

	memset(dp, 0, sizeof dp);

	for(int i = 1;i <= 3;i++)

		dp[1][i] = a[1][i];

	for(int i = 2;i <= N;i++)

	{

		dp[i][1] = max(dp[i - 1][2] + a[i][1], dp[i - 1][3] + a[i][1]);

		dp[i][2] = max(dp[i - 1][1] + a[i][2], dp[i - 1][3] + a[i][2]);

		dp[i][3] = max(dp[i - 1][1] + a[i][3], dp[i - 1][2] + a[i][3]);

	}

	int ans = 0;

	for(int i = 1;i <= 3;i++)

		ans = max(dp[N][i], ans);

	printf("%d\n", ans);

	return 0;	

}