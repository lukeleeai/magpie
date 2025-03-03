#include"stdc++.h"

using namespace std;

typedef long long ll;

const int N=1E5+7;

ll arr[N];

const int MOD=998244353;

ll ksm(ll x, ll y){

	ll res=1;

	while(y){

		if(y&1) res=res*x%MOD;

		x=x*x%MOD;

		y>>=1;

	}

	return res%MOD;

}



int main(){

	ll n;

	cin>>n;

	ll sum=1;

	ll x;

	ll s=0;

	for(int i=1;i<=n;i++){

		cin>>x;

		if(i==1&&x!=0) sum=0;

		arr[x]++;

		s=max(s,x);

	}

	for(int i=s;i>=0;i--){

		if(arr[i]==0) sum=0;

		if(i>1)	sum=sum*ksm(arr[i-1],arr[i])%MOD;

	}

	if(arr[0]>1) sum=0;

	printf("%lld\n",sum);

	

	return 0;

}