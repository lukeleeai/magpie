#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;



int n,m,dp[5][10010];



int dfs(int now,int sy)

{

	if(now>3) return !sy;

	if(dp[now][sy]!=-1) return dp[now][sy];

	int i,res=0;

	for(i=0;i<=min(n,sy);i++)

	{

		res+=dfs(now+1,sy-i);

	}

	return dp[now][sy]=res;

}



int main()

{

	int a,b;

	memset(dp,-1,sizeof(dp));

	cin>>n>>m;

	cout<<dfs(1,m);

}