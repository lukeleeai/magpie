#include <stdio.h>

#include <string.h>



#define INT_MAX 2147483647

#define INT_MIN -2147483648



int max(int a, int b);

int min(int a, int b);

int abs(int a);



int main() {

	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d\n", (3 * a + b) / 2);

	return 0;

}



void swap(int *a, int *b) {

	int temp = *a;

	*a = *b;

	*b = temp;	

}



int max(int a, int b) {

	return (a > b) ? a : b;

}



int min(int a, int b) {

	return (a < b) ? a : b;

}



int abs(int a) {

	return (a < 0) ? -a : a;

}
