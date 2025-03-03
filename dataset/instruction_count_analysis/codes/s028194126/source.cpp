#include <stdio.h>

#include <string.h>



#define INT_MAX 2147483647

#define INT_MIN -2147483648



int max(int a, int b);

int min(int a, int b);

int abs(int a);



int main() {

	int n;

	scanf("%d", &n);



	int flag = 0;

	for(int i = 1; i <= 9; i++) {

		if(n % i == 0) {

			if(n / i < 10) {

				flag = 1;

				break;

			}

		}

	}



	(flag) ? puts("Yes") : puts("No");

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
