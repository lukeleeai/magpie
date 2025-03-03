#include<stdio.h>

int main()

{

	long long max,sum,a,b,c;

	while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)

	{

		max=a>b?a:b;

		max=max>c?max:c;

		sum=(max-a)+(max-b)+(max-c);

		if(sum%2==0)

		printf("%lld\n",sum/2);

		else

		{

			printf("%lld\n",sum/2+2);

		}

	}

	return 0;

 } 