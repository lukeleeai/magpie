#include <stdio.h>

#define N 1000001



char f[N];



int main()

{		

	int n, x, i;

	

	scanf("%d", &n);

	for(i = 0; i < n; i++) f[i] = 0;

	for(i = 1, x = 0; ; i++){

		x = (10 * x + 7) % n;

		if(f[x]){

			puts("-1");

			return 0;

		}

		f[x] = 1;

		if(!x) break;

	}

	printf("%d\n", i);

				

	return 0;

}