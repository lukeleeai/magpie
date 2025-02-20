#include <string>

#include <iostream>

#include <algorithm>

using namespace std;

int H, W; string s[1009], t[3], x = "JOI";

int main() {

	cin >> H >> W;

	for (int i = 0; i < H; i++) cin >> s[i];

	cin >> t[0] >> t[1];

	int sum = 0;

	for (int i = 0; i < H - 1; i++) {

		for (int j = 0; j < W - 1; j++) {

			bool flag = true;

			for (int k = 0; k < 2; k++) {

				for (int l = 0; l < 2; l++) {

					if (s[i + k][j + l] != t[k][l]) flag = false;

				}

			}

			if (flag) sum++;

		}

	}

	int ret = 0;

	for (int i = 0; i < H; i++) {

		for (int j = 0; j < W; j++) {

			char e = s[i][j];

			int a[3] = { 0 }, z = -1;

			for (int c = 0; c < 3; c++) {

				if (x[c] == e) z = c;

				s[i][j] = x[c];

				for (int k = -1; k < 1 && i + k + 1 < H; k++) {

					if (i + k < 0) continue;

					for (int l = -1; l < 1 && j + l + 1 < W; l++) {

						if (j + l < 0) continue;

						bool flag = true;

						for (int m = 0; m < 2; m++) {

							for (int n = 0; n < 2; n++) {

								if (s[i + k + m][j + l + n] != t[m][n]) flag = false;

							}

						}

						if (flag) a[c]++;

					}

				}

			}

			for (int c = 0; c < 3; c++) ret = max(ret, sum + a[c] - a[z]);

			s[i][j] = e;

		}

	}

	cout << ret << endl;

	return 0;

}