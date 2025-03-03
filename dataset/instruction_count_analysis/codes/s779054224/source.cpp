#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

using namespace std;

const int mxn =  5e5+5;

const int inf = 0x3f3f3f3f;

typedef long long ll;

const ll mod =998244353; 

int n,m;

ll dp[mxn],v[mxn];

//dp[i] : 装满i容量的物品 的方案数 



int main()

{



	ll ans = 0;

	memset(dp,0,sizeof(dp));

	scanf("%d%d",&n,&m);

	for(int i = 1;i<=n;i++)scanf("%lld",&v[i]);

	

	for(int i  = 1;i<=n;i++)

	{

		dp[0] ++;

		for(int j = m;j>=v[i];j--)

		{

			dp[j] = ( dp[j]+dp[j-v[i]])%mod;

		}

		ans = (ans + dp[m])%mod;

	}

	printf("%lld",ans);

	

	

	return 0;

}