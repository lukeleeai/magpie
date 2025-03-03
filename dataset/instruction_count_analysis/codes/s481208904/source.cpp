#include <stdio.h>

 

int main() {

 

    int a,b;

	scanf("%d %d", &a, &b) ;

	if(b % a == 0){

		printf("%d", a+b);

	}else if(b % a != 0){

		printf("%d", b-a);

	}

	return 0;

}