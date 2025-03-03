#include<iostream>

#include<string.h>

#include<cmath>

using namespace std;

int n;

int main()

{

	int m,sum=0;

	cin>>n>>m;

	if(n<=0&&m>=0)

	{

		cout<<"Zero"<<endl;

		return 0;

	}

	for(int i=n;i<=m;i++)

	{

		if(i<0)

		sum++;

	}

	if(sum%2!=0)

	{

		cout<<"Negative"<<endl;

	}

	else

	{

		cout<<"Positive"<<endl;

	} 

	return 0;

}