#include <stdio.h>



int main () {

	int L, R, d, a, b = 0;

	scanf ("%d %d %d", &L, &R, &d);

	

	for (int i = 1; i < 150; i++) {

		a = i * d;

		if (a <= R && a >= L) {

			b++;

		}

	}

	printf ("%d", b);

	return 0;

}	