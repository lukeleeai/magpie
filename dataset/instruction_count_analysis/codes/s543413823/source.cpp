#include<stdio.h>

int main(){

	int num1, num2, num3;

	scanf("%d %d %d", &num1, &num2, &num3);

	(num1+num2+num3>=22)?puts("bust"):puts("win");

	return 0;

}