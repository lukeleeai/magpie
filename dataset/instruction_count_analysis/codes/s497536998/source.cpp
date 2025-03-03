#include<cstdio>

#define N 200010

#define F for(register int j(1);j<=now;j++)

int n,m,k,now,cnt,pre[N],a[N],b[N],opt[N],head[N],nxt[N<<1],dis[N<<1];

bool used[N];

int find(int x)

{

	return !pre[x]?x:pre[x]=find(pre[x]);

}

inline void add(int x,int y)

{

	dis[++cnt]=y,nxt[cnt]=head[x],head[x]=cnt;

	return;

}

void dfs(int x)

{

	used[x]=1,a[++now]=x;

	for(register int i(head[x]);i;i=nxt[i])

		if(!used[dis[i]])

			dfs(dis[i]);

	return;

}

signed main()

{

	scanf("%d%d%d",&n,&m,&k);int x,y;

	while(m--)

		scanf("%d%d",&x,&y),(x=find(x))-(y=find(y))?pre[x]=y:8;

	while(k--)

		scanf("%d%d",&x,&y),add(x,y),add(y,x);

	for(register int i(1);i<=n;i++)

		if(!used[i])

		{

			dfs(i);

			F

				b[find(a[j])]++;

			F

				opt[a[j]]=b[find(a[j])];

			F

				b[find(a[j])]--;

			now=0;

		}

	for(register int i(1);i<=n;i++)

		printf("%d%c",opt[i],i-n?32:10);

	return 0;

}