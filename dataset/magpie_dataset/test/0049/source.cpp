#include"stdc++.h"

#define int long long

using namespace std;

const int N=16;

int dp[1<<N],a[N][N],n;

int calc(int s)

{

	int sum=0;

	for(int i=0;i<n;i++)

	{

		if(!(s&(1<<i)))

			continue;

		for(int j=i+1;j<n;j++)

			if(s&(1<<j))

				sum+=a[i][j];

	}

	return sum;

}

int dfs(int s)

{

	if(dp[s]!=-1)

		return dp[s];

	if(s==0)

		return dp[s]=0;

	dp[s]=0;

	int p;

	for(int i=0;i<n;i++)

	{

		if(s&(1<<i))

		{

			p=i;

			break;

		}

	}

	for(int t=s;t;t=s&(t-1))

	{

		int nt=t|(1<<p);

		dp[s]=max(dp[s],calc(nt)+dfs(s^nt));

	}

	return dp[s];

}

main()

{

	ios::sync_with_stdio(false);

	cin>>n;

	for(int i=0;i<n;i++)

		for(int j=0;j<n;j++)

			cin>>a[i][j];

	memset(dp,-1,sizeof(dp));

	cout<<dfs((1<<n)-1)<<endl;

	return 0;

}