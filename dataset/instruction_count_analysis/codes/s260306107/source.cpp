#include<iostream>

using namespace std;

int n,a[10002],m,b,c,d,e;

int main()

{

	cin>>n;

	for(int i=1;i<=n;i++)cin>>a[i];

	cin>>m;

	for(int i=1;i<=m;i++)

	{

		d=0;

		cin>>b>>c;

		e=a[b];a[b]=c;

		for(int j=1;j<=n;j++)

		{

			d+=a[j];

		}

		cout<<d<<endl;

		a[b]=e;

	}

	return 0;

}//AC