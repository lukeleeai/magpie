#include "stdc++.h"

#define ll long long

using namespace std;

 

const ll mol = 1e9 + 7;

const int maxn = 2e5;

 

int a[maxn + 11],b[maxn + 11];

 

int main() {

	int k,n;

	scanf("%d %d",&n,&k);

	int ca = 0 , cb = 0;

	for (int i = 1; i <= n; i++) {

		int x;

		scanf("%d",&x);

		if (x >= 0) a[++ca] = x;

		else b[++cb] = -x;

	}

	sort(a + 1 , a + 1 + ca , [&](int x,int y) { return x > y; });

	sort(b + 1 , b + 1 + cb , [&](int x,int y) { return x > y; });

	if (ca == 0) {

		ll ans = 1;

		if (k % 2 == 1) {

			for (int i = cb; i >= cb - k + 1; i--)

				ans = ans * b[i] % mol;

			ans = mol - ans;

		}

		else {

			for (int i = 1; i <= k; i++)

				ans = ans * b[i] % mol;

		}

		printf("%lld\n" , ans);

		return 0;

	}

	if (n == k) {

		ll ans = 1;

		for (int i = 1; i <= ca; i++)

			ans = ans * a[i] % mol;

		for (int i = 1; i <= cb; i++)

			ans = ans * b[i] % mol;

		if (cb & 1) ans = mol - ans;

		printf("%lld\n" , ans);

		return 0;

	}

	int u,d;

	if (ca >= k) { u = k; d = 0; }

	else if ((k - ca) % 2 == 0) {

		u = ca; d = k - ca;

	}

	else {

		u = ca - 1; d = k - ca + 1;

	}

	while (1) {

		if (u < 2 || d + 2 > cb) break;

		if (1ll * a[u] * a[u - 1] > 1ll * b[d + 1] * b[d + 2]) break;

		u -= 2; d += 2;

	} 

	ll ans = 1;

	for (int i = 1; i <= u; i++) ans = ans * a[i] % mol;

	for (int i = 1; i <= d; i++) ans = ans * b[i] % mol;

	printf("%lld\n" , ans);

} 