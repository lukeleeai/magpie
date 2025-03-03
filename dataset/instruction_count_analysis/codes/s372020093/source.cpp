#include <cstdio>

#include <algorithm>



using namespace std;



long long N, A, B, arr[100010], sum = 0;



int main()

{

	scanf("%lld%lld%lld", &N, &A, &B);

	for (int i = 1; i <= N; i++)

	{

		scanf("%lld", &arr[i]);

		if (i > 1) sum += min((arr[i] - arr[i - 1]) * A, B);

	}

	printf("%lld\n", sum);

	return 0;

}