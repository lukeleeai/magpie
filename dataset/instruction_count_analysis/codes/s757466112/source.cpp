#include "stdc++.h"

using namespace std;

int n,head[100005],cnt,in[100005],flag,vis[100005];

struct edge{int to,next;

}e[200005];

void add(int x,int y)

{

	e[cnt].to=y;

	e[cnt].next=head[x];

	head[x]=cnt++;

}

void dfs(int u,int pre)

{

	int tot=0;

	for(int i=head[u];i;i=e[i].next)

	{

		if(e[i].to==pre)continue;

		dfs(e[i].to,u);

	}

	if(u==1&&!vis[u])flag=1;

	if(!vis[u])

	{

		vis[u]++;vis[pre]++;

	}

	if(vis[u]!=1)flag=1;

}

int main()

{

	flag=0;cnt=1;

	scanf("%d",&n);

	for(int i=1;i<n;++i)

	{

		int x,y;scanf("%d%d",&x,&y);add(x,y);add(y,x);

	}

	dfs(1,0);



	if(flag)puts("First");

	else puts("Second");

  return 0;

}
