#include<stdio.h>

const int MAX_X = 10000;

int prime[10000];



int main(){



	int i, k, n;



	int border[10];

	for( i = 2; i <= MAX_X; i++) {

		prime[i] = 1;

	}



	for(i = 2; i*i <= MAX_X; i++){

		if(prime[i]) {

			for(k = 2 * i; k <= MAX_X; k += i){

				prime[k] = 0;

			}

		}

	}



	while(1){

		scanf("%d", &n);

		if( n == 0) break;

		int max;

		for( i = n; i >= 2; i--){

			if( prime[i]){

				if( prime[i - 2]){

					max = i;

					break;

				}

			}

		}

		printf("%d %d\n", max -2, max);

	}

	return 0;

}