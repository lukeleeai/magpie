#include"stdc++.h"

using namespace std;

int H,W;

const int Maxn = 105;

const int INF = 1000000;

char Map[Maxn][Maxn];

int dp[Maxn][Maxn];

int Path[Maxn][Maxn];// 1 表示向下 -1 表示向右 

int main()

{

	cin>>H>>W;

	for(int i=1;i<Maxn;i++)

		for(int j=1;j<Maxn;j++)

			dp[i][j] = INF;

	for(int i=1;i<=H;i++)

		for(int j=1;j<=W;j++)

			cin>>Map[i][j];

	if(Map[H][W] == '#') dp[H][W] = 1;

	else	dp[H][W] = 0;

	for(int i=H;i>=1;i--)

		for(int j=W;j>=1;j--)

		{

			if(i==H&&j==W)	continue;

			if(Map[i][j]=='.')

				dp[i][j] = min(dp[i+1][j],dp[i][j+1]);

			else

			{

				if(Map[i+1][j]=='.')

					dp[i][j] = min(dp[i][j],dp[i+1][j]+1);

				else

					dp[i][j] = min(dp[i][j],dp[i+1][j]);

				if(Map[i][j+1]=='.')

					dp[i][j] = min(dp[i][j],dp[i][j+1]+1);

				else

					dp[i][j] = min(dp[i][j],dp[i][j+1]); 

			}

		}

	cout<<dp[1][1];

	return 0;

}