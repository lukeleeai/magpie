#include <iostream>

#include <stdio.h>

#include <string.h>

#include <string>

#include <list>

#include <map>

#include <vector>

#include <algorithm>

#include <cmath>

using namespace std;

long long gcd(long long a,long long b)

{

	if(a==0)return b;

	return gcd(b%a,a);

}

long long m,n, mn;

long long s[1266],ind,gd;

int main()

{

	while(cin>>n&&n)

	{

		m=(n+1)*n/2;

		double mn;

		ind=0;

		mn=1e100;

		for(int i=0;i<m;i++)

		{

			long long z;

			scanf("%lld",&z);

			if(z>(1LL<<62))while(1);

			if(z%2==0)

				s[ind++]=z;

			else mn=min(mn,z+0.0);

		}

		sort(s,s+ind);

		if(ind!=n)while(1);

		long long da=sqrt(s[0]*1.0*s[1]/mn)+0.5;



		cout<<da<<endl;

		//if(da==0)continue;

		for(int i=0;i<n;i++)

		{

			if(i)cout<<' ';

			cout<<s[i]/da;

		}cout<<endl;

	}

}