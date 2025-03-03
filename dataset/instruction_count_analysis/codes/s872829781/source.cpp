#include <stdio.h>



int read()

{

	char c;

	while((c = getchar()) < 48 || c > 57);

	int x = c - 48;

	while((c = getchar()) > 47 && c < 58) x = x * 10 + c - 48;

	return x;

}



int main()

{		

	int n, i;

	int c[4] = {0};

	

	n = read();

	for(i = 0; i < n; i++){

		c[read() % 4]++;

	}

	if(c[1] + c[3] <= c[0] + (!c[2])) puts("Yes");

	else puts("No");

				

	return 0;

}