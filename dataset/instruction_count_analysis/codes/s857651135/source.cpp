#include <stdio.h>



int main () {

	int a, p, pie;

	scanf("%d %d", &a, &p);

	a *= 3;

	if ((a+p) >= 2) {

		pie = (a+p)/2;

		printf("%d\n", pie);

	}

	else {

		printf("0\n");

	}

	

	

	return 0;

}