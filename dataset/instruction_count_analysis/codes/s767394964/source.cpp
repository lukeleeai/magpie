#include <stdio.h>



int main(){

	int huruf=0;

	scanf("%c", &huruf);

	

	if(huruf>='A' && huruf<='Z'){

		printf("A");

	} else if(huruf>='a' && huruf<='z'){

		printf("a");

	}



	return 0;

}