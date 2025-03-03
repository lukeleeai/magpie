#include<iostream>

using namespace std;

int main()

{

	int n,a[1000000],ans=0,t=0,num=0;

	cin>>n;

	for(int i=1;i<=n;i++)

	{

		cin>>a[i];

		if(num>=a[i])

		{

			t++;

			if(t>ans)

			ans = t;

		}

		else if(num<a[i])

		{

			t = 0;

		}

		num = a[i];

	}

	cout<<ans;

	return 0;

}