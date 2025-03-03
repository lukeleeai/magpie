#include "stdc++.h"

using namespace std;

int n, T, a[100010], dp[100010];

int main() {

	scanf("%d%d", &n, &T);

	int mn = 0x3f3f3f3f, ans = 0;

	for (int i = 1; i <= n; ++ i) {

		scanf("%d", &a[i]);

		dp[i] = max(0, a[i] - mn);

		ans = max(ans, dp[i]);

		mn = min(mn, a[i]);

	}

	mn = 0x3f3f3f3f; int tot = 0;

	for (int i = 1; i <= n; ++ i) {if (a[i] - mn == ans) ++ tot; mn = min(mn, a[i]);}

	printf("%d\n", tot);

	return 0;

}