#include <stdio.h>



int main(){

	int val, k;

	scanf("%d", &val);

	scanf("%d", &k);

	int jwb = 1;

	

	for(int i = 0; i < val; i++){

		if(jwb < k){

			jwb *= 2;

		} else{

			jwb += k;

		}

	}

	printf("%d", jwb);

	return 0;

}