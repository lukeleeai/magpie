#include<iostream>

using namespace std;

int n,a[100010],b,ans;

int main()

{

	cin>>n;

	for(int i=0;i<n;i++)

	{

		cin>>b;

		if(b>100000)

		  ans++;

		else a[b]++;

	}

	for(int i=0;i<100001;i++)

	{

		if(a[i]>=i)

		  ans+=a[i]-i;

		else ans+=a[i];

	}

	cout<<ans;

}