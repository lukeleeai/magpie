#include <cstdio>



using namespace std;



int n, cnt = 0;

bool f[1000010] = { false };



int main()

{

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)

	{

		int temp;

		scanf("%d", &temp);

		if (f[temp]) cnt++;

		else f[temp] = true;

	}

	if (cnt & 1) cnt++;

	printf("%d\n", n - cnt);

	return 0;

}