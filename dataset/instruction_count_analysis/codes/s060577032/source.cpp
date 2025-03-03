#include<stdio.h>

int main()

{

	long long w,h,x,y;

	while(~scanf("%lld%lld%lld%lld",&w,&h,&x,&y))

	{

		printf("%.6lf ",(double)(w*h)/2.0);

		double xx=w*1.0/2.0;

		double yy=h*1.0/2.0;

		if((xx==x)&&(yy==y))

		{

			printf("1\n");

	    }

		else

		{

			printf("0\n");

		}

	}

	return 0;

}