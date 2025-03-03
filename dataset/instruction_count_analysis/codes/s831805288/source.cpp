# include "stdc++.h"

using namespace std;

const int N = 1000 * 1000 + 10, mod = 1e9 + 7;

int r[N], c[N];

long long ans = 1, sr, sc, cnt;

int main() {

	int n, m;

	cin >> n >> m;

	memset(r, -1, sizeof(r));

	memset(c, -1, sizeof(c));

	for (int i = 0; i < n; i++) {

		int x;

		cin >> x;

		x--;

		if (r[x] != -1) {

			cout << 0;

			return 0;

		}

		r[x] = i;

	}

	for (int i = 0; i < m; i++) {

		int x;

		cin >> x;

		x--;

		if (c[x] != -1) {

			cout << 0;

			return 0;

		}

		c[x] = i;

	}

	for (int i = n * m - 1; i >= 0; i--) {

		if (r[i] >= 0 && c[i] >= 0) {

			cnt++, sr++, sc++;

			continue;

		}

		if (r[i] == -1 && c[i] == -1) {

//			cout << "rc : i = " << i<< " : " << ans << " : : ";

			if (sr * sc - cnt <= 0) {

				cout << 0;

				return 0;

			}

			ans = (ans * (sr * sc - cnt)) % mod;

//			cout << ans << endl;

			cnt++;

			continue;

		}

		if (r[i] == -1) {

			if (!sc) {

				cout << 0;

				return 0;

			}

//			cout << "r : i = " << i << " : " << ans << " : : ";

			ans = ans * sc % mod;

//			cout << ans << endl;

			cnt++, sr++;

			continue;

		}

		if (c[i] == -1) {

			if (!sr) {

				cout << 0;

				return 0;

			}

//			cout << "c : i = " << i << " : " << ans << " : : ";

			ans = ans * sr % mod;

//			cout << ans << endl;

			cnt++, sc++;

			continue;

		}

	}

	cout << ans;

	return 0;

}
