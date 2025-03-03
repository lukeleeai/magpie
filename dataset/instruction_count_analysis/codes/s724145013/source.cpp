#include <stdio.h>



using namespace std;



const int n = 100;///change to 100



int res[n + 1][n + 1];



void fill1(int i)

{

	for(int l = 1; l <= n; l++)

		res[i][l] = 1;

}



main()

{

	int a, b;

	scanf("%d %d", &a, &b);

	

	b--;

	a -= (b > 0);

	

	int i = 1;

	while(b)

	{

		fill1(i);

		for(int j = 2; j < n && b; j += 2)

		{

			res[i][j] = 0;

			b--;

		}

		i++;

		fill1(i);

		i++;

	}

	i++;

	

	while(a)

	{

		for(int j = 1; j < n && a; j += 2)

		{

			res[i][j] = 1;

			a--;

		}

		i += 2;

	}

	i++;

	

	printf("%d %d\n", n, n);

	

	//for(int i = 1; i <= n; i++)

	//{

		//for(int j = 0; j < n; j++)

		//{

			//printf("%d ", 1 - res[i][j]);

		//}

		//puts("");

	//}

	

	for(int i = 1; i <= n; i++)

	{

		for(int j = 0; j < n; j++)

		{

			if(res[i][j]) printf(".");

			else printf("#");

		}

		puts("");

	}

}

/**

7 1 2 3 4 5 6 7

**/
