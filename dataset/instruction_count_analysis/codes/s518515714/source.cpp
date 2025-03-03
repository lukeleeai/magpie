#include<stdio.h>

#include<math.h>

bool flag[1000000];

int main(void)

{

	long long i,j,p,n,count;

	p = (long long)sqrt(1000000.0);

	for(i = 3; i <= p; i = i + 2)

	{

		if(flag[i] == false)

		{

			for(j = i * i; j <= 1000000; j = j + 2 * i)

			{

				flag[j] = true;

				

			}

		}

	}

		

	while((scanf("%lld",&n)) != EOF)

	{

		

		if(n == 1 || n == 0)

			count = 0;

		else

		{

			count = 1;

			for(i = 3; i <= n; i = i + 2)

			{

				if(flag[i] == false)

					count++;

			}

		}

		printf("%lld\n",count);

	}

	



		

	return 0;

}