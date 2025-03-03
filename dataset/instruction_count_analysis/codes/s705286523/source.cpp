#include"stdc++.h"

#define N 111111

#define M 444444

#define LL long long

using namespace std;

int n,i,k,j,a[N];LL f[N],V1[M],V2[M],E,T;

void ins(int k,int l,int r,int x,LL z1,LL z2){

	if(l==r){V1[k]=z1;V2[k]=z2;return;}

	int md=l+r>>1;

	if(x<=md)ins(k<<1,l,md,x,z1,z2);else ins(k<<1|1,md+1,r,x,z1,z2);

	V1[k]=min(V1[k<<1],V1[k<<1|1]);

	V2[k]=min(V2[k<<1],V2[k<<1|1]);

}

LL qu1(int k,int l,int r,int x,int y){

	if(x>y)return 1e18;

	if(x<=l&&r<=y)return V1[k];

	int md=l+r>>1;

	if(y<=md)return qu1(k<<1,l,md,x,y);

	if(x>md)return qu1(k<<1|1,md+1,r,x,y);

	return min(qu1(k<<1,l,md,x,y),qu1(k<<1|1,md+1,r,x,y));

}

LL qu2(int k,int l,int r,int x,int y){

	if(x>y)return 1e18;

	if(x<=l&&r<=y)return V2[k];

	int md=l+r>>1;

	if(y<=md)return qu2(k<<1,l,md,x,y);

	if(x>md)return qu2(k<<1|1,md+1,r,x,y);

	return min(qu2(k<<1,l,md,x,y),qu2(k<<1|1,md+1,r,x,y));

}

int main(){

	for(i=0;i<M;i++)V1[i]=V2[i]=1e18;

	scanf("%d%lld%lld",&n,&E,&T);

	for(i=1;i<=n;i++)scanf("%lld",&a[i]);

	for(i=0,k=0;i<=n;i++){

		f[i]=1e18;

		for(;(a[i]-a[k+1])*2>T&&k<i;k++);

		//f[i]=f[k]+max(a[i]-a[k+1]+a[i]-a[k+1],T)+a[i]-a[k];

		//j<=k a[i]-a[j+1*2>T

		//f[i]=qu2(1,0,0,k)

	//	printf("%d %d\n",(a[i]-a[k+1])*2,T);

		if(i==0)f[i]=0;else 

		f[i]=min(qu1(1,0,n,k,i-1)+T+a[i],qu2(1,0,n,0,k-1)+1ll*a[i]*3);

		//printf("%lld %lld\n",qu1(1,0,n,k,i-1)+T+a[i],qu2(1,0,n,0,k-1)+1ll*a[i]*3);

		//printf("%d %d %lld\n",i,k,f[i]);

	//	printf("%lld %lld %d\n",qu1(1,0,n,k,i-1),qu2(1,0,n,0,k-1),T+a[i]);

		//puts("-----------------------");

			//f[i]=min(f[i],f[j]+a[i]-a[j]+max((a[i]-a[j+1])*2,T));

		

		ins(1,0,n,i,f[i]-a[i],f[i]-a[i]-a[i+1]*2);

	}

	printf("%lld\n",f[n]+E-a[n]);

}