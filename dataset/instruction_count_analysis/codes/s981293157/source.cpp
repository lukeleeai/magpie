#include<stdio.h>

int main()

{

    int N,i,j;

	int sum=0;

	scanf("%d",&N);

    for(i=0;i<=25;i++)

	{

		for(j=0;j<=14;j++)

		{

            if(i*4+j*7==N)

			{

				sum=1;

			}

		}

	}

	if(sum==1)

	{

		printf("Yes\n");

	}

	if(sum==0)

	{

		printf("No\n");

	}

	return 0;

}