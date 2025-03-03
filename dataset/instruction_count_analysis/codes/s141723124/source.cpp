#include<stdio.h>

int main()

{

	long long int n,m;

	int t=0;

	m=100;

	scanf("%lld",&n);

	while(m<n)

	{

		m=m*1.01;

		t++;

	}

	printf("%d",t);

}