#include<iostream>

#include<vector>

#include<queue>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> P;

ll inf = 1000000007;

int dx[4] = { 1,-1,0,0 };

int dy[4] = { 0,0,1,-1 };

vector<ll>to[200005];

ll c[15];

int main() {

	int n, m, x;

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

	ll sum;

	for (int bit = 0; bit < (1 << n); bit++) {

		vector<ll>t(m, 0);

		sum = 0;

		bool ok = true;

		for (int i = 0; i < n; i++) {

			if (bit & (1 << i)) {

				for (int k = 0; k < m; k++) {

					t[k] += a[i][k];

				}

				sum += c[i];

			}

		}

		for (int j = 0; j < m; j++) {

			if (t[j] < x) {

				ok = false;

			}

		}

		if (ok) {

			ans = min(ans, sum);

		}

	}

	if (ans != inf) {

		cout << ans << endl;

	}

	else {

		cout << "-1" << endl;

	}

	return 0;

}