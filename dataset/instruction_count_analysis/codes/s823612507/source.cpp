#include <iostream>

#include <algorithm>

#include<cmath>

#include<cstring>

#include<cstdio>

#include<cstdlib>

#include<vector>

#include<iomanip>

#define sqr(x) (x)*(x)

#define fz1(i,n) for (i=1;i<=n;i++)

#define fd1(i,n) for (i=n;i>=1;i--)

#define fz0g(i,n) for (i=0;i<=n;i++)

#define fd0g(i,n) for (i=n;i>=0;i--)

#define fz0k(i,n) for (i=0;i<n;i++)

#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)

#define fz(i,x,y) for (i=x;i<=y;i++)

#define fd(i,y,x) for (i=y;i>=x;i--)

#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}

using namespace std;

int n,m,i,j,k,dp[105][105][305],v[105],w[105],ans;

int main()

{

	memset(dp,-120,sizeof(dp));

	cin>>n>>m;

	fz1(i,n)

	{

		cin>>w[i]>>v[i];

	}

	dp[0][0][0]=0;

	for (i=0;i<n;i++)

	{

		for (j=0;j<=i;j++)

		{

			for (k=0;k<=300;k++)

			{

				if (1ll*j*w[1]+k>1ll*m) continue;

				dp[i+1][j+1][k+w[i+1]-w[1]]=max(dp[i+1][j+1][k+w[i+1]-w[1]],dp[i][j][k]+v[i+1]);

				dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);

			}

		}

	}

	for (i=0;i<=n;i++)

	{

		for (j=0;j<=300;j++)

		{

			if (1ll*i*w[1]+j>1ll*m) continue;

			ans=max(ans,dp[n][i][j]);

		}

	}

	cout<<ans<<endl;

	return 0;

}