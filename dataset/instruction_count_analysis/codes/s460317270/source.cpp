/*********************

*  Author: xuziyuan  * 

*********************/



#include "stdc++.h"



#define rt0 return 0

#define rep(i,n) for(int i=0;i<n;i++)

#define repn(i,n) for(int i=1;i<=n;i++)

#define replet(c) for(char c='a';c<='z';c++) 

#define LL long long

#define pii pair <int,int>

#define pb push_back

#define fi first

#define se second

#define mpr make_pair

#define sqr(a) ((a)*(a))



using namespace std;



const LL MOD=1e9+7;



LL n,t,dp[110][10010],all=1,ans=0;



int main()

{

	cin>>n>>t;

	rep(i,n-1) all=all*(t+1)%MOD;

	all=all*(t+1)*t/2*n%MOD;

	if(n==t)

	{

		dp[n-1][1]=1;

		dp[n-1][0]=t;

	}

	else dp[n-1][0]=t+1;

	for(int i=n-1;i>0;i--)

	{

		rep(j,10005)

		{

			if(dp[i][j]==0) continue;

			rep(k,t+1)

			{

				if(k<=i) dp[i-1][j+(j+k)/i]=(dp[i-1][j+(j+k)/i]+dp[i][j])%MOD;

				else dp[i-1][j]=(dp[i-1][j]+dp[i][j])%MOD;

			}

		}

	}

	repn(i,10003) ans=(ans+i*dp[0][i])%MOD;

	cout<<(all-ans+MOD)%MOD<<endl;

	rt0;

}