#include <cstdio>

#include <algorithm>

#define maxn 100000+10

using namespace std;

int f[maxn],ans[maxn],n,m,Q,x,y,z,head[maxn],g;

struct xx

{

	int v,next;

}b[maxn<<1];



struct yy

{

	int x,d,col;

}a[maxn];



void add(int u,int v)

{

	b[++g]=(xx){v,head[u]};

	head[u]=g;

}



void dfs(int x,int d,int col)

{

	if (f[x]>=d) return ;

	f[x]=d;

	if (d<=0)return ;

	if (!ans[x])ans[x]=col;

	for (int i=head[x];i;i=b[i].next)

	{

		int v=b[i].v;

		dfs(v,d-1,col);

	}

}



int main()

{

	scanf("%d%d",&n,&m);

	for (int i=1;i<=m;++i)

	  scanf("%d%d",&x,&y),add(x,y),add(y,x);

	scanf("%d",&Q);

	for (int i=1;i<=Q;++i)

	  scanf("%d%d%d",&x,&y,&z),a[i]=(yy){x,y+1,z};

	for (int i=Q;i>=1;--i)

	  dfs(a[i].x,a[i].d,a[i].col);

	for (int i=1;i<=n;++i) printf("%d\n",ans[i]);

	return 0;

}