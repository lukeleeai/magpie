#include<cstdio>

#include<cstring>

#include<iostream>

#include<algorithm>

using namespace std;

typedef long long ll;



ll mod_pow(ll x,ll n,ll mod){

	ll res=1;

	while(n>0){

		if(n&1) res=res*x%mod;

		x=x*x%mod;

		n>>=1;

	}

	return res;

}

int a[100005];

int main()

{

	int n;

	ll mod=1000000000+7;

	while(~scanf("%d",&n)){

		for(int i=0;i<n;i++)

			scanf("%d",&a[i]);

		sort(a,a+n);

		int flag=1;

		if(n%2==1){

			if(n==1){

				if(a[0]==0){

					

				}else{

					flag=0;

				}

			}

			for(int i=1;i<n;i++){

				if(i%2==1){

					if(a[i]==a[i-1]+2){

						

					}else{

						flag=0;

					}

				}else{

					if(a[i]==a[i-2]+2){

						

					}else{

						flag=0;

					}

				}

			}

		}else{

			if(a[0]!=a[1]) flag=0;

			if(a[0]!=1) flag=0;

			for(int i=2;i<n;i++){

				if(i%2==0){

					if(a[i]==a[i-1]+2){

						

					}else{

						flag=0;

					}

				}else{

					if(a[i]==a[i-2]+2){

						

					}else{

						flag=0;

					}

				}

			}

			

		}

		ll l=n/2;

		if(flag==0){

			printf("0\n");

		}else{

			printf("%lld\n",mod_pow(2,l,mod));

			

			

			

		}

	}

	

	return 0;

}