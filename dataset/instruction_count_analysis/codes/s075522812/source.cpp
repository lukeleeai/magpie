#include "stdc++.h"

using namespace std;

typedef long long ll;

typedef long double ld;

const int MOD = (int)1e9 + 7;

const int MAXN = (int)1e5 + 7;

const int infint = (int)1e9;

ll a[MAXN], n, k;

int main()

{

	ios::sync_with_stdio(false);

	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)

		cin >> a[i];

	ll g = -1;

	for (int i = 0; i <= n - k; i++)

	{

		ll ans = abs(a[i] - 0) + abs(a[i] - a[i + k - 1]);

		ll ans2 = abs(a[i + k - 1] - 0) + abs(a[i] - a[i + k - 1]);

		ans = min(ans, ans2);

		if(g == -1 || ans < g)

			g = ans;

	}

	cout << g;

}