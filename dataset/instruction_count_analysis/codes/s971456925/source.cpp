#include<iostream>

#include<cstdio>

#include<cmath>

using namespace std;

long long a[100002],n,m,p=1e9+7;

long long ksm(int a,int b,int p)

{

	long long ans=1;

	while(b)

	{

		if(b&1)

		{

			ans=ans*a%p;

		}

		a=a*a%p;

		b>>=1;

	}

	return ans;

}

long long c(long long n,long long m)

{

	if(m>n)

	{

		return 0;

	}

	return (((a[n]*ksm(a[m],p-2,p))%p*ksm(a[n-m],p-2,p))%p);

}

long long lucas(long long n,long long m)

{

	if(m==0)

	{

		return 1;

	}

	return (c(n%p,m%p)*lucas(n/p,m/p))%p;

}

int main()

{

	cin>>n>>m;

	if(abs(n-m)>1)

	{

		cout<<"0"<<endl;

		return 0;

	}

	a[0]=1;

	for(int i=1;i<=max(n,m);i++)

	{

		a[i]=(a[i-1]*i)%p;

	}

	if(n==m)

	{

		cout<<(2*a[n]*a[m])%p<<endl;

	}

	if(abs(n-m)==1)

	{

		cout<<(a[n]*a[m])%p<<endl;

	}

}