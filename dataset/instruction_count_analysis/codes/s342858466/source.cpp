#include <stdio.h>

#include <string.h>



#define INT_MAX 2147483647

#define INT_MIN -2147483648



int max(int a, int b);

int min(int a, int b);

int abs(int a);



int n, a, b;



int main() {

	scanf("%d %d %d", &n, &a, &b);

	int total = 0;

	for(int i = 1; i <= n; i++) {

		int temp = i;

		int temp2 = 0;



		while(temp) {

			temp2 += temp % 10;

			temp /= 10;

		}



		if(a <= temp2 && temp2 <= b) {

			total += i;

		}

	}



	printf("%d\n", total);

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
