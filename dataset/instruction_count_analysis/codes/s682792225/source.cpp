#include<iostream>

#include<cstdio>

#include<algorithm>

using namespace std;

int main()

{

	int n,m;

	while(cin>>n>>m)

	{

		int a[100000]={0};

		int b[100000],c[100000];

		for(int i=0;i<m;i++)

		{

			cin>>b[i]>>c[i];

		}

		for(int i=0;i<m;i++)

		{

			a[b[i]]++;

			a[c[i]]++;

		}

		int flag=1;

		for(int i=0;i<n;i++)

		{

			if(a[i]%2!=0)

				flag=0;

		}

		if(flag==1)

			cout<<"YES\n";

		else

			cout<<"NO\n";

	}

}