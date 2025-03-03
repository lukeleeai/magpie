#include <stdio.h>

int main (){

	int L, R, d, num = 0;

	scanf ("%d %d %d", &L, &R, &d);

	for (int i = L; i <= R; i++){

		if (i % d == 0){

			num = num +1;

		}

		}

	printf ("%d",num);

	return 0;

}