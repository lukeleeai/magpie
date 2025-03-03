#include <stdio.h>



int main (){

	

	int N,j, i = 0, dif, o = 0;

	int s[1000];

	int sum1 = 0, sum2 = 0, min, T = 0 ;

	scanf("%d", &N);

	

	for (int y = 0; y < N; y++){

		scanf("%d", &s[y]);

	}

	

	for (int u = 0; u < N; u++){

		min = min + s[u];

	}

	

	

	

	for (int i = 1; i < N; i++){

		for (int j = 0; j < i; j++){

			sum1 = sum1 + s[j];

		}

		for (int k = i; k < N; k++){

			sum2 = sum2 + s[k];

		}

		

		dif = sum1 - sum2;

		if(dif < 0){

			dif = -dif;

		}

		

		if(dif < min){

			min = dif;

			T = i;

		}

		

		sum1 = 0;

		sum2 = 0;

	}

	

	

	printf("%d", min);

	

	

	

	

	return 0;

}
