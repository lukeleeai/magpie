#include<stdio.h>

long long x,y,res;

int main()

{

	scanf("%lld%lld",&x,&y,&res);

	long long i=x;

	while(i<=y)

	{

		res++;

		i<<=1;

	}

	printf("%d\n",res);

	return 0;

}