#include"stdc++.h"

#define MAX 507

using namespace std;

int h, w;

char a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

int main()

{

	int i, j;

	scanf("%d%d", &h, &w);

	getchar();

	memset(a, '.', sizeof(a));

	memset(b, '.', sizeof(b));

	for(i = 1; i <= h; i++)scanf("%s", c[i] + 1);

	for(i = 1; i <= h; i += 2)

	{

		for(j = 2; j <= w; j++)a[i][j] = '#';

		b[i][1] = '#';

	}

	for(i = 2; i <= h; i += 2)

	{

		for(j = 1; j < w; j++)b[i][j] = '#';

		a[i][w] = '#';

	}

	for(i = 1; i <= h; i++)

	for(j = 1; j <= w; j++)

	if(c[i][j] == '#')a[i][j] = b[i][j] = '#';

	for(i = 1; i <= h; i++)

	{

		for(j = 1; j <= w; j++)printf("%c", a[i][j]);

		printf("\n");

	}

	printf("\n");

	for(i = 1; i <= h; i++)

	{

		for(j = 1; j <= w; j++)printf("%c", b[i][j]);

		printf("\n");

	}

	return 0;

}