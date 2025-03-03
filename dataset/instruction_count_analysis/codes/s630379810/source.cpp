#include <stdio.h>

int main ()

{

	long long N,K,Q,i,B[100000],c[100000];

	scanf("%lld %lld %lld",&N,&K,&Q);

	

	for(i=0;i<N;i++)

	{

		c[i]=K-Q;

	}

	for(i=0;i<Q;i++)

	{

		scanf("%lld",&B[i]);

		c[B[i]-1]+=1;

	}

	for(i=0;i<N;i++)

	{

		if(c[i]>0)

		{

			printf("Yes\n");

		}

		else

		{

			printf("No\n");

		}

	}

	return 0;

}