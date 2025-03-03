#include<stdio.h>

int main()

{

	int N, D;

	scanf("%d %d",&N, &D);

	int fanwei;

	fanwei = D*2+1;

	int i;

	for( i = 0; N>0; i++)

	{

		N = N-fanwei;

	}

	printf("%d",i);

}