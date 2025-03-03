#include <stdio.h>





int main()

{	 

	int a, b, c, k, x;

	

	scanf("%d%d%d%d", &a, &b, &c, &k);

	if(a > k) x = k;

	else{

		x = a, k -= a;

		if(k > b) x -= k - b;

	}

	printf("%d\n", x);

		

	return 0;

}