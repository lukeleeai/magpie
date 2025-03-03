#include <stdio.h>



int main()

{

	int A, B, C;

	scanf ("%d %d %d", &A, &B, &C);



	(A==B && A==C && B==C) || (A!=B && A!=C && B!=C) ? puts ("No") : puts ("Yes");



	return 0;

}