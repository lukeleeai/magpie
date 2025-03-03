#include<stdio.h>

int main()

{

	int n,k,sum=0;

	scanf("%d%d",&n,&k);

	while(1)

	{

		n-=k;

		sum++;

		if(n<=0)break;

		n++;

	}

	printf("%d\n",sum);

}