#include <stdio.h>

#define MAXN 100005



int main ()

{

	int n;

	while(scanf("%d", &n) != EOF)

	{

		int n1 = 0, n2 = 0, n3 = 0;

		int a;

		while(n--)

		{

			scanf("%d", &a);

			if(a%4 == 0)n1++;

			else if(a%2 == 0)n2++;

			else n3++;

		}

		if((n3 - 1 > n1) || n3 - 1 == n1 && n2)

		printf("No\n");

		else printf("Yes\n");

	}

	return 0;

}