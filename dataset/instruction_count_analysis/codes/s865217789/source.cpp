#include <cstdio>



int main()

{

	int n;

	while (scanf("%d", &n), n)

	{

		int t[10], d;

		for (d = 0; n; ++d, n /= 8)

			t[d] = n % 8;

		for (int i = d-1; i >= 0; --i)

			printf("%d", t[i] >= 5 ? t[i]+2 : t[i] == 4 ? t[i]+1 : t[i]);

		printf("\n");

	}



	return 0;

}