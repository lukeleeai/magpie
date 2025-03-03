#include<cstdio>

using namespace std;

const int maxn = 10000000;

int main()

{

	int a,b,c,d;

	scanf("%d%d%d%d",&a,&b,&c,&d);

	if(a % c == 0 && b % d == 0)

	{

		printf("No\n");

	}

	else

	{

		int nz = maxn / (c * d - 1);

		int nf = (c * d - 1) * nz + 1;

		printf("Yes\n");

		for(int i = 1;i <= a;++i)

		{

			for(int j = 1;j <= b;++j)

			{

				if(i % c == 0 && j % d == 0)

					printf("-%d ",nf);

				else

					printf("%d ",nz);

			}

			putchar('\n');

		}

	}

	return 0;

}