#include"stdc++.h" 

const int maxn=202020;

struct Edge{

	int to;

	int last;

}a[maxn<<1];

int n,m;

int tot;

int d[maxn];

int head[maxn];

inline void HA(int x,int y)

{

	a[++tot]={y,head[x]};

	head[x]=tot;

	a[++tot]={x,head[y]};

	head[y]=tot;

}

#define y a[i].to

inline void Dfs(int x,int prt){

	for(int i=head[x];i;i=a[i].last)

		if(y!=prt)d[y]=d[x]+1,Dfs(y,x);

	if(d[x]>d[m])m=x;

}

#undef y

int main()

{

	scanf("%d",&n);

	for(int i=1,x,y;i<n;++i)

	{

		scanf("%d%d",&x,&y);

		HA(x,y);

	}

	m=0,Dfs(1,0);

	int temp=m;d[m]=0;

	m=0,Dfs(temp,0);

	puts(d[m]%3==1 ? "Second" : "First");

	return 0;

}