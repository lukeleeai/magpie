#include <stdio.h>

#define M 1000000007

typedef long long LL;



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

	int n, s, i, x;

	LL ss = 0;

	

	n = read();

	s = read();

	for(i = 1; i < n; i++){

		x = read();

		ss += (LL)x * (LL)s % M;

		s += x;

		if(s >= M) s -= M;

	}

	printf("%lld\n", ss % M);

				

	return 0;

}