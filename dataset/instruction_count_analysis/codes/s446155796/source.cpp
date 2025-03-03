#include"stdc++.h"

#define ci const int&

#define Updl(x) (t[x].vl=Mrgl(t[x<<1].vl,t[x<<1|1].vl))

#define Updr(x) (t[x].vr=Mrgr(t[x<<1].vr,t[x<<1|1].vr))

#define pi pair<int,int>

#define f first

#define s second

using namespace std;

struct node{

	int l,r;

	pi vl,vr;

}t[400010];

int n,p[100010],pos[100010],l1,l2,r1,r2;

long long ans;

pi tmp;

pi Mrgl(const pi&x,const pi&y){

	return x.f>y.f?(pi){x.f,max(x.s,y.f)}:(pi){y.f,max(x.f,y.s)};

}

pi Mrgr(const pi&x,const pi&y){

	return x.f<y.f?(pi){x.f,min(x.s,y.f)}:(pi){y.f,min(x.f,y.s)};

}

void Build(ci x,ci l,ci r){

	t[x].l=l,t[x].r=r;

	if(l==r)return(void)(t[x].vr.f=pos[l],t[x].vr.s=n+1);

	int mid=l+r>>1;

	Build(x<<1,l,mid),Build(x<<1|1,mid+1,r),Updr(x);

}

void Changel(ci x,ci id,ci v){

	if(t[x].l==t[x].r)return(void)(t[x].vl.f=v);

	int mid=t[x].l+t[x].r>>1;

	id<=mid?Changel(x<<1,id,v):Changel(x<<1|1,id,v),Updl(x);

}

void Changer(ci x,ci id){

	if(t[x].l==t[x].r)return(void)(t[x].vr.f=n+1);

	int mid=t[x].l+t[x].r>>1;

	id<=mid?Changer(x<<1,id):Changer(x<<1|1,id),Updr(x);

}

pi Queryl(ci x,ci l,ci r){

	if(l>r)return(pi){0,0};

	if(t[x].l==l&&t[x].r==r)return t[x].vl;

	int mid=t[x].l+t[x].r>>1;

	return r<=mid?Queryl(x<<1,l,r):(l>mid?Queryl(x<<1|1,l,r):(Mrgl(Queryl(x<<1,l,mid),Queryl(x<<1|1,mid+1,r))));

}

pi Queryr(ci x,ci l,ci r){

	if(l>r)return(pi){n+1,n+1};

	if(t[x].l==l&&t[x].r==r)return t[x].vr;

	int mid=t[x].l+t[x].r>>1;

	return r<=mid?Queryr(x<<1,l,r):(l>mid?Queryr(x<<1|1,l,r):(Mrgr(Queryr(x<<1,l,mid),Queryr(x<<1|1,mid+1,r))));

}

int main(){

	scanf("%d",&n);

	for(int i=1;i<=n;++i)scanf("%d",&p[i]),pos[p[i]]=i;

	Build(1,1,n);

	for(int i=1;i<=n;++i){

		Changer(1,p[i]),Changel(1,p[i],i),tmp=Queryl(1,p[i]+1,n),l1=tmp.f,l2=tmp.s,tmp=Queryr(1,p[i]+1,n),r1=tmp.f,r2=tmp.s;

		ans+=1ll*(i-l1)*(r2-r1)*p[i]+1ll*(l1-l2)*(r1-i)*p[i];

	}

	printf("%lld",ans);

	return 0;

}