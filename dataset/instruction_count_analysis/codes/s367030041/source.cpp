#include <stdio.h>

int main () {

	

	long int a,b, count = 0;

	long int time = 0;

	float t;

	scanf("%ld %ld %f", &a, &b, &t);

	float t2 = t + 0.5;

 	for (int i = a; i < t2; i = i + a){

		 count = count + b;

		 time = i;

	 }

	

	 //long int x = (count*t2)/time;

	 printf("%ld", count);

	 //printf(" ------ %ld", x);

	

	

	

	

	return 0;

}
