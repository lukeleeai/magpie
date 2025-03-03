#include<stdio.h>

int main()

{

	int A,B,C,k;

	int i=0;

	int sum1,sum2,sum3;

	scanf("%d %d %d",&A,&B,&C);

	scanf("%d",&k);

	int A1[k];

	int p=k;

	while(k--)

	{



		sum1=A*2+B+C;

		sum2=A+B*2+C;

		sum3=A+B+C*2;

		if(sum1>=sum2 && sum1>=sum3 )

		{

			A=A*2;

			A1[i]=sum1;

			//printf("%d",sum1);

		}

		else if(sum2>=sum1 && sum2>=sum3)

		{

			B=B*2;

			A1[i]=sum2;

			//printf("%d",sum1);

		}

		else if(sum3>=sum1 && sum3>=sum2)

		{

			C=C*2;

			A1[i]=sum3;

			//printf("%d",sum1);

		}

		else if(sum1==sum2 && sum2==sum3)

		{

			A=A*2;

			A1[i]=sum1;

		}

		i++;

	}

	i=0;

	int max=0;

	while(i<p)

	{

		if(A1[i]>max)

		{

			max=A1[i];

		}

		i++;

	}

	printf("%d\n",max);

}