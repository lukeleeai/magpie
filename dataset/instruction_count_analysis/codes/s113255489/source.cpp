#include <stdio.h>

#include <string.h>



int main()

{

	char S[15], T[15], U[15];

	int A, B;

	

	scanf ("%s %s", S, T);

	scanf ("%d %d", &A, &B);

	scanf ("%s", U);

	

	(strcmp (S,U) == 0) ? A-- : B--;

	printf ("%d %d", A, B);

	

	return 0;	

}