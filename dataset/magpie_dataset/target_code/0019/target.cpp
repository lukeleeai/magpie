#include<stdio.h>



int main(){

	int k, len = 0;

	char str[100];

	scanf("%d %s", &k, str);

	for(int i = 0; str[i] != '\0'; i++){

		len++;

	}

	if(len <= k){

		printf("%s\n", str);

	}

	else{

		for(int i = k; i <= k + 3; i++){

			if(i < k + 3){

				str[i] = '.';

			}

			else{

				str[i] = '\0';

			}

		}

		printf("%s\n", str);

	}

	return 0;

}