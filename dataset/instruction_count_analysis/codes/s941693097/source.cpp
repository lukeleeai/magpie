#include<stdio.h>

#include<string.h>

#include<algorithm>

#define mem(a) memset(a,0,sizeof(a))

using namespace std;

int F[1005][500];

void Fib()

{

	int i,j;

	mem(F);

	F[0][0]=2;

	F[1][0]=1;

	for(i=2;i<1005;i++)

	{

		for(j=0;j<500;j++)

		F[i][j]=F[i-1][j]+F[i-2][j];

		for(j=0;j<500;j++)

		{

			if(F[i][j]>9)

			{

				F[i][j+1]+=F[i][j]/10;

				F[i][j]=F[i][j]%10;

			}

		}

	}

}

int main()

{

	int i,j,flag,N,n;

	Fib();

	

		scanf("%d",&n);

		flag=0;

		for(j=499;j>=0;j--)

		{

			if(flag==1||F[n][j])

			{

				flag=1;

				printf("%d",F[n][j]);

			}

		}

		printf("\n");

	 return 0;

}