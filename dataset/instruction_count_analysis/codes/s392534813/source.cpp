#include<set>

#include<map>

#include<stack>

#include<queue>

#include<deque>

#include<cmath>

#include<cstdio>

#include<cctype>

#include<string>

#include<vector>

#include<cstdlib>

#include<cstring>

#include<sstream>

#include<iostream>

#include<algorithm>

#define MAXN 1000

#define hlq 1000000007



using namespace std;

int c,d,C[MAXN+8][MAXN+8],dp[MAXN+8][MAXN+8],fac[MAXN+8];

int DP(int l,int r,int res)

{

	if(res==0)

		return 1;

	if(r<l)

		return 0;

	if(~dp[r][res])

		return dp[r][res];

	dp[r][res]=DP(l,r-1,res);

	int i,k=min(d,res/r),f=1,t=res,tmp=0;

	if(c>k)

		return dp[r][res];

	for(i=1;i<c&&t>=r;i++)

	{

		f=(1LL*f*C[t][r])%hlq;

		t-=r;

	}

	for(i=c;i<=k&&t>=r;i++)

	{

		f=(1LL*f*C[t][r])%hlq;

		t-=r;

		tmp=1LL*DP(l,r-1,t)*f%hlq;

		tmp=1LL*tmp*fac[i]%hlq;

		dp[r][res]=(tmp+dp[r][res])%hlq;

	}

	return dp[r][res];

}

int pow_mod(long long a,int x)

{

	long long ans=1;

	while(x)

	{

		if(x&1)

			ans=ans*a%hlq;

		a=a*a%hlq;

		x>>=1;

	}

	return (int)ans;

}

int main()

{

	int n,a,b,i,j;

	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);

	memset(dp,-1,sizeof(dp));

	for(i=0;i<=n;i++)

	{

		C[i][0]=1;

		for(j=1;j<=i;j++)

			C[i][j]=(C[i-1][j]+C[i-1][j-1])%hlq;

	}

	fac[0]=1;

	for(i=1;i<=n;i++)

		fac[i]=1LL*fac[i-1]*pow_mod(i,hlq-2)%hlq;

	printf("%d",DP(a,b,n));

	return 0;

}