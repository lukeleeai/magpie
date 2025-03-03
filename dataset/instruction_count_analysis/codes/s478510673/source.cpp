// luogu-judger-enable-o2

#include<iostream>

#include<cstring>

#include<cstdio>

#define ll long long

using namespace std;

const int maxn=2005;

const int mod=1e9+7;

int n,k;

ll dp[maxn][maxn],f[maxn];

ll kuai(ll a,int k)

{

	ll ans=1;

	while(k)

	{

		if(k&1)(ans*=a)%=mod;

		(a*=a)%=mod;k>>=1;

	}

	return ans%mod;

} 

int main()

{

//	freopen("forget.in","r",stdin);

//	freopen("forget.out","w",stdout);

	cin>>n>>k;

	dp[0][n+1]=1;ll ans=0;

	for(int i=1;i<=k;i++)

	{

		f[n+1]=dp[i-1][n+1];

		for(int j=n;j>=1;j--)f[j]=(f[j+1]+dp[i-1][j])%mod;

		for(int j=1;j<=n-i+1;j++)

			dp[i][j]=f[j];

	}

	dp[k][1]=(dp[k][1]-dp[k-1][1]+mod)%mod;

	if(n==k)ans=dp[k][1];

	else ans=dp[k][1]*kuai(2,n-k-1)%mod;

	cout<<ans<<endl;

}