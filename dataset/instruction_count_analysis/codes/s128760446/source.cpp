#include <stdio.h>

#include <math.h>

typedef long long LL;



LL f(LL x, LL n)

{

	if(n < x) return n;

	return f(x, n / x) + n % x; 

}



int main()

{		

	LL n, s, i, d, k, x, y;

	

	scanf("%lld%lld", &n, &s);

	if(s > n){

		puts("-1");

		return 0;

	}

	if(s == n){

		printf("%lld\n", n + 1);

		return 0;

	}

	for(i = 2; n / i >= i; i++){

		if(f(i, n) == s){

			printf("%lld\n", i);

			return 0;

		}

	}

	d = n - s;

	for(i = sqrt(d); i > 0; i--){

		if(d % i == 0){

			x = d / i + 1, y = s - i;

			if(y >= 0 && y < x && n / x < x){

				printf("%lld\n", x);

				return 0;

			}

		}

	}

	puts("-1");

				

	return 0;

}