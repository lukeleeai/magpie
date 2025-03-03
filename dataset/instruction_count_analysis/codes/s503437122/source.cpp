#include<stdio.h>

#include<stdlib.h>

#include<math.h>



//记得修改scanf_s

int main()

{

	long int n,*a;

	scanf("%ld", &n);

	a = (long int *)malloc(n * sizeof(long int));

	for (int i = 0; i < n; i++)

		scanf("%ld", &a[i]);



	double sum = 0, sum1 = 0;

	for (int i = 0; i < n; i++)

		sum += a[i];



	long int min = fabs(2 * a[0] - sum);

	for (int i = 0; i < n - 1; i++)

	{

		sum1 += a[i];

		if (min > fabs(2 * sum1 - sum))

			min = fabs(2 * sum1 - sum);

	}

	printf("%ld\n", min);

	return 0;

}