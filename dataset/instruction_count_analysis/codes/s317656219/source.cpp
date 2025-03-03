#include "stdc++.h"

using namespace std;

int n,a[200010],c[200010];

struct tree

{

	int Min0,Min1,pos0,pos1,l,r,tag;

}t[800010];

int Get(int x) {int an=0;for (;x;x-=x&(-x)) an+=c[x];return an;}

void Add(int x) {for (;x<=n;x+=x&(-x)) c[x]++;}

void Updata(int p)

{

	if (t[p*2].Min0<t[p*2+1].Min0) t[p].pos0=t[p*2].pos0,t[p].Min0=t[p*2].Min0;

	  else t[p].pos0=t[p*2+1].pos0,t[p].Min0=t[p*2+1].Min0;

	if (t[p*2].Min1<t[p*2+1].Min1) t[p].pos1=t[p*2].pos1,t[p].Min1=t[p*2].Min1;

	  else t[p].pos1=t[p*2+1].pos1,t[p].Min1=t[p*2+1].Min1;

}

void Build(int p,int l,int r)

{

	t[p].l=l;t[p].r=r;t[p].Min0=t[p].Min1=1e9;t[p].tag=0;

	if (l==r) {

		if (l&1) t[p].Min1=a[l],t[p].pos1=l;

		  else t[p].Min0=a[l],t[p].pos0=l;

		return;

	}

	int mid=(l+r)>>1;

	Build(p*2,l,mid);

	Build(p*2+1,mid+1,r);

	Updata(p);

}

void Pass(int p)

{

	if (t[p].tag==0) return;

	swap(t[p*2].Min0,t[p*2].Min1);swap(t[p*2].pos0,t[p*2].pos1);

	swap(t[p*2+1].Min0,t[p*2+1].Min1);swap(t[p*2+1].pos0,t[p*2+1].pos1);

	t[p*2].tag^=1;t[p*2+1].tag^=1;

	t[p].tag=0;

}

int Query(int p,int l,int r)

{

	if (t[p].l==l&&t[p].r==r) return t[p].pos0;

	Pass(p);

	int mid=(t[p].l+t[p].r)>>1;

	if (r<=mid) return Query(p*2,l,r);

	  else if (l>mid) return Query(p*2+1,l,r);

	int p1=Query(p*2,l,mid),p2=Query(p*2+1,mid+1,r);

	if (a[p1]<a[p2]) return p1;

	else return p2;

}

void Modify(int p,int l,int r)

{

	if (t[p].l==l&&t[p].r==r) {

		swap(t[p].Min0,t[p].Min1);

		swap(t[p].pos0,t[p].pos1);

		t[p].tag^=1;

		return;

	}

	Pass(p);

	int mid=(t[p].l+t[p].r)>>1;

	if (r<=mid) Modify(p*2,l,r);

	  else if (l>mid) Modify(p*2+1,l,r);

	    else Modify(p*2,l,mid),Modify(p*2+1,mid+1,r);

	Updata(p);

}

void Change(int p,int x)

{

	if (t[p].l==x&&t[p].r==x) {

		t[p].Min0=t[p].Min1=1e9;

		t[p].pos0=t[p].pos1=0;

		return ;

	}

	Pass(p);

	int mid=(t[p].l+t[p].r)>>1;

	if (x<=mid) Change(p*2,x);

	else Change(p*2+1,x);

	Updata(p);

}

int main()

{

	scanf("%d",&n);

	a[0]=1e9;

	for (int i=1;i<=n;i++)

	  scanf("%d",&a[i]);

	Build(1,1,n);

	for (int i=1;i<=n/2;i++) {

		int x=t[1].pos1;

		int l=x+1,r=n;

		int s=Get(x);

		while (l+1<r) {

			int mid=(l+r)>>1;

			if (Get(mid)-s) r=mid;

			else l=mid;

		}

		int y;

		if (Get(l)-s) y=Query(1,x+1,l-1);else if (Get(r)-s) y=Query(1,x+1,r-1);

		else y=Query(1,x+1,r);

		printf("%d %d ",a[x],a[y]);

		if (x<y-1) Modify(1,x+1,y-1);

		Change(1,x);

		Change(1,y);

		Add(x);Add(y);

	}

}