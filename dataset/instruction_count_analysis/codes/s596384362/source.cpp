#include <stdio.h>



int main ()

{

	int a=0,b=0,c=0;

	scanf("%d %d %d",&a,&b,&c);

	

	if(b-a==c-b)

	{

		printf("YES\n");

	}

	else if (b-a!=c-b)

	{

		printf("NO\n");

	}

	

	

	

	return 0;

}