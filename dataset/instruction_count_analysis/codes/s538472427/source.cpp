#include<stdio.h>

int main()

{

	char a[4];

	scanf("%s",a);

	bool flag=1;

	for(int i=0;i<3;i++)

	{

		if(a[i]==a[i+1])

		{

			flag=0;

			break;

		}

	}

	if(flag)

	{

		printf("Good\n");

	}

	else

	{

		printf("Bad\n");

	}

}