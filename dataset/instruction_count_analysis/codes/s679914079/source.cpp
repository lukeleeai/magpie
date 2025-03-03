#include <stdio.h>



int main() 

{

	int H;

	int A;

	int F;

	

	scanf("%d %d", &H, &A);

	

	F = H/A;

	

	H%A>0 ? printf("%d", F+1) : printf("%d", F);

	

	return 0;

}