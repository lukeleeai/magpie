#include<stdio.h>

#define size 115

int main()

{

	int N,max=-1,i,l[size],total=0;

	scanf("%d",&N);

	if(N>=3)

	{

	for(i=0;i<N;i++)

		{

			scanf("%d",&l[i]);

			total+=l[i];

		}

	for(i=0;i<N;i++)

		{

			if(l[i]>max&&l[i]>0)

				{

					max=l[i];

				}

			else

				{

					

				}

			

		}

		total-=max;

	if(max<total)

		{

			printf("Yes\n");

		}

	else

		{

			printf("No\n");

		}

	}

	else

		{

			printf("No\n");

		}

	return 0;

}