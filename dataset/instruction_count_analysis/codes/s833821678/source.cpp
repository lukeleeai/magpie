#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <algorithm>

#include <iostream>

using namespace std;



typedef long long ll;

typedef pair<int, int> pii;



const int KN = 1e5 + 5;



int n, m, a[KN];

ll b[KN << 2];



int main() {

	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)

		cin >> a[i];

	ll all = 0;

	for (int i = 1; i < n; ++i) {

		int l = a[i], r = a[i + 1];

		if (l > r)

			r += m;

		all += r - l;

		if (l < r) {

			b[l + 1] += 1;

			b[r] -= (r - l + 1) - 1;

			b[r + 1] += (r - l + 1) - 2;

		}

	}

	for (int i = 2; i <= 2 * m; ++i)

		b[i] = b[i - 1] + b[i];

	for (int i = 2; i <= 2 * m; ++i)

		b[i] = b[i - 1] + b[i];

	ll ans = 1LL << 62;

	for (int i = 1; i <= m; ++i)

		ans = min(ans, all - b[i] - b[i + m]);

	cout << ans << endl;

	return 0;

}