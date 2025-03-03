#include<stdio.h>

int main(){

	int x;

	scanf("%d",&x);

	if(x>=0&&x<1200){

		printf("ABC\n");

	}

	else if(x>=1200&&x<2800){

		printf("ARC\n");

	}

	else if(x>=2800&&x<=4208){

		printf("AGC\n");

	}

	return 0;

}