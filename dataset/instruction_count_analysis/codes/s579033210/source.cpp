#include<stdio.h>



int main()

{

	int a,b,d,e,f;

	scanf("%d %d",&a,&b);

	d=a+b;e=a-b;f=a*b;

	

	if(d>=e&&d>=f)

	{

		printf("%d\n",d);

	}

	

	else if(e>=d&&e>=f)

	{

		printf("%d\n",e);

	}

	

	else if(f>=d&&f>=e)

	{

		printf("%d\n",f);

	}

	return 0;

}