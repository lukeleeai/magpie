#include<stdio.h>

int main()

{

	long long n,m;

	int s;

	s=0;

	scanf("%lld",&n);

	m=n;

	while(n)

	{

		s+=n%10;

		n=n/10;

	}

	if(m%s==0) printf("Yes\n");

	else printf("No\n");

	return 0;

}