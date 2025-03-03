#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

const int maxd = 1e5+10;

const int mod = 1e9+7;

char s[maxd];

int dp[maxd][20];

int main()

{

	// freopen("a.in","r",stdin);

	// freopen("k.out","w",stdout);

	scanf("%s",s+1);

	dp[0][0] = 1;

	for(int i=1;s[i];i++)

	{

		if(s[i] != '?')

		{

			int k = s[i] - '0';

			for(int j=0;j<13;j++)

				dp[i][(j*10+k)%13] = (1ll * dp[i][(j*10+k)%13] + dp[i-1][j])%mod;

		}

		else 

		{

			for(int k=0;k<10;k++)

				for(int j=0;j<13;j++)

					dp[i][(j*10+k)%13] = (1ll * dp[i][(k+j*10)%13] + dp[i-1][j])%mod;

		}

	}

	printf("%d",dp[strlen(s+1)][5]);

	return 0;

}