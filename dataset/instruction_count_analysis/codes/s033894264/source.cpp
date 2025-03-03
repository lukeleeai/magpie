#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<cmath>

#include<iostream>

#include<algorithm>

using namespace std;

long long n,r;

int main()

{

	cin>>n>>r;

	if (n>=10)

	{

		cout<<r<<"\n";

	}

	else

	{

		long long a=100*(10-n);

		a+=r;

		cout<<a<<"\n";

	}

	return 0;

}