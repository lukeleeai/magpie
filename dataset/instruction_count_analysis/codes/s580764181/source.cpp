#include <stdio.h>

#define N 200002



int a[N] = {0}, b[N] = {0};



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

	int n, k, i, c = 0, t, ans = 0;

	

	n = read(), k = read();

	for(i = 0; i < n; i++){

		a[read()]++;

	}

	for(i = 1; i <= n; i++){

		if(t = a[i]) b[t]++, c++;

	}

	if(c <= k) puts("0");

	else{

		c -= k;

		for(i = 1; i <= n; i++){

			if(t = b[i]){

				if(c > t) c -= t, ans += t * i;

				else{

					ans += c * i;

					c = 0;

					break;

				}

			}

		}

		printf("%d\n", ans);

	}

				

	return 0;

}