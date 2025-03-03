#include <stdio.h>



int main (){

	

	int a,b,c;

	scanf ("%d", &a);

	scanf ("%d", &b);

	if (a == 1 && b == 2 || a == 2 && b == 1){

		printf ("3");

	}

	else if (a == 1 && b == 3 || a == 3 && b == 1){

		printf ("2");

	}

	else if(a == 2 && b == 3 || a == 3 && b == 2){

		printf ("1");

	}

	return 0;

}