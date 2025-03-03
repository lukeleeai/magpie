#include<cstdio>

#include<algorithm>

#define int long long

using namespace std;

const int maxN=1e6 + 100;

struct Node

{

	int to,value,next;

}edge[maxN*2+1];

int n,m,head[maxN+1],tot,dis[maxN+1];

bool col[maxN+1];

int maxT=-1e15,minT=1e15,ans=-1e15;

void add(int x,int y,int t)

{

	tot++;

	edge[tot].to=y;

	edge[tot].value=t;

	edge[tot].next=head[x];

	head[x]=tot;

}

bool dfs(int x)

{

	maxT=max(maxT,dis[x]);

	minT=min(minT,dis[x]);

	bool flag=true;

	col[x]=true;

	for(int i=head[x];i;i=edge[i].next)

		if(!col[edge[i].to]) dis[edge[i].to]=dis[x]+edge[i].value,flag=(flag&&dfs(edge[i].to));

		else if(dis[x]+edge[i].value!=dis[edge[i].to]) flag=false;

	return flag;

}

#undef int

int main()

#define int long long

{

//	freopen("line.in","r",stdin);

//	freopen("line.out","w",stdout);

	scanf("%lld%lld",&n,&m);

	for(int i=1;i<=m;i++)

	{

		int x,y,t;

		scanf("%lld%lld%lld",&x,&y,&t);

		add(x,y,t); add(y,x,-t);

	}

	for(int i=1;i<=n;i++)

		if(!col[i])

		{

			maxT=-1e18,minT=1e18;

			if(!dfs(i))

			{

				printf("No");

				return 0;

			}

			ans=max(ans,maxT-minT);

		}

	printf("Yes");

	fclose(stdin);

	fclose(stdout);

	return 0;

}