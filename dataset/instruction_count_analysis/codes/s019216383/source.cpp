#include <stdio.h>

#include <string.h>



int main()

{

	int A, B;

	char S[40];

	char T[40];

	char U[40];

	

	scanf("%s %s", &S, &T);

	scanf("%d %d", &A, &B);

	scanf("%s", &U);

	

	if(strcmp(S, U)==0)

{

	A--;

	printf("%d %d", A, B);

}

	else

{

	B--;

	printf("%d %d", A, B);

}

	return 0;

}