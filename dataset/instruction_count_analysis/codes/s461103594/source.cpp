#include<iostream>

#include<algorithm>

#include<cstdio>

#include<cstring>

#include<string>

#include<vector>

using namespace std;



const int maxn = 100;

vector<int>g[maxn];

int vis[maxn];

int n,m;

int num,tot;

void dfs(int t)

{	

	int j;

	for(j=1;j<=n;j++)

	{

		if(vis[j]!=1)

			break;

	}

	if(j==n+1)

	{

		num++;

		return;

	}

	for(int i=0;i<g[t].size();i++)

	{

		int x = g[t][i];

		if(vis[x]==0)

		{

			vis[x]=1;

			dfs(x);

			vis[x]=0;

		}

	}

	return ;

}

int main()

{

	memset(vis,0,sizeof(vis));

	cin>>n>>m;

	tot=0;

	num=0;

	for(int i=1;i<=n;i++)

	{

		g[i].clear();

	}

	for(int i=1;i<=m;i++)

	{

		int a,b;

		cin>>a>>b;

		g[a].push_back(b);

		g[b].push_back(a);

	}

	vis[1]=1;

	num=0;

	for(int i=0;i<g[1].size();i++)

	{

		int x=g[1][i];

		vis[x]=1;

		dfs(x);

		vis[x]=0;

	}

	cout<<num<<endl;

	

	return 0;

}
