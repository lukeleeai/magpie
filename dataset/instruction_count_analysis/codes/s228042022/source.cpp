#include<stdio.h>



int main(){

	

	int a,b,c;

	

	scanf("%d %d %d",&a,&b,&c);

	

	int trip =a*b;

	

	if(trip<=c){

		

		printf("%d\n",trip);

		

	}

	

	else{

		

		printf("%d\n",c);

	}

	

	

	return 0;

}