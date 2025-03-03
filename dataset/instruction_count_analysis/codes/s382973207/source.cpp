#include<cstdio>

#include<algorithm>

#define maxn 100005

#define LL long long

using namespace std;

int n,m,fa[maxn],use[maxn],cnt;

LL ans;

struct node { int w;bool vis; } a[maxn];

bool cmp(node p,node q) 

{

	if(p.vis) return false;

	if(q.vis) return true;

	return p.w<q.w; 

}

int find(int x)

{

	if(fa[x]==x) return x;

	return fa[x]=find(fa[x]);

}

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)

	{

		scanf("%d",&a[i].w);

		fa[i]=i;use[i]=i;

		a[i].vis=true;

	}

	for(int i=1;i<=m;i++)

	{

		int u,v;

		scanf("%d%d",&u,&v);

		u++,v++;

		int r1=find(u),r2=find(v);

		if(r1!=r2)

		{

			if(a[use[r2]].w<a[use[r1]].w)

			{

				a[use[r1]].vis=false;

				use[r1]=use[r2];

			}

			else a[use[r2]].vis=false;

			fa[r2]=r1;

		}

	}

	for(int i=1;i<=n;i++)

		if(find(i)==i) 

		{

			ans+=1ll*a[use[i]].w;

			cnt++;

		}

	if(cnt==1)

	{

		printf("0\n");

		return 0;

	}

	sort(a+1,a+n+1,cmp);

	for(int i=1;i<=cnt-2;i++)

		if(a[i].vis)

		{

			printf("Impossible\n");

			return 0;

		}

		else ans+=1ll*a[i].w;

	printf("%lld\n",ans);

}