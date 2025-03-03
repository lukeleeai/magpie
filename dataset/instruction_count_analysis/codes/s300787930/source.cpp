#include<stdio.h>

#include<math.h>

int a[100][20]={0};

int main()

{

	int n,m,i,j,t;

	scanf("%d %d",&n,&m);

	for(i=0;i<n;i++)

	{

		for(j=0;j<m;j++)

		scanf("%d",&a[i][j]);

	}

	int sum;

	sum=0;

	for(i=0;i<n;i++)

	{

		for(j=i+1;j<n;j++)

		{

//			printf("1\n");

			double s=0;

			for(t=0;t<m;t++)

			{

				s+=((a[i][t]-a[j][t])*(a[i][t]-a[j][t]));

//				printf("2\n");

			}

			

			s=sqrt(s);

			int mu=s;

			if(s-mu==0)

			sum++;

		}

	}

	printf("%d\n",sum);

 } 