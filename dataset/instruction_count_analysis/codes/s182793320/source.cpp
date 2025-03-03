#include<vector>

#include<cstdio>

#include<cstdlib>

#include<iostream>

#include<cstring>

#include<algorithm>

#define LL long long

using namespace std;

const LL inf=1LL<<60;

LL n,d,a[200010];

struct node{

	LL c1,c2,k1,k2;

	node() {}

	node(LL a,LL b,LL c,LL d) {c1=a;c2=b;k1=c;k2=d;}

};

LL fa[200010];

LL findfa(LL x) {return fa[x]==x?x:fa[x]=findfa(fa[x]);}

struct Node{

	LL x,y,c;

}e[200010];LL len=0;

struct trnode{

	LL lc,rc;

	node c;

}tr[400010];LL tot=0;

node update(node lc,node rc)

{

	node c;

	c.c1=min(lc.c1,rc.c1);

	c.k1=lc.c1<rc.c1?lc.k1:rc.k1;

	c.k2=lc.c2<rc.c2?lc.k2:rc.k2;

	c.c2=min(lc.c2,rc.c2);

	return c;

}

void change(LL x,LL l,LL r,LL k,node c)

{

	if(l==r) {tr[x].c=c;return;}

	LL mid=(l+r)/2;

	if(k<=mid) change(tr[x].lc,l,mid,k,c);

	else change(tr[x].rc,mid+1,r,k,c);

	tr[x].c=update(tr[tr[x].lc].c,tr[tr[x].rc].c);

}

node findans(LL x,LL l,LL r,LL fl,LL fr)

{

	if(fl>fr) return node(inf,inf,1,1);

	if(l==fl&&r==fr) return tr[x].c;

	LL mid=(l+r)/2;

	if(fr<=mid) return findans(tr[x].lc,l,mid,fl,fr);

	if(fl>mid) return findans(tr[x].rc,mid+1,r,fl,fr);

	return update(findans(tr[x].lc,l,mid,fl,mid),findans(tr[x].rc,mid+1,r,mid+1,fr));

}

LL bt(LL l,LL r)

{

	LL x=++tot;

	if(l!=r)

	{

		LL mid=(l+r)/2;

		tr[x].lc=bt(l,mid);

		tr[x].rc=bt(mid+1,r);

		tr[x].c=update(tr[tr[x].lc].c,tr[tr[x].rc].c);

	}

	else tr[x].c=node(l*d+a[l],-l*d+a[l],l,l);

	return x;

}

vector<int> vec[200010];

bool cmp(Node a,Node b) {return a.c<b.c;}

bool vis[200010];

int main()

{

	scanf("%lld %lld",&n,&d);

	for(LL i=1;i<=n;i++) fa[i]=i;

	for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);

	bt(1,n);LL num=n;

	LL ans=0;

	while(num!=1)

	{

		memset(vis,false,sizeof(vis));

		for(LL i=1;i<=n;i++) vec[i].clear();

		for(LL i=1;i<=n;i++) vec[findfa(i)].push_back(i);

		len=0;

		for(LL i=1;i<=n;i++)

			if(findfa(i)==i)

			{

				for(LL j=0;j<vec[i].size();j++)

				{

					LL y=vec[i][j];

					change(1,1,n,y,node(inf,inf,y,y));

				}

				for(LL j=0;j<vec[i].size();j++)

				{

					LL y=vec[i][j];

					node c1=findans(1,1,n,1,y-1);

					node c2=findans(1,1,n,y+1,n);

					LL C1=c1.c2+y*d+a[y],C2=c2.c1-y*d+a[y];

					if(C1<C2) e[++len].x=i,e[len].y=c1.k2,e[len].c=C1;

					else e[++len].x=i,e[len].y=c2.k1,e[len].c=C2;

				}

				for(LL j=0;j<vec[i].size();j++)

				{

					LL y=vec[i][j];

					change(1,1,n,y,node(y*d+a[y],-y*d+a[y],y,y));

				}

			}

		sort(e+1,e+len+1,cmp);

		for(LL i=1;i<=len;i++)

		{

			LL tx=findfa(e[i].x),ty=findfa(e[i].y);

			if(vis[tx]) continue;

			vis[tx]=true;

			if(tx!=ty)

			{

				ans+=e[i].c;

				fa[tx]=ty;num--;

			}

		}

	}

	printf("%lld",ans);

}