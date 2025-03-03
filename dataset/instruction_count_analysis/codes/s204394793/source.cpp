//AT2043 AND Grid

#include <cstdio>

using namespace std;



const int MAXH = 505;

char g[MAXH][MAXH];



int main()

{

	int n, m;

	scanf("%d%d", &n, &m);

	for (register int i = 0; i < n; i++)

		scanf("%s", &g[i]);

	for (register int i = 0; i < n; i++)

	{

		for (register int j = 0; j < m; j++)

		{

			if (j == 0) printf("#");

			else if (g[i][j] == '#') printf("#");

			else if (j == m-1) printf(".");

			else if (!(i & 1)) printf("#");

			else printf(".");

		}

		printf("\n");

	}

	printf("\n");

	for (register int i = 0; i < n; i++)

	{

		for (register int j = 0; j < m; j++)

		{

			if (j == m-1) printf("#");

			else if (j == 0) printf(".");

			else if (g[i][j] == '#') printf("#");

			else if (i & 1) printf("#");

			else printf(".");

		}

		printf("\n");

	}

	return 0;

}