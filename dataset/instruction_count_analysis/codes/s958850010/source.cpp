#include<cstdio>

#include<cstring>

#include<algorithm>

#define MAXN 5000

#define MO 1000000007

using namespace std;

char str[MAXN+5];

int N;

int dp[MAXN+5][MAXN+5];//dp[i][j]:走到第j位花了i步

int main()

{

	scanf("%d",&N);

	scanf("%s",str+1);

	int len=strlen(str+1);

//	int len=N/2;

	dp[0][0]=1;

	for(int tmn=1;tmn<=N;tmn++)

	{

		for(int pos=0;pos<=N;pos++)

		{

			if(pos!=N)

				dp[tmn][pos]=(1LL*dp[tmn][pos]+2LL*dp[tmn-1][pos+1]%MO)%MO;

			if(pos!=0)

				dp[tmn][pos]=(1LL*dp[tmn][pos]+1LL*dp[tmn-1][pos-1])%MO;

			if(pos==0)

				dp[tmn][pos]=(1LL*dp[tmn][pos]+1LL*dp[tmn-1][pos])%MO;

		}

	}

	printf("%d\n",dp[N][len]);

	return 0;

}