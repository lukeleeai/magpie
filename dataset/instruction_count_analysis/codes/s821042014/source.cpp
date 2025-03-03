#include<stdio.h>

long long gcd(long long a,long long b)

{ return b?gcd(b,a%b):a;}



long long lcm(long long a, long long b)

{ return a/gcd(a,b)*b;}



int main()

{

	long long n,x,y;

	scanf("%lld%lld",&n,&x);

	n--;

	while(n--)

	{

		scanf("%lld",&y);

		x=lcm(x,y);

	}

	printf("%lld\n",x);

}