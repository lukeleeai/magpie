#include<iostream>

#include<cmath>

using namespace std;

int main()

{

	int n,ce=0,cw=0,an=1e9,a[300003];

	char c[300003];

	cin>>n;

	for(int i=0;i<n;i++)

	{

		cin>>c[i];

		a[i]=cw;

		if(c[i]=='W')cw++;

	}

	for(int i=n-1;i>=0;i--)

	{

		an=min(an,a[i]+ce);

		if(c[i]=='E')ce++;

	}

	cout<<an<<endl;

	return 0;

}