#include "stdc++.h"

using namespace std;



int main()

{

	int N, H, W;

	cin >> N;

	while (N--) {

		cin >> H >> W;

		vector<int> used(26), xma(26), xmi(26, 100), yma(26), ymi(26, 100);

		vector<vector<char>> a(H, vector<char>(W));

		for (int i = 0; i < H; i++) {

			for (int j = 0; j < W; j++) {

				cin >> a[i][j];

				if (a[i][j] != '.') {

					int p = a[i][j] - 'A';

					used[p] = 1;

					xma[p] = max(xma[p], i);

					xmi[p] = min(xmi[p], i);

					yma[p] = max(yma[p], j);

					ymi[p] = min(ymi[p], j);

				}

			}

		}

		vector<vector<int>> d(26, vector<int>(26, 1000));

		for (int i = 0; i < 26; i++) {

			d[i][i] = 0;

		}

		bool sus = false;

		for (int i = 0; i < 26; i++) {

			if (used[i]) {

				for (int x = xmi[i]; x <= xma[i]; x++) {

					for (int y = ymi[i]; y <= yma[i]; y++) {

						if (a[x][y] == '.') {

							sus = true;

						}

						else if (a[x][y] - 'A' != i) {

							d[i][a[x][y] - 'A'] = -1;

						}

					}

				}

			}

		}

		for (int k = 0; k < 26; k++) {

			for (int i = 0; i < 26; i++) {

				for (int j = 0; j < 26; j++) {

					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

				}

			}

		}

		for (int i = 0; i < 26; i++) {

			if (d[i][i] < 0) {

				sus = true;

				break;

			}

		}

		cout << (sus ? "SUSPICIOUS" : "SAFE") << endl;

	}

	return 0;

}