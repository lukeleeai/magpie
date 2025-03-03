#include<cstdio>

#define p 1000000007

int i,j,_[8][2]={{},{2,3},{4,1},{5,7},{2,2},{6,3},{5,5},{7,7}},dp[2][8];

char s[300005];

int main()

{

	scanf("%s",s+1);

	int*f=dp[0],*g=dp[1],*q;

	for(f[1]=i=1;s[i];i++,q=f,f=g,g=q)for(j=1;j<8;f[j++]=0)if(f[j])s[i]!='1'&&((g[_[j][0]]+=f[j])%=p),s[i]!='0'&&((g[_[j][1]]+=f[j])%=p);

	printf("%d",(f[3]+f[7])%p);

}