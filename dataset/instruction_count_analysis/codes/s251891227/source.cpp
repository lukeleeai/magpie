#include<iostream>

#include<string.h>

#include<algorithm>

using namespace std;

int a[100010];

int main ()

{

	int n;

	cin>>n;

	memset(a,0,sizeof(a));

	int sum=0;

	for(int i=1;i<=n;i++)

	{		

		cin>>a[i];

	} 

	sort(a+1,a+1+n);

	for(int i=1;i<n;i++)

	{

		if(a[i]==a[i+1])

		{

			a[i]=0;

			a[i+1]=0;

		}

		

		

		

	}

	for(int i=1;i<=n;i++)

	{

		if(a[i]!=0)

		{

			sum++;

		}

	}

	

	

	

	

	

	

	cout<<sum<<endl;	

 } 