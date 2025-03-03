#include <stdio.h>



int main() {

	int N;

	int a1, a2, a3;

	scanf("%d", &N);

	

	a1 = N / 100;

	a2 = (N - (a1 * 100)) / 10 ;

	a3 = N % 10;

	if(a1 == 7 || a2 == 7 || a3 == 7){

		puts("Yes");

	}

	else {

		puts("No");

	}

	return 0;

}
