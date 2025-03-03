#include <stdio.h>





int main() {

	int x, a, b;

	

	scanf("%d %d %d", &x, &a, &b);

	

	int rangeA = (x > a)? (x - a) : (a - x);

	int rangeB = (x > b)? (x - b) : (b - x);

	

	(rangeA < rangeB)? puts("A") : puts("B");

	

	return 0;

}