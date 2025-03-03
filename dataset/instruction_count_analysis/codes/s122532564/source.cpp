#include<iostream>

#include<cstdio>

#include<string>

#include<cstring>

#include<algorithm>

#include<queue>

#include<stack>

#include<map>

#include<vector>

#include<set>

#include<list>

#define ll long long

using namespace std;

ll h[200050],dp[200050];

int main()

{

	ll n;

	cin>>n;

	for(int i=1;i<=n;i++)

		cin>>h[i];

	memset(dp,0,sizeof(dp));

	dp[2]=abs(h[2]-h[1]);

	for(int i=3;i<=n;i++)

		dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));

	cout<<dp[n]<<endl;

	return 0;

}