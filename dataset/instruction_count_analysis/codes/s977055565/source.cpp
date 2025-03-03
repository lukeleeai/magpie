#include <cstdio>

#include <queue>

#include <cstring>

#include <iostream>

#include <algorithm>

using namespace std;

int vis[110][110][110];

struct node

{

	int a,b,c,s;

	node (int aa,int bb,int cc,int ss):a(aa),b(bb),c(cc),s(ss){}

};

int bfs(int a,int b,int c)

{

	queue<node>q;

	q.push(node(a,b,c,0));

	while(!q.empty())

	{

		node t=q.front();

		q.pop();

		if(t.a==t.b&&t.b==t.c)

			return t.s;

		int x,y,z;

		x=t.a+2;y=t.b;z=t.c;

		if(x<110&&y<110&&z<110&&vis[x][y][z]==0)

		{

			q.push(node(x,y,z,t.s+1));

			vis[x][y][z]=1;

		}

		x=t.a;y=t.b+2;z=t.c;	

		if(x<110&&y<110&&z<110&&vis[x][y][z]==0)

		{

			q.push(node(x,y,z,t.s+1));

			vis[x][y][z]=1;

		}

		x=t.a;y=t.b;z=t.c+2;

		if(x<110&&y<110&&z<110&&vis[x][y][z]==0)

		{

			q.push(node(x,y,z,t.s+1));

			vis[x][y][z]=1;

		}if(x<110&&y<110&&z<110&&vis[x][y][z]==0)

		{

			q.push(node(x,y,z,t.s+1));

			vis[x][y][z]=1;

		}	

		x=t.a+1;y=t.b+1;z=t.c;

		if(x<110&&y<110&&z<110&&vis[x][y][z]==0)

		{

			q.push(node(x,y,z,t.s+1));

			vis[x][y][z]=1;

		}

		x=t.a;y=t.b+1;z=t.c+1;

		if(x<110&&y<110&&z<110&&vis[x][y][z]==0)

		{

			q.push(node(x,y,z,t.s+1));

			vis[x][y][z]=1;

		}

		x=t.a+1;y=t.b;z=t.c+1;

		if(x<110&&y<110&&z<110&&vis[x][y][z]==0)

		{

			q.push(node(x,y,z,t.s+1));

			vis[x][y][z]=1;

		}		

	}

	return -1;

}

int main()

{

	int x,y,z,ans;

	cin>>x>>y>>z;

	memset(vis,0,sizeof(vis));

	vis[x][y][z]=1;

	ans=bfs(x,y,z);

	cout<<ans<<endl;

	return 0;

}