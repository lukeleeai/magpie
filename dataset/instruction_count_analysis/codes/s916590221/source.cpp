#include "stdc++.h"

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;i++)

#define dep(i,a,b) for(int i=a;i>=b;i--)

#define N 500005

#define inf 666666666

int in[N],pos[N],p[N],ans[N],tot,n,k;

priority_queue <int> q;

int head[N],to[N<<1],nxt[N<<1],cnt;

void add(int u,int v)

{

	cnt++;

	to[cnt]=v;

	nxt[cnt]=head[u];

	head[u]=cnt;

}

#define ls id<<1

#define rs id<<1|1

int t[N<<2];

void change(int id,int l,int r,int p,int d)

{

	if(l==r) {

		t[id]=d;

		return;

	}

	int mid=(l+r)>>1;

	if(p<=mid) change(ls,l,mid,p,d);

	else change(rs,mid+1,r,p,d);

	t[id]=min(t[ls],t[rs]);

}

int query(int id,int L,int R,int l,int r)

{

	if(t[id]>=N) return inf;

	if(l==L&&r==R) return t[id];

	int Mid=(L+R)>>1;

	if(r<=Mid) return query(ls,L,Mid,l,r);

	else if(l>Mid) return query(rs,Mid+1,R,l,r);

	else return min(query(ls,L,Mid,l,Mid),query(rs,Mid+1,R,Mid+1,r));

}

int main()

{

	int tmp;

	scanf("%d%d",&n,&k);

	rep(i,1,n) 

		scanf("%d",&tmp),p[tmp]=i;

	memset(t,0x3f,sizeof(t));

	dep(i,n,1) {

		int pos=query(1,1,n,p[i],min(n,p[i]+k-1));

		if(pos!=inf) {

			add(p[i],p[pos]);

			in[p[pos]]++;

		}

		pos=query(1,1,n,max(1,p[i]-k+1),p[i]);

		if(pos!=inf) {

			add(p[i],p[pos]);

			in[p[pos]]++;

		}

		change(1,1,n,p[i],i);

	}

	rep(i,1,n) if(!in[i]) q.push(-i);

	while(!q.empty()) {

		int now=-q.top();

		ans[now]=++tot;

		q.pop();

		for(int i=head[now]; i; i=nxt[i]) {

			int v=to[i];

			--in[v];

			if(!in[v]) q.push(-v);

		}

	}

	rep(i,1,n) printf("%d\n",ans[i]);

	return 0;

}