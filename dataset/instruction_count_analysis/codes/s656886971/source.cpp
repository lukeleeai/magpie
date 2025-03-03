#include <stdio.h>

#include <string.h>

#include <algorithm>

using namespace std;

long long dp[60][2501],a[60];

int main()

{

	long long  n,i,j,k,s,t,k1;

	scanf("%lld%lld",&n,&k1);

	{

	  for(i=1;i<=n;i++)

	  scanf("%lld",&a[i]);

	  memset(dp,0,sizeof(0));

	  dp[0][0]=1;

	  for(k=1;k<=n;k++)

	    {

	    	for(i=k-1;i>=0;i--)

	    	  {

	    	  	for(j=0;j<=50*i;j++)

	    	  	  dp[i+1][j+a[k]]+=dp[i][j];

			  }

		}

	  long long m=0;

	  for(i=1;i<=n;i++)

	    {

	    	int x=i*k1;

	    	if(x<=2500) m+=dp[i][x];

		}

		printf("%lld\n",m);

	}

  return 0;

}