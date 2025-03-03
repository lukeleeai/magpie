#include"stdc++.h"

using namespace std;

#define ll long long

ll rk(ll k){

	ll s=1;

	for(ll i=1;i<=k;i++) s*=10;

	return s;

}

bool pan(ll k, ll fir, ll las, ll per){

	ll r=k, s=0, s1=0;

	while(r) s+=r%10, r/=10;

	for(ll i=fir;i<=las;i+=per){

		r=i, s1=0;

		while(r) s1+=r%10, r/=10;

		if(i>k&&s1*k>s*i) return 0;

	}

	return 1;

}

int main(){

	ll k;

	cin>>k;

	/*for(ll i=1;i<=min(9LL, k);i++) cout<<i<<endl;

	k-=9;

	for(ll i=1;i<=min(9LL, k);i++) cout<<i<<9<<endl;

	k-=9;

	if(k<=0) return 0;*/

	ll f=0;

	for(ll i=1;i<=15;i++){

		ll fir=rk(i-1)+f;

		if(i>2) f=f*10+9;

		ll per=max(1LL,rk(i-3)), las=rk(i);

		for(ll j=fir;j<las;j+=per){

			if(k&&pan(j, fir, las+1, per)) {

				printf("%lld\n", j);

				k--;

			}

		}

		if(!k) return 0;

	}

	//cout<<maxn<<" "<<k;

}
