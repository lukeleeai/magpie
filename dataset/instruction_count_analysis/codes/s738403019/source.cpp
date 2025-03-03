#include <stdio.h>

#include <algorithm>

#define N 500

using namespace std;



int a[N + 5], p[N + 5], b[N * N + 5] = {0};



void write(int x)

{

	if(x < 10){

		putchar(x + 48);

		return;

	}

	write(x / 10);

	putchar(x % 10 + 48);

}



int cmp(int x, int y)

{

	return a[x] < a[y];

}



int next(int i)

{

	for(i++; b[i]; i++);

	return i;

}



int main()

{		

	int n, i, head = 1, j, x, t;

	

	scanf("%d", &n);

	for(i = 1; i <= n; i++){

		scanf("%d", a + i);

		p[i] = i;

	}

	sort(p + 1, p + n + 1, cmp);

	

	for(i = 1; i <= n; i++){

		x = p[i], t = a[x];

		for(j = 1; j < x; j++){

			if(head >= t){

				puts("No");

				return 0;

			}

			b[head] = x;

			head = next(head);

		}

		if(head == t) head = next(head);

		b[t] = x;

	}

	for(i = 1; i <= n; i++){

		x = p[i], t = a[x];

		for(j = x + 1; j <= n; j++){

			if(head > t) b[head] = x;

			else{

				puts("No");

				return 0;

			}

			head = next(head);

		}

	}

	puts("Yes");

	write(b[1]);

	for(i = 2, t = n * n; i <= t; i++){

		putchar(32), write(b[i]);

	}

	puts("");

			

	return 0;

}