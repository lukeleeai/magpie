#include<cstdio>

#include<queue>

#include<cstring>

#include<algorithm>

using namespace std;

#define MAXN 500010

int a[MAXN],n,k,ans[MAXN];

int t[MAXN*4];

int Query(int i,int l,int r,int L,int R)

{

	if(L>R) return t[0];

	if(L<=l&&r<=R) return t[i];

	int mid=(l+r)/2;

	if(R<=mid) return Query(i<<1,l,mid,L,R);

	if(L>mid) return Query(i<<1|1,mid+1,r,L,R);

	return min(Query(i<<1,l,mid,L,R),Query(i<<1|1,mid+1,r,L,R));

}

void Change(int i,int l,int r,int p,int w)

{

	if(l==r)

	{

		t[i]=w;

		return;

	}

	int mid=(l+r)/2;

	if(p<=mid) Change(i<<1,l,mid,p,w);

	else Change(i<<1|1,mid+1,r,p,w);

	t[i]=min(t[i<<1|1],t[i<<1]);

}

int Adj[MAXN],V[MAXN*2],nxt[MAXN*2],c,d[MAXN];

void AddEdge(int u,int v)

{

	d[v]++;c++;V[c]=v,nxt[c]=Adj[u];Adj[u]=c;

}

priority_queue<int ,vector<int>,greater<int> >Q;

void TopSort()

{

	for(int i=1;i<=n;i++) if(!d[i]) Q.push(i);

	int tot=0;

	while(!Q.empty())

	{

		int u=Q.top();Q.pop();

		ans[u]=++tot;

		for(int i=Adj[u];i;i=nxt[i])

			if(!--d[V[i]])

				Q.push(V[i]);

	}

}

int main()

{

//	freopen("swap.in","r",stdin);

//	freopen("swap.out","w",stdout);

	scanf("%d%d",&n,&k);

	for(int i=1;i<=n;i++)

	{

		int x;

		scanf("%d",&x);

		a[x]=i;

	}

	if(k<=1)

	{

		for(int i=1;i<=n;i++)

			printf("%d\n",i);

		return 0;

	}

	memset(t,0x3f3f3f3f,sizeof t);

	for(int i=n;i;i--)

	{

		int x=Query(1,1,n,a[i]+1,min(a[i]+k-1,n));

		if(x<1e9) AddEdge(a[i],a[x]);

		x=Query(1,1,n,max(a[i]-k+1,1),a[i]-1);

		if(x<1e9) AddEdge(a[i],a[x]);

		Change(1,1,n,a[i],i);

	}

	TopSort();

	for(int i=1;i<=n;i++)

		printf("%d\n",ans[i]);

}