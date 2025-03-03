#include <stdio.h>



int main() {

	int a, b;

	scanf("%d %d", &a, &b);

	

	if(b < a) {

		printf("No");

	} else if(a == b) {

		printf("Yes");

	} 

	

	return 0;

}