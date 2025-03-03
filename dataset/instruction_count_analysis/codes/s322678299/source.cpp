#include <stdio.h>



int main(){

	int n;

	scanf("%d", &n);

	int T, K;

	scanf ("%d %d", &T, &K);

	

	for (int i = T; i <= K; i++){

		if (i % n == 0){

			puts("OK");

			return 0;

		}

		else continue;

	}

	puts("NG");

}