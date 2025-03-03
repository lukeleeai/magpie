#include <stdio.h>



int main (){

	int n; 

	scanf("%d", &n);

	char str[n + 1];

	scanf("%s", str);

	if(n % 2 == 1){

		puts("No");

	} else{

		int temp = 1;

		for(int i = 0; i < n / 2; i++){

			if(str[i] != str[i + n / 2]){

				temp = 0;

			}

		}

		if (temp){

			puts("Yes");

		}else{

			puts("No");

		}

	}

	return 0;

}