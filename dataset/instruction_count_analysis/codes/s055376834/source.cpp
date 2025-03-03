#include <stdio.h>



int main() {

	long long int n;

	scanf("%lld", &n);

	long long int total = 0;

	

	for(int i = 0; i <=n; i++){

		if(i % 3 == 0 && i % 5 == 0) {

			continue;

	} else if (i % 3 == 0) {

		continue;

	} else if (i % 5 == 0) {

		continue;

	} else { 

		total += i;

	}

}

	printf("%lld", total);

	return 0;

}