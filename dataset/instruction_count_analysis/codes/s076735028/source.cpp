#include <stdio.h>







int main()

{

	int H1, H2, M1, M2, k, tH, tM;

	scanf("%d %d %d %d %d", &H1, &M1, &H2, &M2, &k);

	tH = H2 - H1;

	tM = M2 - M1;

	tH = ((tH * 60) + tM) - k ;

	

	printf("%d", tH);

	return 0;

}