//#include "stdc++.h"

#include <iostream>

#include <algorithm>

#include <queue>

using namespace std;

typedef long long ll;

ll n,k,ans;

ll sum[1000005],mod=1000000007ll;

ll pow1(ll x,ll y){

	ll a=1,b=x;while(y){if(y&1)a=(a*b)%mod;b=(b*b)%mod;y>>=1;}return a;

}

int main(){

    cin>>n>>k;

    for(int i=k;i>=1;i--){

		sum[i]=pow1(k/i,n);

		for(int j=2;i*j<=k;j++){

			sum[i]=(sum[i]-sum[i*j]+mod)%mod;

		}

		ans=(ans+i*sum[i])%mod;

	}

	cout<<ans;

	//system("pause");

    return 0;

}
