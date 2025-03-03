#include<iostream>

using namespace std;

int main()

{

	int a,b,c;

	cin>>a>>b>>c;

	if(a>b)

	{

		int d=a;

		a=b;

		b=d;

	}

	if(a>c)

	{

		int d=a;

		a=c;

		c=d;

	}

	if(b>c)

	{

		int d=b;

		b=c;

		c=d;

	}

	if(a+b+c==5||a+b+c==7||(a+b==5&&c==7)||(a+b==5&&c==5)||(a+b==7&&c==5)||(a+b==7&&c==7)||(a==5&&b==5&&c==7)||(a==5&&c==5&&b==5))

	{

		cout<<"YES"<<endl;

	}

	else

	{

		cout<<"NO"<<endl;

	}

	

 } 