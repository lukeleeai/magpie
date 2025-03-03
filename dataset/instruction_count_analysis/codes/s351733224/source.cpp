#include<cstdio>

#include<stack>

#include<ctime>

using namespace std;

#define N 1050

#define M 200500

int head[N],cnt,scc[N],dfn[N],low[N],f[N][13],s[M][2],as[M],vl[N],ct,ct2,vis[N][N],id[N],ct1,dep[N],is[N],n,m,ct3;

struct edge{int t,next,id;}ed[M];

void adde(int f,int t,int id){ed[++cnt]=(edge){t,head[f],id};head[f]=cnt;}

stack<int> tp,tp2,v[N],tp3;

void dfs1(int u)

{

	dfn[u]=low[u]=++ct1;

	tp.push(u);

	for(int i=head[u];i;i=ed[i].next)

	{

		if(!dfn[ed[i].t])dfs1(ed[i].t),low[u]=min(low[u],low[ed[i].t]);

		else if(!scc[ed[i].t])low[u]=min(low[u],dfn[ed[i].t]);

	}

	if(dfn[u]==low[u])

	{

		int s=tp.top(),id=++ct2;tp.pop();

		scc[s]=id;

		while(s!=u)

		s=tp.top(),tp.pop(),scc[s]=id;

	}

}

void dfs2(int u,int s){for(int i=head[u];i;i=ed[i].next)if(!vis[s][ed[i].t])vis[s][ed[i].t]=1,dfs2(ed[i].t,s);else vis[s][ed[i].t]++;}

int LCA(int x,int y){if(dep[x]<dep[y])x^=y^=x^=y;for(int i=10;i>=0;i--)if(dep[x]-dep[y]>=(1<<i))x=f[x][i];if(x==y)return x;for(int i=10;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];return f[x][0];}

void dfs3(int u,int fa)

{

	dfn[u]=1;dep[u]=dep[fa]+1;f[u][0]=fa;vl[u]=0;for(int i=1;i<=10;i++)f[u][i]=f[f[u][i-1]][i-1];

	for(int i=head[u];i;i=ed[i].next)

	if(!dfn[ed[i].t])tp.push(ed[i].id),dfs3(ed[i].t,u),vl[u]+=vl[ed[i].t];

	else{int s=LCA(u,ed[i].t);vl[u]++;vl[s]--;tp2.push(ed[i].id);}

}

bool check(int x)

{

	for(int i=1;i<=n;i++)dfn[i]=scc[i]=head[i]=0;

	cnt=0;ct2=0;

	for(int i=1;i<=m;i++)if(i!=x)adde(s[i][0],s[i][1],-1);else adde(s[i][1],s[i][0],-2);

	for(int i=1;i<=n;i++)if(!dfn[i])dfs1(i);

	return ct2!=ct3;

}

int main()

{

	scanf("%d%d",&n,&m);

	for(int i=1;i<=m;i++)scanf("%d%d",&s[i][0],&s[i][1]),adde(s[i][0],s[i][1],1);

	for(int i=1;i<=n;i++)if(!dfn[i])dfs1(i);ct3=ct2;

	for(int i=1;i<=n;i++)head[i]=0;cnt=0;

	for(int i=1;i<=m;i++)if(scc[s[i][0]]!=scc[s[i][1]])adde(scc[s[i][0]],scc[s[i][1]],-3);

	for(int i=1;i<=ct2;i++)dfs2(i,i);

	for(int i=1;i<=n;i++)head[i]=0;cnt=0;

	for(int i=1;i<=m;i++)if(scc[s[i][0]]!=scc[s[i][1]])as[i]=vis[scc[s[i][0]]][scc[s[i][1]]]>1;else v[scc[s[i][0]]].push(i);

	for(int i=1;i<=ct2;i++)

	{

		for(int j=1;j<=n;j++)dfn[j]=0,head[j]=0;

		ct1=0;cnt=0;

		for(int j=1;j<=n;j++)if(scc[j]==i)id[j]=++ct1;

		while(!v[i].empty())

		{

			int q=v[i].top();v[i].pop();

			adde(id[s[q][0]],id[s[q][1]],q);

		}

		dfs3(1,0);

		while(!tp2.empty())

		{

			int st=tp2.top();tp2.pop();

			int l=id[s[st][0]],r=id[s[st][1]];

			r=LCA(l,r);

			int fg=0;

			while(l!=r)fg|=(vl[l]==1),l=f[l][0];

			as[st]=fg;

		}

	}

	while(!tp.empty()){int st=tp.top();tp.pop();as[st]=check(st);}

	for(int i=1;i<=m;i++)printf("%s\n",as[i]?"diff":"same");

}///