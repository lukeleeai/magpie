#include <stdio.h>



int main()

{

	int a,b;

	scanf("%d", &a);

	if(a%1000==0){

		printf("0");

	}

	if(a%1000!=0){

		b=a%1000;

		printf("%d", 1000-b);

	}

	return 0;

}