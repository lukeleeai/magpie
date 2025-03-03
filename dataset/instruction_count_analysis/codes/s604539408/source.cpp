#include<stdio.h>



int isprime(int n){

	for(int i = 2; i * i <= n; i++){

		if( n % i == 0) return 0;

	}

	return 1;

}



int main(){

	int n, i;

	while(1){

		scanf("%d", &n);

		if( n == 0) break;

		int max = 0;

		for( i = n; i >=2; i--){

			if( isprime(i)){

				if(isprime( i - 2)){

					max = i;

					break;

				}

			}

		}

		printf("%d %d\n", max - 2, max);

	}

	return 0;

}