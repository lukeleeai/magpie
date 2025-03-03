#include<cstdio>

#include<algorithm>

using namespace std;

typedef long long ll;

int n;

ll A, B;

ll x[100100];

int main()

{

	ll ans = 0;

	scanf("%d%lld%lld", &n, &A, &B);

	for (int i = 1; i <= n; i++)

	{

		scanf("%lld", &x[i]);

		if (i > 1)

			ans += min(B, A * (x[i] - x[i - 1]));

	}

	printf("%lld\n", ans);

	return 0;

}
