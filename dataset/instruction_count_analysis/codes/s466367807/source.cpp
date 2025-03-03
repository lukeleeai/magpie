#include<stdio.h>

int main()

{	int n;

	scanf("%d",&n);

	if(n==1) printf("1\n");

	else if(n<=3) printf("2\n");

	else if(n<8) printf("4\n");

	else if(n<16) printf("8\n");

	else if(n<32) printf("16\n");

	else if(n<64) printf("32\n");

	else if(n<101) printf("64\n");

	return 0;

}