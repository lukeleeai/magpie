#include <stdio.h>

#include <algorithm>

#define N 100001

using namespace std;



int read()

{

	char c;

	while((c = getchar()) < 48 || c > 57);

	int x = c - 48;

	while((c = getchar()) > 47 && c < 58) x = x * 10 + c - 48;

	return x;

}



int a[N];



int main()

{		

	int n, i, l[2] = {0}, j = 0, t = 0;

	

	n = read();

	for(i = 0; i < n; i++) a[i] = read();

	make_heap(a, a + n);

	for(i = n - 1; i >= 0; i--){

		pop_heap(a, a + i + 1);

		if(!t) t = a[i];

		else{

			if(a[i] == t){

				l[j++] = t;

				t = 0;

				if(j == 2) break;

			}

			else t = a[i];

		}

	}

	printf("%lld\n", (long long)l[0] * (long long)l[1]);	

			

	return 0;

}