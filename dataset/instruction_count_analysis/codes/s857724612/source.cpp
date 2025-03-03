#include <stdio.h>



bool is_prime(int n)

{

	for (int i = 2; i * i <= n; i++)

		if (n % i == 0)

			return false;

	return true;

}



int main()

{

	int N, n, k = 0;

	scanf("%d", &N);

	while (N--)

	{

		scanf("%d", &n);

		if (is_prime(n))

			k++;

	}

	printf("%d\n", k);



	return 0;

}


