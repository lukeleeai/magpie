#include <stdio.h>



int main()

{

	long long n, x = 2, i;



	scanf("%lld", &n); 

	for (i = 0; i < n; i++) 

		x = 2 * (x + 1);

	printf("%lld\n", x);



	return 0;

}