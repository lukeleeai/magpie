#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

using namespace std;

typedef long long ll;



ll prime[1005];

bool is_prime[1005];

ll mod=1000000000+7;

ll sieve(ll n){

	ll p=0;

	for(ll i=0;i<=n;i++) is_prime[i]=true;

	is_prime[0]=is_prime[1]=false;

	for(ll i=2;i<=n;i++){

		if(is_prime[i]){

			prime[p++]=i;

			for(ll j=2*i;j<=n;j+=i) is_prime[j]=false;

		}

	}

	return p;

}

ll a[1005];



int main()

{

	ll n;

	

	

	scanf("%lld",&n);

	ll p=sieve(n);

	memset(a,0,sizeof(a));

	//2for(ll i=0;i<p;i++){

	//	printf("%lld ",prime[i]);

	//}

	//printf("\n");

	for(ll i=1;i<=n;i++){

		ll k=i;

		while(1){

			if(k==1) break;

			for(ll j=0;j<p;j++){

				if(k%prime[j]==0){

					a[prime[j]]++;

					k/=prime[j];

				

				}

			}

		}

		

	}

	//for(ll i=1;i<=n;i++){

	//	printf("%lld ",a[i]);

	//}

	//printf("====\n");

	ll res=1;

	

	for(ll i=1;i<=n;i++){

		res*=a[i]+1;

		res%=mod;

		//res=res%mod*(a[i]+1)%mod;

	}

	printf("%lld\n",res);

	

	

	

	return 0;

}