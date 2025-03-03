#include<stdio.h>

#include<math.h>



int main(){

	

	int n;

	scanf("%d", &n);

	

	int num[n];

	int high = -101;

	int low = 101;

	

	for(int i = 0; i < n; i++){

		scanf("%d", &num[i]);

		if(high < num[i]){

			high = num[i];

		}

		if(low > num[i]){

			low = num[i];

		}

	}

		

	int bayar = 10000000;

	

	for(int i = low; i <= high; i++){

		int total = 0;

		for(int j = 0; j < n; j++){

			total += pow(i - num[j], 2);

		}

		if(total < bayar){

			bayar = total;

		}

	}

	

	printf("%d\n", bayar);

	

	return 0;

	

}