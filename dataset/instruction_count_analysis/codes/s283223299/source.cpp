#include "stdc++.h"



using namespace std;

typedef unsigned long long ll;

const int mod=1e9+7;

int a[20010];

int main()

{

	ll n,k;

	scanf("%lld %lld",&n,&k);

	ll cot=0; 

	for(int i=0;i<n;i++)

	{

		scanf("%d",&a[i]);

	}

	for(int i=0;i<n;i++)

	{

		for(int j=i+1;j<n;j++)

		{

			if(a[i]>a[j]) cot++;

		}

	}

	ll cnt=0;

	for(int i=0;i<n;i++)

	{

		for(int j=0;j<i;j++)

		{

			if(a[j]<a[i]) cnt++;

		}

	} 

	ll sum=0;

	ll kk=k*(k+1)/2;

	if(kk==1) cout <<cot;

	else

	{

		ll kkk=(k-1)*(k)/2;

		sum=cot%mod*(kk%mod)%mod+cnt%mod*(kkk%mod)%mod;

		cout <<sum%mod<<endl;

	}

	return 0;

}
