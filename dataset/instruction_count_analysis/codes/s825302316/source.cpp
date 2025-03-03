#include<stdio.h>



int main(void){

	int i,j;

	int N, K;

	int a[100] = {};

	int total = 0;

	scanf("%d%d",&N,&K);

	for(i = 0;i < K;i++){

        int d;

		scanf("%d", &d);

		for(j = 0;j < d;j++){

            int index;

			scanf("%d", &index);

			a[index - 1]++;

		}

	}

	for(i = 0;i < N;i++){

		if(a[i] == 0) total++;

	}

	printf("%d\n", total);

	return 0;

}
