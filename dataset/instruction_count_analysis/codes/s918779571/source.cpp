#include "stdc++.h"

#define ll long long

using namespace std;

const int N = 2e5 + 5;

int a[N];

void kill() {

	cout << "-1\n";

	exit(0);

}

int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)

		cin >> a[i];

	a[0] = -1;

	for (int i = 1; i <= n; i++)

		if (a[i] - a[i - 1] > 1) kill();

	ll ans = 0;

	for (int i = 1; i <= n; i++) {

		if (!a[i]) continue;

		ans++;

		if (a[i - 1] + 1 != a[i]) ans += a[i] - 1;

	}

	cout << ans << endl;

	return 0;

}


