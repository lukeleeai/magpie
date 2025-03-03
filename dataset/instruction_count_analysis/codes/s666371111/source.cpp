#include <iostream>

#include <cstdio>

using namespace std;

const int mo=1e9+7;

int fac[200001],x[100001],y[100001];

int pow(int x,int n){

	int t=1,y=x;

	while (n){

		if (n&1) t=1ll*t*y%mo;

		y=1ll*y*y%mo;

		n>>=1;

	}

	return t;

}

int main(){

	int h,w,a,b,i,j,m,ans=0;

	scanf("%d%d%d%d",&h,&w,&a,&b);

	m=h+w;

	fac[0]=1;

	for (i=1;i<=m;++i) fac[i]=1ll*fac[i-1]*i%mo;

	for (i=b+1;i<=w;++i){

		x[i]=1ll*fac[h-a+i-2]*pow(1ll*fac[i-1]*fac[h-a-1]%mo,mo-2)%mo;

		y[i]=1ll*fac[a+w-i-1]*pow(1ll*fac[a-1]*fac[w-i]%mo,mo-2)%mo;

		ans=(ans+1ll*x[i]*y[i]%mo)%mo;

	}

	printf("%d\n",ans);

	return 0;

}