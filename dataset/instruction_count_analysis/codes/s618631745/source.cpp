#include"stdc++.h"

#define F(i,a,b) for(int i=(a);i<=(b);++i)

#define F2(i,a,b) for(int i=(a);i<(b);++i)

#define dF(i,a,b) for(int i=(a);i>=(b);--i)

#define dF2(i,a,b) for(int i=(a);i>(b);--i)

#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)

using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;



int n;

ll a[200001],a1[200001],a2[200001];

int id[200001];

int dat[524289],dat1[524289],dat2[524289];

ll Sum;

int m(ll*arr,int p1,int p2){return arr[p1]<arr[p2]?p1:p2;}

void build(int i,int l,int r){

	if(l==r) {id[l]=i; return;}

	int mid=l+r>>1; build(i<<1,l,mid), build(i<<1|1,mid+1,r);

}

void Mod(int p,ll x){

	a[p]=x; a1[p]=x-p; a2[p]=x+p;

	dat[id[p]]=dat1[id[p]]=dat2[id[p]]=p;

	for(int i=id[p]>>1;i;i>>=1) dat[i]=m(a,dat[i<<1],dat[i<<1|1]), dat1[i]=m(a1,dat1[i<<1],dat1[i<<1|1]), dat2[i]=m(a2,dat2[i<<1],dat2[i<<1|1]);

}

int Qur1(int i,int l,int r,int a,int b){

	if(b<l||r<a) return 0; if(a<=l&&r<=b) return dat1[i];

	int mid=l+r>>1; return m(a1,Qur1(i<<1,l,mid,a,b),Qur1(i<<1|1,mid+1,r,a,b));

}

int Qur2(int i,int l,int r,int a,int b){

	if(b<l||r<a) return 0; if(a<=l&&r<=b) return dat2[i];

	int mid=l+r>>1; return m(a2,Qur2(i<<1,l,mid,a,b),Qur2(i<<1|1,mid+1,r,a,b));

}

int main(){

	memset(a,0x3f,sizeof a);

	memset(a1,0x3f,sizeof a1);

	memset(a2,0x3f,sizeof a2);

	int q,A,B,lst,now;

	scanf("%d%d%d%d%d",&n,&q,&A,&B,&lst);

	build(1,1,n);

	Mod(A,abs(B-lst));

	Mod(B,abs(A-lst));

	F(i,2,q){

		scanf("%d",&now);

		int tmp1=Qur1(1,1,n,1,now),tmp2=Qur2(1,1,n,now,n);

		ll k=min(a1[tmp1]+now,a2[tmp2]-now)-abs(now-lst);

		Sum+=abs(now-lst);

		if(a[lst]>k) Mod(lst,k);

		lst=now;

	}

	printf("%lld",a[dat[1]]+Sum);

	return 0;

}