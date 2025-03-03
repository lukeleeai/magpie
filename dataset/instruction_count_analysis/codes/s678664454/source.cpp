#include "stdc++.h"

using namespace std;



namespace TYC

{

	void work()

	{

		int K, n;

		scanf("%d", &K);

		if (K == 1)

			return void(puts("1\n1"));

		printf("%d\n", n = (K + 3) / 4 * 2);

		for (int i = 0; i < n; i++)

		{

			for (int j = 0; j < n; j++)

				if (i & 1)

					printf("%d ", (i + j) % n + 1);

				else

				{

					int c = (i + j) % n + n + 1;

					printf("%d ", c > K ? c - n : c);

				}

			puts("");

		}

	}

}



int main()

{

	TYC::work();

	return 0;

}