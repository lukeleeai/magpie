#include<cstdio>

using namespace std;

#define N 205000

int head[N],cnt,dep[N],l,r,in[N],st[N],n,a,b,ct,st2[N],fg,as1[N],as2[N],is[N];

struct edge{int t,next;}ed[N*2];

void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;in[f]++,in[t]++;}

void dfs(int u,int fa){dep[u]=dep[fa]+1;for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs(ed[i].t,u);}

void dfs2(int u,int t,int fa){if(!fg)st[++ct]=u;if(u==t)fg=1;for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs2(ed[i].t,t,u);if(!fg)ct--;}

int main()

{

	scanf("%d",&n);

	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b);

	dfs(1,0);int mx=0,vl;for(int i=1;i<=n;i++)if(dep[i]>mx)mx=dep[i],vl=i;

	dfs(vl,0);mx=0;int vl2=0;for(int i=1;i<=n;i++)if(dep[i]>mx)mx=dep[i],vl2=i;

	dfs2(vl,vl2,0);

	for(int i=1;i<=ct;i++)is[st[i]]=1;

	for(int i=1;i<=n;i++)if(!is[i]&&in[i]>1){printf("-1\n");return 0;}

	for(int i=1;i<=ct;i++)st2[i]=in[st[i]]-2+(in[st[i]]==1);

	int lb=0;

	for(int i=1;i<=ct;i++)

	{

		for(int j=1;j<=st2[i];j++)as1[lb+j]=lb+j+1;

		as1[lb+st2[i]+1]=lb+1;

		lb+=st2[i]+1;

	}

	lb=0;

	for(int i=ct;i>=1;i--)

	{

		for(int j=1;j<=st2[i];j++)as2[lb+j]=lb+j+1;

		as2[lb+st2[i]+1]=lb+1;

		lb+=st2[i]+1;

	}

	int fg2=0;

	for(int i=1;i<=n;i++)if(as1[i]<as2[i]){fg2=1;break;}else if(as2[i]<as1[i])break;

	if(!fg2)for(int i=1;i<=n;i++)as1[i]=as2[i];

	for(int i=1;i<=n;i++)printf("%d ",as1[i]);

}//