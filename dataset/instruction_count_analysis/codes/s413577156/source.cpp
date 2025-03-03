#include <cstdio>



int p[] = {-1,1};



int main()

{

	int a[4];

	for (int i = 0; i<4; i++){

		char c = getchar();

		a[i] = c - '0';

	}



	for (int i = 0; i<2; i++)

		for (int j = 0; j<2; j++)

			for (int k = 0; k<2; k++)

				if (a[0] + p[i]*a[1] + p[j]*a[2] + p[k]*a[3] == 7)

				{

					printf("%d",a[0]);

					printf("%c",i==0?'-':'+');

					printf("%d",a[1]);

					printf("%c",j==0?'-':'+');

					printf("%d",a[2]);

					printf("%c",k==0?'-':'+');

					printf("%d",a[3]);

					printf("=7\n");

					return 0;

				}

}