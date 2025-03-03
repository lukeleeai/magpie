#include<cstdio>

 

int main()

{

	int X;

	scanf("%d", &X);

	for (int A = 0; A < 120; ++A) {

      	for (int B = -120; B < A; ++B) {

			if (A * A * A * A * A - B * B * B * B * B == X)

			{

				printf("%d %d", A, B);

				return 0;

            }

		}

    }

}
