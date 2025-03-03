#include<stdio.h>

#include<cmath>

using namespace std;

#define mod 1000000007

#define MOD(x) ((x)%mod)

long long n,m;

long long ans(long long x)

{

	long long a=1;

	for(long long i=1;i<=x;i++)

		a=MOD(a*i);

	return a;

}

int main()

{

	scanf("%lld%lld",&n,&m);

	if(abs(n-m)>=2)

	{

		printf("0");

	}

	else if(abs(n-m)==1)

	{

		printf("%lld",MOD(ans(n)*ans(m)));

	}

	else

	{

		printf("%lld",MOD(ans(n)*ans(m)*2));

	}

	return 0;

}