#include<iostream>

#include<string>

#include<algorithm>

#include<string.h>

using namespace std;

#define ll long long 

int main()

{

	ll n;

	cin>>n;

	ll a[111111];

	for(int i=0;i<n+1;i++)

	{

		cin>>a[i];

	}

	ll sum=0;

	ll b;

	for(int i=0;i<n;i++)

	{

		cin>>b;

		if(b>=a[i])

		{

			sum+=a[i];

			b-=a[i];

			if(b>=a[i+1])

			{

				sum+=a[i+1];

				a[i+1]=0;

			}

			else

			{

				sum+=b;

				a[i+1]-=b;

			}

		}

		else

		{

			sum+=b;

		}

	}

	cout<<sum<<endl;

	return 0;

}
