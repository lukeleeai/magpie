#include <stdio.h>



int main(){

	int num;

	scanf("%d",&num);

	if (num%10==2||num%10==4||num%10==5||num%10==7||num%10==9){

		printf("hon\n");

	}

	else if(num%10==0||num%10==1||num%10==6||num%10==8){

		printf("pon\n");

	}

	else if(num%10==3){

		printf("bon\n");

	}

	return 0;

}
