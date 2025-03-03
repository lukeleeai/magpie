#include <stdio.h>

int dp[200005],a[100005];

int main(void){

	int n,k,i;

	scanf("%d%d",&n,&k);

	for(i=1;i<=n;i++)

	scanf("%d",&a[i]);

	int j;

	for(i=0;i<=k;i++)

	{

	    if(dp[i]==0)

	    {

	        for(j=1;j<=n;j++)

	        dp[i+a[j]] = 1;

	    }

	}

	if(dp[k])printf("First\n");

	else printf("Second\n");

	return 0;

}