#include<stdio.h>



int main()

{

	int n,a,b;

	scanf("%d%d%d",&n,&a,&b);

	int s = n*a;

	int y = b<s?b:s;

	printf("%d\n",y);

	return 0;

}