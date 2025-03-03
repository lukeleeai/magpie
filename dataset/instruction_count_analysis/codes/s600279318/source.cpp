#include"stdc++.h"

using namespace std;

typedef long long ll;

const ll mod=1e9+7;

ll a[2222];

ll b[2222];

int main()

{

	//ios::sync_with_stdio(flase);

	ll n,k;

	cin>>n>>k;

	for(int i=0;i<n;i++)

	{

		scanf("%lld",&a[i]);

	}

	

	for(int i=0;i<n;i++)

	{

		for(int j=0;j<n;j++)

		{

			if(a[i]>a[j])

				b[i]++;

		}

	}

	ll sum=0;

	ll cnt=0;

	cnt=k%mod*((k-1)%mod)/2%mod;



		

	for(int i=0;i<n;i++)

	{

		sum=sum+(b[i]%mod)*((cnt)%mod)%mod;

	}

	ll sum1=0;

	for(int i=0;i<n;i++)

	{

		for(int j=i+1;j<n;j++)

		{

			if(a[i]>a[j])

				sum1++;

		}

	}

	sum1=k%mod*(sum1%mod)%mod;

	sum=(sum+sum1)%mod;

	cout<<sum%mod<<endl;

	return 0;

}