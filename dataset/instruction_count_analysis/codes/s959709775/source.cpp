#include<stdio.h>

#include<algorithm>

using namespace std;

#define ll long long

int main()

{

	//freopen("in.txt","r",stdin);

	ll n,k;

	scanf("%lld%lld",&n,&k);

	if(k&1){//ji

		if(k>n)printf("0\n");

		else{

			ll cnt1=(n-k)/k;

			cnt1++;

			printf("%lld",cnt1*cnt1*cnt1);

		}

	}else{

		if(k/2>n)printf("0\n");

		else{

			ll cnt1=0;

			if(k<=n){

		cnt1=(n-k)/k;

			cnt1++;

			}

		ll cnt2=(n-(k/2))/k;

		cnt2++;

		printf("%lld",cnt1*cnt1*cnt1+cnt2*cnt2*cnt2);

		}

	}

}