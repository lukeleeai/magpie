#include<stdio.h>



int main(){

	int A1, A2, A3;

	scanf("%d %d %d", &A1, &A2, &A3);

	int sum = A1 + A2 + A3;

	(sum >= 22) ?puts("bust") : puts("win"); 

	return 0;

}