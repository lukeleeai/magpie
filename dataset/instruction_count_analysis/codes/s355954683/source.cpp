#include <stdio.h>



int main(){

	int n = 0;

	scanf("%d",&n);

	

	int modulo = n%10;

	int bagi = n/10;

	

	if(modulo==9 || bagi==9){

		printf("Yes\n");

	}else{

		printf("No\n");

	}

	

	return 0;

}