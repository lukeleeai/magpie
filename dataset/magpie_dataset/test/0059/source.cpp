#include "stdc++.h"

#define lowbit(x) x&-x

using namespace std;



typedef long long ll;

static const int inf = 0x7fffffff;

static const int N = 1e5 + 10;

int n, a[N], cnt[N*10], pre[N*10];



void add (int x)

{

	for (int i = x; i <= N << 1; i += lowbit(i))

		++cnt[i];

}



ll query (int x)

{

	ll sum = 0;

	for (int i = x; i > 0; i -= lowbit(i))

		sum += cnt[i];

	return sum;

}



bool check (int x)

{

	for (int i = 1; i <= N << 1; ++i)

		cnt[i] = 0;

	pre[0] = 0;

	for (int i = 1; i <= n; ++i)

		pre[i] = pre[i-1] + (a[i] >= x ? 1 : -1);

	ll sum = 0;

	for (int i = 0; i <= n; ++i)

	{

		sum += query(pre[i] + N);

		add(pre[i]+N);

	}

	return sum >= 1ll * n * (n + 1) >> 2;

}



int main ()

{

	cin >> n;

	int l = 0, r = 0;

	for (int i = 1; i <= n; ++i)

		cin >> a[i], r = max(r, a[i]);

	int ans = 0;

	while (l <= r)

	{

		int mid = (l + r) >> 1;

		if (check(mid))

			l = mid + 1;

		else

			r = mid - 1;

	}

	cout << r;

	return 0;

}