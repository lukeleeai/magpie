#include<cstdio>

using namespace std;

int main()

{

	int n;

	scanf("%d",&n);

	if(n<2)

	{

		printf("1\n");

		return 0;

	}

	if(n<4)

	{

		printf("2\n");

		return 0;

	}

	if(n<8)

	{

		printf("4\n");

		return 0;

	}

	if(n<16)

	{

		printf("8\n");

		return 0;

	}

	if(n<32)

	{

		printf("16\n");

		return 0;

	}

	if(n<64)

	{

		printf("32\n");

		return 0;

	}

	printf("64\n");

	return 0;

}