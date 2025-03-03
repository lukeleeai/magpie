#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;

ll num[3010];

int main()

{

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)

	{

		scanf("%lld", &num[i]);

		num[i]--;

	}



	ll res = 0;

	for (int i = 0; i < n; i++)

	{

		res += num[i];

	}

	printf("%lld", res);

	return 0;

}
