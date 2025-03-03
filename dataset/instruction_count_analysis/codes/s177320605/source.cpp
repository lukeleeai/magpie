#include <stdio.h>



int main() {

	int a, b;

	scanf("%d", &a);

	

	b = a / 2;

	

	if(a % 2 == 1) {

		printf("%d", b + 1);

	} else {

		printf("%d", b);

	}

	

	return 0;

}