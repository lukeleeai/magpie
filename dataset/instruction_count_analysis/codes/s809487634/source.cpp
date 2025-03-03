#include<iostream>

#include<cstdio>

#include<cstring>

#include<queue>

#include<vector>

#define N 500010

#define P pair<int,int>

#define MP make_pair

#define fi first

#define se second

using namespace std;

P tree[N<<2];

void change(int u,int l,int r,P x)

{

	tree[u]=max(tree[u],x);

	if(l==r) return;

	int mid=(l+r)>>1;

	if(x.se<=mid) change(u<<1,l,mid,x);

	else change(u<<1|1,mid+1,r,x);

}

P answer(int u,int l,int r,int L,int R)

{

	if(L<=l && r<=R) return tree[u];

	if(R<L) return MP(0,0);

	int mid=(l+r)>>1;

	P ans=MP(0,0);

	if(L<=mid) ans=max(ans,answer(u<<1,l,mid,L,R));

	if(R>mid) ans=max(ans,answer(u<<1|1,mid+1,r,L,R));

	return ans;

}

int nxt[N<<1],to[N<<1],head[N],in[N],cnt;

int p[N];

void add(int u,int v)

{

	nxt[++cnt]=head[u];

	to[cnt]=v;

	in[v]++;

	head[u]=cnt;

}

priority_queue<int,vector<int>,greater<int> > q;

int ans[N];

int main()

{

	int n,k;

	scanf("%d%d",&n,&k);

	for(int i=1;i<=n;i++)

	{

		int a;

		scanf("%d",&a);

		p[a]=i;

	}

	for(int i=1;i<=n;i++)

	{

		change(1,1,n,MP(i,p[i]));

		P l=answer(1,1,n,max(1,p[i]-k+1),p[i]-1),r=answer(1,1,n,p[i]+1,min(p[i]+k-1,n));

		if(l.fi>0) add(l.se,p[i]);

		if(r.fi>0) add(r.se,p[i]);

	}

	for(int i=1;i<=n;i++) if(!in[i]) q.push(i);

	int tot=0;

	while(!q.empty())

	{

		int u=q.top();

		q.pop();

		ans[u]=++tot;

		for(int i=head[u];i;i=nxt[i])

		{

			int v=to[i];

			in[v]--;

			if(!in[v]) q.push(v);

		}

	}

	for(int i=1;i<=tot;i++) printf("%d\n",ans[i]);

	return 0;

}
