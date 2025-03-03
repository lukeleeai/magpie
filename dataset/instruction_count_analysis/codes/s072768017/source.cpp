#include"stdc++.h"

#define ll long long

using namespace std;

const ll p=998244353;

ll n,m,ans,jc[1000010],ny[1000010];

ll ksm(ll x,ll y){

	ll xlh=1;

	while(y){

		if(y&1)xlh=xlh*x%p;

		x=x*x%p;

		y/=2;

	}

	return xlh;

}

ll C(ll x,ll y){

	return jc[x]*ny[y]%p*ny[x-y]%p;

}

int main(){

	ll i,op;

	scanf("%lld%lld",&n,&m);

	jc[0]=ny[0]=1;

	for(i=1;i<=max(n,m);i++)jc[i]=jc[i-1]*i%p,ny[i]=ksm(jc[i],p-2)%p;

	for(i=0;i<=min(n,m);i++){

		if(i%2)op=-1;

		 else op=1;

		ans=(ans+op*C(n,i)%p*C(m,i)%p*jc[i]%p*ksm(n+1,m-i)%p*ksm(m+1,n-i)%p+p)%p;

	}

	printf("%lld",ans);

}