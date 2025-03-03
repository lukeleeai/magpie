#include <stdio.h>



int main()

{

	int N, M;

	scanf ("%d %d", &N, &M);

	

	int x = 0;

	for (int a = 1; a < N; a++)

	{

		x = x + a;

	}

	

	int y = 0;

	for (int b = 1; b < M; b++)

	{

		y = y + b;

	}

	

	if (N + M >= 2)

	{

		printf ("%d", x + y);

	}

	

	return 0;

}