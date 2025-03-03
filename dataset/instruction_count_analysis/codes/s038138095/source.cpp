#include<cstdio>

#include<cstring>

#include<cstdlib>

using namespace std;

typedef long long LL;

const int maxn=100000,maxm=100000;



int n,m,col[maxn+5],A,B;

int E,lnk[maxn+5],son[maxm*2+5],nxt[maxm*2+5];



inline void Add(int x,int y) {son[++E]=y;nxt[E]=lnk[x];lnk[x]=E;}

void Dfs(int x,int now=0,int fa=0)

{

	col[x]=now;now^=1;

	for (int j=lnk[x];j;j=nxt[j])

	{

		if (col[son[j]]==-1) Dfs(son[j],now,x);

		if (col[son[j]]!=now) printf("%lld\n",(LL)n*(n-1)/2-m),exit(0);

	}

}

int main()

{

	scanf("%d%d",&n,&m);memset(col,255,sizeof(col));

	for (int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),Add(x,y),Add(y,x);

	Dfs(1);for (int i=1;i<=n;i++) if (col[i]) A++; else B++;

	return printf("%lld\n",(LL)A*B-m),0;

}