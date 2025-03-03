#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<queue>

using namespace std;

const int maxn=100000+10;

struct node

{

	int to,next,w;

}edge[maxn];

int k=1,head[maxn],ind[maxn],n,m,dp[maxn];

void add(int u,int v,int w)

{

	edge[++k].to=v;edge[k].next=head[u];head[u]=k;edge[k].w=w;

}

void Topsort()

{

	queue<int>q;

	for(int i=1;i<=n;i++)

		if(!ind[i])

			q.push(i);

	while(!q.empty())

	{

		int x=q.front();q.pop();

		for(int i=head[x];i;i=edge[i].next)

		{

			dp[edge[i].to]=max(dp[edge[i].to],dp[x]+edge[i].w);

			ind[edge[i].to]--;

			if(!ind[edge[i].to])

				q.push(edge[i].to);

		}

	}

}

int  main()

{

	cin>>n>>m;

	for(int i=1;i<=m;i++)

	{

		int u,v;

		cin>>u>>v;

		add(u,v,1);

		ind[v]++;

	}

	Topsort();

	int ans=0;

	for(int i=1;i<=n;i++)

		ans=max(ans,dp[i]);

	cout<<ans<<endl;

	return 0;

}

//Phoenix-ZH