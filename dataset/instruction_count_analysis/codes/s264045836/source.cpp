#include<stdio.h>

#include<string.h>

int dp[1000005][2],num[1000005]={0};

char tmp[1000005];

int min(int a,int b){

	return a<b?a:b;

}

int main()

{

	int len,ans;

    for(int i=0;i<1000005;i++)for(int j=0;j<2;j++)dp[i][j]=99;

    scanf("%s",tmp);

    len=strlen(tmp);

    for(int i=1;i<=len;i++)num[i]=tmp[i-1]-'0';

    dp[len][0]=num[len];dp[len][1]=10-num[len];

    for(int i=len-1;i>=0;i--)

    {

    	/*数位*/

    	dp[i][0]=min(dp[i+1][0]+num[i],dp[i+1][1]+num[i]+1),

        dp[i][1]=min(10+dp[i+1][0]-num[i],10+dp[i+1][1]-(num[i]+1));

	}

	ans=min(dp[0][0],dp[0][1]);

    printf("%d\n",ans);

}