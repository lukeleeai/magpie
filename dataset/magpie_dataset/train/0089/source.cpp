#include<stdio.h>

int main(void)

{

	int N,i,c;

	int *k,*kk;

	while(1){

		scanf("%d",&N);

		if(N==0) break;

		k = new int [N];

		kk = new int [N];

		for(i=0;i<N;i++)

			kk[i] = 0;

		for(i=0;i<N;i++)

			scanf("%d",&k[i]);

		

		i=0,c=0;

		while(1){

			if(k[i%N] > 0){

				k[i%N]--;

				kk[i%N]++;

				c++;

			}

			if(kk[i%N] == 2){

				printf("%d\n",c);

				break;

			}

			if(i > N * 2){

				printf("NA\n");

				break;

			}

			i++;

		}

	}

	return 0;

}