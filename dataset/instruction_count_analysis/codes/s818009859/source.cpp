#include <cstdio>

#include <cmath>



#define maxn 100010

char s[maxn], t[maxn];

int gcd(int a, int b)

{

	return !b ? a : gcd(b, a % b);

}

typedef long long ll;

int main()

{

	int n, m; scanf("%d%d", &n, &m);

	scanf("%s%s", s, t);

	bool flag = 1;

	ll ans = 1ll * n * m / gcd(n, m);

	for (int i = 0; i < n; ++i)

		if (i * (ans / n) % (ans / m) == 0)

			flag &= s[i] == t[i * (ans / n) / (ans / m)];

	if (flag)

		printf("%lld\n", ans);

	else puts("-1");

	return 0;

}

/*

6 3

abbcca

abc

*/