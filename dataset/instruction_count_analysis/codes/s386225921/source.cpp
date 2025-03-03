#include<stdio.h>





int main(){



	int x;

	int total;

	scanf("%d",&x);

	

	if(x%1000 != 0){

		x = x % 1000;

		total = 1000-x;

		printf("%d",total);

	}

	else{

		printf("0");

	}





    return 0;

}
