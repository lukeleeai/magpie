#include<iostream>

#include<cstdio>

#include<cstring>

#include<cmath>

typedef long long ll;

using namespace std;

ll a[200000+50]={0};

int main ()

{

	ll n,i;

	cin>>n;

	for(i=0;i<n;i++)

		cin>>a[i];

	if(a[0]!=0)

	{

		cout<<"-1"<<endl;

		return 0;

	}

	for(i=1;i<n;i++)

	{

		if(a[i]-a[i-1]>1&&a[i]!=1)

		{

			cout<<"-1"<<endl;

			return 0;

		}

	}

	ll ans=0;

	for(i=1;i<n;i++)

	{

		if(a[i-1]<a[i])

			ans+=1;

		else

			ans+=a[i];

	}

	cout<<ans<<endl;

	return 0;

 } 