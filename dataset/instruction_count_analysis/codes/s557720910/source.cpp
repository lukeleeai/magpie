#include<stdio.h>

int main(){

	int n;

	scanf("%d", &n);

		int diff = 1000 - (n%1000);

		if(n<1000 || n%1000!=0){

			printf("%d", diff);

		}

		if(n%1000==0){

			printf("%d", diff-1000);

		}



	return 0;

}