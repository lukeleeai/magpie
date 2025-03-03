#include<cstdio>

#include<queue>

#include<algorithm>

#include<cstring>

#include<set>

using namespace std;

#define N 206

int head[N],cnt=1,dis[N],n,m,v[N][N],as[N][N],as2[N][N],cur[N];

multiset<int> sb[N],vl[N][N];

struct edge{int t,next,v;}ed[N*N*3];

void adde(int f,int t,int v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){f,head[t],0};head[t]=cnt;}

bool bfs(int s,int t)

{

	queue<int> v;

	memset(dis,-1,sizeof(dis));

	memcpy(cur,head,sizeof(cur));

	v.push(s);dis[s]=1;

	while(!v.empty())

	{

		int r=v.front();v.pop();

		for(int i=head[r];i;i=ed[i].next)

		if(dis[ed[i].t]==-1&&ed[i].v)

		{dis[ed[i].t]=dis[r]+1,v.push(ed[i].t);if(ed[i].t==t)return 1;}

	}

	return 0;

}

int dfs(int u,int t,int f)

{

	if(!f||(u==t))return f;

	int as=0,tp;

	for(int &i=cur[u];i;i=ed[i].next)

	if(ed[i].v&&dis[ed[i].t]==dis[u]+1&&(tp=dfs(ed[i].t,t,min(ed[i].v,f))))

	{

		ed[i].v-=tp,ed[i^1].v+=tp,as+=tp,f-=tp;

		if(!f)return as;

	}

	return as;

}

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++)

	for(int j=1;j<=m;j++)

	{

		scanf("%d",&v[i][j]);

		int v1=(v[i][j]-1)/m+1;

		sb[i].insert(v1),vl[i][v1].insert(v[i][j]);

	}

	for(int i=1;i<=m;i++)

	{

		for(int j=1;j<=n*2+2;j++)head[j]=0;

		cnt=1;

		for(int j=1;j<=n;j++)

		{

			adde(n*2+1,j,1);adde(j+n,n*2+2,1);

			for(int k=1;k<=n;k++)

			{

				multiset<int>::iterator it=sb[j].lower_bound(k);

				if(it==sb[j].end()||*it!=k)continue;

				adde(j,k+n,1);

			}

		}

		while(bfs(n*2+1,n*2+2))dfs(n*2+1,n*2+2,1e8);

		for(int j=1;j<=n;j++)

		for(int k=head[j];k;k=ed[k].next)

		if(!ed[k].v)

		{

			int l=j,r=ed[k].t-n;

			as[l][i]=as2[i][l]=*vl[l][r].begin();

			vl[l][r].erase(vl[l][r].begin());

			sb[l].erase(sb[l].find(r));

		}

	}

	for(int i=1;i<=n;i++,printf("\n"))

	for(int j=1;j<=m;j++)

	printf("%d ",as[i][j]);

	for(int i=1;i<=m;i++)sort(as2[i]+1,as2[i]+n+1);

	for(int i=1;i<=n;i++,printf("\n"))

	for(int j=1;j<=m;j++)

	printf("%d ",as2[j][i]);

}//