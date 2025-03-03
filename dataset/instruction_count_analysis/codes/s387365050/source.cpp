#include <iostream>

using namespace std;

int main() {

	int n, m;

	char a[51][51], b[51][51];

	cin >> n >> m;

	for (int y = 0; y < n; y++) {

		for (int x = 0; x < n; x++) {

			cin>>a[y][x];

		}

	}

	for (int y = 0; y < m; y++) {

		for (int x = 0; x < m; x++) {

			cin>> b[y][x];

		}

	}

	bool exist = false;

	for (int ly = 0; ly < n; ly++) {

		for (int lx = 0; lx < n; lx++) {

			if (ly + m - 1 >= n or lx + m - 1 >= n) continue;

			bool match = true;

			for (int y = 0; y < m; y++) {

				for (int x = 0; x < m; x++) {

					if (b[y][x] != a[ly + y][lx + x]) match = false;

				}

			}

			if (match) exist = true;

		}

	}

	if (exist) cout << "Yes" << endl;

	else cout << "No" << endl;

	return 0;

}