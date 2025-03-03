#include <stdio.h>

#define N 350053

#define M 300007





int read()

{

	char c;

	while((c = getchar()) < 48 || c > 57);

	int x = c - 48;

	while((c = getchar()) > 47 && c < 58) x = x * 10 + c - 48;

	return x;

}



int ha[N] = {0};



int main() 

{

	int i, j, x, n, h, f = 1;

		

	n = read();

	for(i = 0; i < n; i++){

		x = read();

		if(!f) continue;

		h = x % M * 618 % M;

		for( ; ha[h] && ha[h] != x; h++);

		if(!ha[h]) ha[h] = x;

		else f = 0;

	}

	if(f) puts("YES");

	else puts("NO");

	

	return 0;

}