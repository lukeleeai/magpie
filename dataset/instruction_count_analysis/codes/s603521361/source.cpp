#include<cstdio>

#include<algorithm>

#include<cstring>

#define MN 200005

using namespace std;

typedef long long ll;

int n,q;

ll mk[MN<<2];

struct node{

	ll mi[4];

	friend node operator+(node x,node y){

		node z;

		for(int i=1;i<=3;i++)z.mi[i]=min(x.mi[i],y.mi[i]);

		return z;

	}

}T[MN<<2];

void uadd(int v){for(int i=1;i<=3;i++)T[1].mi[i]+=v;mk[1]+=v;}

void pushdown(int k,int l,int r){

	mk[k<<1]+=mk[k],mk[k<<1|1]+=mk[k];

	for(int i=1;i<=3;i++)T[k<<1].mi[i]+=mk[k],T[k<<1|1].mi[i]+=mk[k];mk[k]=0;

}

void update(int l,int r,int a,int k,ll ad){

	if(l==r)return (void)(T[k].mi[1]>ad?(T[k].mi[1]=ad,T[k].mi[2]=ad-l,T[k].mi[3]=ad+l):0);if(mk[k])pushdown(k,l,r);int mid=(l+r)>>1;

	if(a<=mid)update(l,mid,a,k<<1,ad);else update(mid+1,r,a,k<<1|1,ad);T[k]=T[k<<1]+T[k<<1|1];

}

ll que1(int l,int r,int a,int b,int k){

	if(l==a&&r==b)return T[k].mi[2];if(mk[k])pushdown(k,l,r);int mid=(l+r)>>1;

	if(b<=mid)return que1(l,mid,a,b,k<<1);if(a>mid)return que1(mid+1,r,a,b,k<<1|1);

	return min(que1(l,mid,a,mid,k<<1),que1(mid+1,r,mid+1,b,k<<1|1));

}

ll que2(int l,int r,int a,int b,int k){

	if(l==a&&r==b)return T[k].mi[3];if(mk[k])pushdown(k,l,r);int mid=(l+r)>>1;

	if(b<=mid)return que2(l,mid,a,b,k<<1);if(a>mid)return que2(mid+1,r,a,b,k<<1|1);

	return min(que2(l,mid,a,mid,k<<1),que2(mid+1,r,mid+1,b,k<<1|1));

}

void build(int l,int r,int k){

	if(l==r)return (void)(T[k].mi[1]=T[k].mi[2]=T[k].mi[3]=1e18);int mid=(l+r)>>1;

	build(l,mid,k<<1);build(mid+1,r,k<<1|1);T[k]=T[k<<1]+T[k<<1|1];

}

int main(){

	int a,b;scanf("%d%d%d%d",&n,&q,&a,&b);build(1,n,1);

	update(1,n,b,1,0);

	int lst=a,x;

	for(int i=1;i<=q;i++){

		scanf("%d",&x);

		ll tmp=min(que1(1,n,1,x,1)+x,que2(1,n,x,n,1)-x);

		uadd(abs(x-lst));update(1,n,lst,1,tmp);lst=x;

	}printf("%lld\n",T[1].mi[1]);

}