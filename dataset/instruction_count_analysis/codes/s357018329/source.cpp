#include<stdio.h>

int main()

{

	long int x,n=2;

	int i;

	scanf("%d",&x);

	for(i=0;i<x;i++)

		n=(n+1)*2;

	printf("%ld",n);

	return 0;

}