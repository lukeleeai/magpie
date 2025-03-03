#include<stdio.h>

#include<stdlib.h>

#include<math.h>

#include<algorithm>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

ll v[55];

typedef struct Node {

	ll val = 0;

	int sum = 0;

}node;

node s[55];

ll dp[55][55];

ll C(int n, int m);

int main(void)

{

	int n = 0, N, a, b;

	scanf("%d %d %d", &N, &a, &b);

	for (int i = 0; i < N; i++)// 5 5 5 4 4 3 2 1

		scanf("%lld", &v[i]);

	sort(v, v + N);

	reverse(v, v + N);

	s[n].val = v[0], s[n].sum++;

	for (int i = 1; i < N; i++)

		if (s[n].val == v[i])

			s[n].sum++;

		else

			s[++n].val = v[i], s[n].sum++;

	n++;

	ll ans = 0;

	double ave;

	ll t = 0;

	for (int i = 0; i < a; i++)

		t += v[i];

	ave = (double)t / a;

	if (a <= s[0].sum)

	{

		if (b > s[0].sum)b = s[0].sum;

		for (int i = a; i <= b;i++)

			ans += C(s[0].sum, i);

	}

	else

	{

		int k = s[0].sum, m;

		for (m = 1; m < n; m++)

			if (k + s[m].sum >= a)

				break;

			else

				k += s[m].sum;

		a -= k;

		ans = C(s[m].sum, a);

	}

	printf("%.12lf\n", ave);

	printf("%lld\n", ans);

	return 0;

}

ll C(int n, int m)

{

	if (n == m || !m)return 1;

	for (int i = 0; i <= 50; i++)

		dp[i][0] = 1;

	for (int i = 1; i <= n; i++)

		for (int j = 1; j <= m; j++)

			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

	return dp[n][m];

}