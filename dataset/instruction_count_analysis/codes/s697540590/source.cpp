//NOT MY CODE

#include <limits.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>



int comp(const void *a, const void *b){return *(int*)b-*(int*)a;}



int main(void){

	int n, m, i;

	int x[200000][2];

	scanf("%d%d", &n, &m);

	for(i=0; i<n; i++){

		int A;

		scanf("%d", &A);

		x[i][0]=A;

		x[i][1]=1;

	}

	for(i=n; i<=n+m; i++){

		int B, C;

		scanf("%d%d", &B, &C);

		x[i][0]=C;

		x[i][1]=B;

	}

	qsort(x, n+m, sizeof(int)*2, comp);

	int j=n;

	long sum=0;

	for(i=0; i<n; i++){

		if(x[i][1]<j){

			sum += ((long)x[i][0])*x[i][1];

			j -= x[i][1];

		}else{

			sum += ((long)x[i][0])*j;

			break;

		}

	}

	printf("%ld\n", sum);

}
