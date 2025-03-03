#include <iostream>

#include <vector>



using namespace std;



int main() {

	int n;

	while ( cin >> n, n ) {

		vector<int> h(n), r(n);

		for (int i = 0; i < n; ++i) {

			cin >> h[i] >> r[i];

		}

		int M; cin >> M;

		h.resize(n+M);

		r.resize(n+M);

		for (int i = 0; i < M; ++i) {

			cin >> h[n+i] >> r[n+i];

		}

		n += M;



		int m[200][200] = {0};

		for (int i = 0; i < n; ++i) {

			for (int j = 0; j < n; ++j) {

				if (h[i] < h[j] && r[i] < r[j]) {

					m[i][j] = -1;

				}

			}

		}

		int ans = 0;

		for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {

			if (m[i][k] && m[k][j]) {

				m[i][j] = min(m[i][j], m[i][k] + m[k][j]);

			}

			ans = min(ans, m[i][j]);

		}

		cout << (-ans + 1) << endl;

	}

}