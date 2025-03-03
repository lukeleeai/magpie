#include <stdio.h>



int main()

{

	int A,B;

	scanf("%d%d",&A,&B);

	if((A==2&&B==3)||(A==3&&B==2))

	{

		printf("1");

	}

	if((A==1&&B==2||A==2&&B==1))

	{

		printf("3");

	}

	if((A==3&&B==1||A==1&&B==3))

	{

		printf("2");

	}

	return 0;

}