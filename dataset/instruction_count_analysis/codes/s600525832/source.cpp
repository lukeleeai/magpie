#include <stdio.h>

 

int main(){

	long long int n, sum = 0;

	scanf("%lld", &n);

	for (int i=0 ; i<=n ; i++){

		if (i%3 == 0 || i%5 == 0 ){

			continue;

		}

		else {

			sum+=i;

		}

	}

	printf("%lld", sum);

	

	return 0;

}
