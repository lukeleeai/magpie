#include <stdio.h>

#define M 121



long long p[M], t, tt;



int main()

{		

	int x, i, j;

	

	scanf("%d", &x);

	for(t = 0, i = 0; t < M; t++, i++){

		tt = t * t;

		p[i] = tt * tt * t;

	}

	for(i = 1; p[i] - p[i - 1] <= x; i++){

		for(j = i - 1; ; j--){

			if(j >= 0) t = p[i] - p[j];

			else t = p[i] + p[-j];

			if(t > x) break;

			if(t == x){

				printf("%d %d\n", i, j);

				return 0;

			}

		}

	}

			

	return 0;

}