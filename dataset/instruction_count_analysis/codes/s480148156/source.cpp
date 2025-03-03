#include <stdio.h>

 

int main() {

	int N;

	int x, y, z;

	scanf("%d", &N);

	

	x = N / 100;

	y = (N - (x * 100)) / 10 ;

	z = N % 10;

	if(x == 7 || y == 7 || z == 7){

		puts("Yes");

	}

	else {

		puts("No");

	}

	return 0;

}