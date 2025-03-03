#include"stdc++.h"

#define ll long long

using namespace std;

ll n,m,jc[1000010],ny[1000100],ans,p=998244353;

ll C(ll x,ll y){

	return jc[x]*ny[y]%p*ny[x-y]%p;

}

ll ksm(ll x,ll y){

	ll xlh=1;

	while(y){

		if(y&1)xlh=xlh*x%p;

		x=x*x%p;

		y/=2;

	}

	return xlh;

}

int main(){

	ll i,xlh;

	scanf("%lld%lld",&n,&m);

	if(n>m)swap(n,m);

	jc[0]=ny[0]=1;

	for(i=1;i<=m;i++)jc[i]=jc[i-1]*i%p,ny[i]=ksm(jc[i],p-2);

	for(i=0;i<=n;i++){

		xlh=C(n,i)*C(m,i)%p*jc[i]%p*ksm(n+1,m-i)%p*ksm(m+1,n-i)%p;

		if(i%2)ans=(ans-xlh+p)%p;

		 else ans=(ans+xlh)%p;

	}

	printf("%lld",ans);

}

/*

仔细想想不难，但感觉这种容斥确实非常奇怪。 

*/