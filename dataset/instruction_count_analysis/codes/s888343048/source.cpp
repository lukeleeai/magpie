#include<iostream>

#include<cstdio>

#include<cmath>

using namespace std;

long long f[100];

int main()

{

	long long n;

	cin>>n;

	f[0]=2;

	f[1]=1;

	for(int i=2;i<=100;i++)

	f[i]=f[i-1]+f[i-2];

	cout<<f[n]<<endl;

	return 0;

}