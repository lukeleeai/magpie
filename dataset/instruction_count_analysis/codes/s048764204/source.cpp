#include <stdio.h>

#include <math.h>



int d[20002], e[20002], c = 0;



int main()

{	 

	int n, m, i, k, j;

	

	scanf("%d%d", &n, &m);

	for(i = 1, k = sqrt(m); i <= k; i++){

		if(m % i == 0){

			d[c] = i;

			e[c++] = m / i;

		}

	}

	for(i = c - 1; i >= 0; i--){

		d[c] = e[i], e[c] = d[i], c++;

	}

	for(i = c - 1; i >= 0 && e[i] < n; i--);

	printf("%d\n", d[i]);

		

	return 0;

}