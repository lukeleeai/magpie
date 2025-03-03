#include <stdio.h>

long long gcd(long long a,long long b)

{

	long long n=a%b;

	while(n!=0)

	{

		a=b;

		b=n;

		n=a%b;

	}

	return b;

}

int main()

{

	long long i,n,m;

    long long ans=1;

	scanf("%lld",&n);

	for(i=0;i<n;i++)

	{

		scanf("%lld",&m);

		ans=ans/gcd(ans,m)*m;

	}

	printf("%lld\n",ans);

}