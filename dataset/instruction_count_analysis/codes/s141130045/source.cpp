#include<stdio.h>



int main(){

 	int K,X;

 	scanf("%d %d", &K, &X );

 	int sum = K*500;

 	if(sum >= X){

 		puts("Yes");

	 }

	 else{

	 	puts("No");

	}

	return 0;

 }