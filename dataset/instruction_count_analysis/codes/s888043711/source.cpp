#include<cstdio>

#include<cstring>

//long long

const int len = 1e5 + 5;

int a[len],cnt[5],N;



int main(void)

{

	scanf("%d", &N);

	for (int i = 0; i < N; ++i)

	{

		scanf("%d", &a[i]);

		if (a[i] % 4 == 0)

			++cnt[4];

		else if (!(a[i] & 01))

			++cnt[2];

		else

			++ cnt[1];

	}

	if (cnt[2] == 0 && cnt[4] >= cnt[1] - 1)

		printf("Yes");

	else if (cnt[4] >= cnt[1])

		printf("Yes");

	else

		printf("No");

	return 0;

}