#include <cmath>

#include<iostream>

#include<vector>

#include<algorithm>

#include<map>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> P;

ll inf = 1000000007;

ll c[15];

int main() {

	ll n, m, x;

	cin >> n >> m >> x;

	vector<vector<ll>>a(n);

	

	for (int i = 0; i < n; i++) {

		cin >> c[i];

		a[i].resize(m);

		for (int j = 0; j < m; j++) {

			cin >> a[i][j];

		}

	}

	ll ans = inf;

	for (int bit = 0; bit < (1 << n); bit++) {

		ll sum = 0;

		vector<ll>check(m, 0);

		bool ok = true;

		for (int i = 0; i < n; i++) {

			if (bit & (1 << i)) {

				sum += c[i];

				for (int j = 0; j < m; j++) {

					check[j] += a[i][j];

				}

			}

		}

		for (int k = 0; k < m; k++) {

			if (check[k] < x) {

				ok = false;

			}

		}

		if (ok) {

			ans = min(ans, sum);

		}



	}

	if (ans == inf) {

		cout << "-1" << endl;

	}

	else {

		cout << ans << endl;

	}

	return 0;

}


