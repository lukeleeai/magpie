#include"stdc++.h"

using namespace std;

const int maxn=5e5+5;

const int INF=1e7+5;

priority_queue<int,vector<int>,greater<int> > q;

int n,k;

int A[maxn],ans[maxn],ind[maxn];

int tot;

int h[maxn],last[maxn<<1],to[maxn<<1];

int st[maxn<<2];

void build(int x,int l,int r)

{

	st[x]=INF;

	if(l==r) return;

	int mid=(l+r)>>1;

	build(x<<1,l,mid),build(x<<1|1,mid+1,r);

} 

void pushup(int x)

{

	st[x]=min(st[x<<1],st[x<<1|1]);

}

void update(int x,int l,int r,int id,int k)

{

	if(l==r){

		st[x]=k;

		return;

	}

	int mid=(l+r)>>1;

	if(id<=mid) update(x<<1,l,mid,id,k);

	else update(x<<1|1,mid+1,r,id,k);

	pushup(x);

}

int query(int x,int l,int r,int ql,int qr)

{

	if(r<ql||l>qr) return INF;

	if(l>=ql&&r<=qr) return st[x];

	int mid=(l+r)>>1;

	return min(query(x<<1,l,mid,ql,qr),query(x<<1|1,mid+1,r,ql,qr));

}

void add(int x,int y)

{

	to[++tot]=y;last[tot]=h[x];h[x]=tot;++ind[y];

}

int main()

{

	scanf("%d%d",&n,&k);

	for(int i=1;i<=n;++i){

		int a=0;

		scanf("%d",&a);

		A[a]=i;

	}

	build(1,1,n);

	for(int i=n;i>=1;--i){

		int l=query(1,1,n,A[i],A[i]+k-1),r=query(1,1,n,A[i]-k+1,A[i]);

		if(l!=INF) add(A[i],A[l]);

		if(r!=INF) add(A[i],A[r]);

		update(1,1,n,A[i],i);

	}

	for(int i=1;i<=n;++i) if(!ind[i]) q.push(i);

	int cnt=0;

	while(q.size()){

		int u=q.top();

		q.pop();

		ans[u]=++cnt; 

		for(int i=h[u];i;i=last[i]){

			int v=to[i];

			if(!--ind[v]) q.push(v);

		}

	}

	for(int i=1;i<=n;++i) printf("%d\n",ans[i]);

	return 0;

}