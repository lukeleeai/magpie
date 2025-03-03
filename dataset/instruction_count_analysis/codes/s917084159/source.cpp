#include<cstdio>

using namespace std;

const int MaxN = 2e5;

long long a[MaxN + 5];

int N;

long long T, x;



int main()

{

	long long flag = 0;

	scanf("%d %lld", &N, &T);

	for(int i = 1; i <= N; i++)	scanf("%lld", &a[i]);

	for(int i = 1; i <= N; i++)

	{

		if(a[i] <= T)

		{

			flag = a[i];

			x = a[i];

		}

		else if(a[i] - a[i - 1] > T) x = x + T;

		else x = x + a[i] - a[i - 1];

	}

	printf("%lld\n", x + T);

	return 0;

}