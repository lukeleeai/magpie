#include<stdio.h>

#include<stdlib.h>

#pragma warning(disable:4996)

int main()

{

	int n, d[105],s=0;

	scanf("%d",&n);

	for(int i=0;i<n;i++)scanf("%d",&d[i]);

	for(int i=0;i<n;i++)

	{

		for(int j=i+1;j<n;j++)

		{

			s+=d[i]*d[j];

		}

	}

	printf("%d",s);

	return 0;

}