#include "stdc++.h"

using namespace std;



const int N = 1000 + 5;



int h, w, A, B, num[N], a[N][N];



int main()

{

	scanf("%d%d%d%d", &h, &w, &A, &B);

	for (int i = 1; i <= h; i++)

	{

		for (int j = 1; j <= w; j++)

			if ((i <= B && j <= A) || (i >= B + 1 && j >= A + 1))

				printf("1");

			else printf("0");

		printf("\n");

	}

    return 0;

}