#include <stdio.h>



int main()

{

	char S[7];

	scanf ("%s", &S);

	

	((S[2] == S[3]) && (S[4] == S[5])) ? puts ("Yes") : puts ("No");

	

	return 0;

}