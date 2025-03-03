#include"stdc++.h"

using namespace std;

const int N=500005;

struct ab{int f,t;} t[N];

int h,hh[N],vv[N],ans[N];

void make(int x,int y)

{

	t[++h].f=hh[x];

	t[h].t=y;

	hh[x]=h;

}

int dfs1(int x,int y,int z)

{

	if(x>z) return 0;

	int now=1;

	for(int i=hh[x];i;i=t[i].f)

	{

		int j=t[i].t;

		if(j==y) continue;

		now+=dfs1(j,x,z);

	}

	return now;

}

int dfs2(int x,int y,int z)

{

	int now=1;

	for(int i=hh[x];i;i=t[i].f)

	{

		int j=t[i].t;

		if(j==y) continue;

		if(j<z) now+=dfs2(j,x,z);

	}

	return now;

}

void dfs(int x,int y,int z,int v)

{

	if(x>z) v+=dfs2(x,y,z);

	ans[x]=v;

	for(int i=hh[x];i;i=t[i].f)

	{

		int j=t[i].t;

		if(j==y) continue;

		if(x>z) dfs(j,x,x,v+dfs1(j,x,x)-dfs1(j,x,z));

		else dfs(j,x,z,v);

	}

}

int main()

{

	int n;

	scanf("%d",&n);

	for(int i=1;i<n;i++)

	{

		int x,y;

		scanf("%d%d",&x,&y);

		make(x,y),make(y,x);

	}

	dfs(1,0,0,0);

	for(int i=2;i<=n;i++) printf("%d ",ans[i]-1);printf("\n");

	return 0;

}