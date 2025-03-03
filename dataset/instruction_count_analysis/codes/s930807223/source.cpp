#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 55

#define MO 1000000007

void Add(int &x,int y)

{

	x=(x+y>=MO)?(x+y-MO):(x+y);

}

int dp[MAXN][MAXN*2][MAXN*2],n,a[MAXN*2],ans;

int main()

{

	scanf("%d",&n);

	for(int i=1;i<=n*2-1;i++)

		scanf("%d",&a[i]);

	sort(a+1,a+n*2);

	dp[n][1][0]=1;

	for(int i=n-1;i>=1;i--)

	{

		int al=(a[i]!=a[i+1]),ar=(a[n*2-i]!=a[n*2-i-1]);

		for(int l=0;l<=2*n-1;l++)

			for(int r=0;r+l<=2*n-1;r++)

				if(dp[i+1][l][r])

				{

					int t=dp[i+1][l][r];

					for(int dl=0;dl<l+al;dl++)

						Add(dp[i][l+al-dl][r+ar+(dl>0)],t);

					for(int dr=1;dr<=r+ar;dr++)

						Add(dp[i][l+al+1][r+ar-dr],t);

				}

	}

	for(int l=0;l<=2*n-1;l++)

		for(int r=0;r+l<=2*n-1;r++)

			Add(ans,dp[1][l][r]);

	printf("%d\n",ans);

}