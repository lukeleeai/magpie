#include<iostream>

#include<cstring>

#include<string>

#include<algorithm>

#include<cstdio>

#include<queue>

using namespace std;

#define N 100002

int dis1[N],dis2[N];

int vis[N];

vector<int> g[N];

queue<int> q;

int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

void BFS1() //从哪个节点开始 

{

	int i,now;

	int st; 

	while( !q.empty() )

	{

		st = q.front();

		q.pop();

		for( i=0;i<g[st].size();i++ )

		{

			now = g[st][i];

			if( vis[now] )

				continue;

			vis[now]=1;

			dis1[now] = dis1[st] + 1;

			q.push(now);

		}

	}

}

void BFS2() //从哪个节点开始 

{

	int i,now;

	int st; 

	while( !q.empty() )

	{

		st = q.front();

		q.pop();

		for( i=0;i<g[st].size();i++ )

		{

			now = g[st][i];

			if( vis[now] )

				continue;

			vis[now]=1;

			dis2[now] = dis2[st] + 1;

			q.push(now);

		}

	}

}

int main(){

	int to,from,i,n;

	cin>>n;

	for( i=0;i<n-1;i++ ){

		cin>>to>>from;

		g[to].push_back(from);

		g[from].push_back(to);

	}

	q.push(1);

	BFS1();

	memset(vis,0,sizeof(vis));

	q.push(n);

	BFS2();

	int cntF=0;

	for( i=1;i<=n;i++ )

	{

		if( dis1[i]<=dis2[i] )

			cntF++;

	}

	int cntS = n-cntF;

	if( cntF>cntS )

		cout<<"Fennec\n";

	else

		cout<<"Snuke\n";

	return 0;

}
