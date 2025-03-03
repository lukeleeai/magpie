#include<iostream>

#include<cstdio>

#include<cmath>

#include<cstring>

#include<string>

#include<iomanip>

using namespace std;

int main()

{

	int a,b;

	int sum=0;

	cin>>a>>b;

	if(a<=0&&b>=0)

	{

		cout<<"Zero"<<endl;

	}

	else if(a>0&&b>0)

	{

		cout<<"Positive"<<endl;

	}

	else if(a<0&&b<0)

	{

		sum=b-a+1;

		if(sum%2==0) cout<<"Positive"<<endl;

		else cout<<"Negative"<<endl;

	}

	return 0;

}