#include<stdio.h>

int main(){

	char a;

	

	scanf("%c",&a);

	if(a>=97 && a<=122){

		a+=1;

		printf("%c",a);

	}

	

	return 0;

}