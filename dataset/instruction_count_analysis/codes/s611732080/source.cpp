#include<stdio.h>

long long a[100009]={0},l,i,n,m,p;

int main()

{

	

	scanf("%lld",&n);

	for(i=1;i<=n;i++)

	{

		scanf("%lld",&m);

		a[m]++;

		

	}

	if(n%2==1)

	{

		if(a[0]==1)p=1;

		else  {

		printf("0");	return 0;

		}

		for(i=2;i<=n;i=i+2)

		{

			if(a[i]==2)p=(p*2)%1000000007;

			else {

				printf("0");

				return 0;

			}

		}

		

	}

	else {

		p=1;

		for(i=1;i<=n;i=i+2)

		{

			if(a[i]==2)p=(p*2)%1000000007;

			else {

				printf("0");

				return 0;

			}

		}

	}

	printf("%lld",p);

}