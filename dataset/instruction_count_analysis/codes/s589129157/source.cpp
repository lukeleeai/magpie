#include <iostream>

#include <cstdio>

#include <cstring>

#define N 3002

using namespace std;

int head[N],ver[N*2],nxt[N*2],l;

int n,i,a[N],f[N];

int read()

{

	char c=getchar();

	int w=0;

	while(c<'0'||c>'9') c=getchar();

	while(c<='9'&&c>='0'){

		w=w*10+c-'0';

		c=getchar();

	}

	return w;

}

void insert(int x,int y)

{

	l++;

	ver[l]=y;

	nxt[l]=head[x];

	head[x]=l;

}

void dfs(int x,int pre)

{

	int minx=1<<30;

	for(int i=head[x];i;i=nxt[i]){

		int y=ver[i];

		if(y!=pre){

			dfs(y,x);

			if(!f[y]) minx=min(minx,a[y]);

		}

	}

	if(minx<a[x]) f[x]=1;

}

int main()

{

	n=read();

	for(i=1;i<=n;i++) a[i]=read();

	for(i=1;i<n;i++){

		int u=read(),v=read();

		insert(u,v);

		insert(v,u);

	}

	for(i=1;i<=n;i++){

		memset(f,0,sizeof(f));

		dfs(i,0);

		if(f[i]) printf("%d ",i);

	}

	puts("");

	return 0;

}