#include <stdio.h>

#include <time.h>

int isprime(int n){

	for(int i = 2; i * i <= n; i++){

		if(n % i == 0){

			return 0;

		}

	}

	return 1;

}

int main() {

	int i,p,q,n;

	while(1){

		scanf("%d",&n);

		if(n == 0){

			break;

		}

		for(i=n;i>=2;i--){

			if(isprime(i) && isprime(i-2) ){

				break;

			}

		}

		printf("%d %d\n",i-2,i);

	}

	return 0;

}





	// clock_t start, now;

	// now = clock();

	// printf("%f\n",(double)(now - start) / CLOCKS_PER_SEC);