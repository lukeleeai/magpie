#include <stdio.h>



int main(){

	int a, b;

	scanf("%d %d", &a, &b);

	a = a * (a - 1) / 2;

	b = b * (b - 1) / 2;

	printf("%d", a + b);

	return 0;

}