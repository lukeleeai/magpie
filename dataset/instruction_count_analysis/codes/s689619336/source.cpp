#include<iostream>

#include<iomanip>

#include<string.h>

using namespace std;

int main()

{

	int x,n=0;

	long long sum=2;

	cin>>x;

	do

	{

		sum=sum+1+(sum+1);

		n=n+1;

	}

	while(n<x);

	cout<<sum;

	return 0;

}