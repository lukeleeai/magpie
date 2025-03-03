#include<stdio.h>

int main()

{

	int N,x,y,s,a;

	1<=N<=100;

	scanf("%d",&N);

	s=N/15;

	x=800*N;

	y=200*s;

	a=x-y;

	printf("%d",a);

	return 0;

}