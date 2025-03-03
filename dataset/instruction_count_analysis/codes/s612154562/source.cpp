#include <stdio.h>



int main (){

	int angka;

	scanf ("%d", &angka);

	

	char str[angka+1];

	scanf("%s", str);

		

		// IIDID

	

	

	int sum = 0;

	int maks = 0;

	for (int i = 0 ; i < angka; i++){

		if (str[i] == 'I'){

			sum ++;	

		}

		else if (str[i]=='D'){

		 sum--;

		}

		if (sum > maks){

			maks = sum;

		}

		

	}

	

	printf("%d\n", maks);

	return 0;

}