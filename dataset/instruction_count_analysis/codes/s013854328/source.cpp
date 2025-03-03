#include"stdc++.h"

using namespace std;

#define ll long long

const int maxn=200000+100;



ll n,m,q,t[maxn<<2],x,y,z;

/*

ll low(ll x){

	return x&(-x);

}

ll query(ll x){

	ll res=0;

	for(;x>0;x-=low(x))res+=t[x];

	return res;

}

void updata(ll x,ll k){

	for(;x<=n;x+=low(x))t[x]+=k;

}*/



int main(){

	scanf("%lld%lld%lld",&n,&m,&q);

	memset(t,0,sizeof(t));

	for(int i=0;i<q;i++){

		scanf("%lld",&x);

		t[x]++;

	}

	for(int i=1;i<=n;i++){

		int k=t[i]+m-q;

		if(k<=0)printf("No\n");

		else printf("Yes\n");

	}

}