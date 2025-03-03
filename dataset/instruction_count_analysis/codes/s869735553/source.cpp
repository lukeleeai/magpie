#include<stdio.h>

int main()

{

	int a;

	scanf("%d",&a);

	if(a<1200){

		printf("ABC\n");

	}

	else if(a<2800){

		printf("ARC\n");

	}

	else{

		printf("AGC\n");

	}

	return 0;

}