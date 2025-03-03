#include<stdio.h>

int main()

{

	int a[3]={0};

	int i,j,x;

	int k=0;

	for(i=0;i<3;i++)

	{

	scanf("%d",&x);

	a[i]=x;

	}

	for(i=0;i<2;i++)

	{

		for(j=i+1;j<3;j++)

		{

			if(a[0]==a[1]&&a[1]==a[2])

			k=1;

		 	else if(a[i]!=a[j])

			k++;

			

		}

	}

	printf("%d\n",k);

	return 0;

}