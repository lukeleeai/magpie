#include<iostream>

#include<cstdio>

#include<stack>

#include<cmath>

#include<cstring>

using namespace std;



int a[55];

int main()

{

	int n;

	while(cin>>n)

	{

		memset(a,0,sizeof(a));

		for(int i=0;i<n;i++)

		{

			cin>>a[i];

		}

		long long int sum=0;

		for(int i=0;i<n;i++)

		{

			for(int j=i+1;j<n;j++)

			{

				sum+= a[i]*a[j];

			}

		}

		cout<<sum<<endl;

	}

}