#include<iostream>

#include<algorithm>

using namespace std;



const int MAX = 1400;



int minSquare(int tile[MAX][MAX], int x, int y) {

	if (tile[y][x] == 1) {

		tile[y][x] = 0;

		return 0;

	}

	return min(tile[y - 1][x - 1], min(tile[y - 1][x], tile[y][x - 1])) + 1;

}



int main() {

	int H, W;

	int tile[MAX][MAX];

	int ans = 0;





	cin >> H >> W;

	for (int i = 0; i < H; i++) {

		for (int j = 0; j < W; j++) {

			cin >> tile[i][j];

		}

	}



	for (int i = 0; i < H; i++) {

		if (tile[i][0] == 1)tile[i][0] = 0;

		else {

			tile[i][0] = 1;

			ans = 1;

		}

	}

	for (int i = 1; i < W; i++) {

		if (tile[0][i] == 1)tile[0][i] = 0;

		else {

			tile[0][i] = 1;

			ans = 1;

		}

	}



	int x = 1;

	int y = 1;

	int n = min(H, W);

	for (int i = 1; i < n; i++) {

		for (int j = y; j < H; j++) {

			tile[j][x] = minSquare(tile, x, j);

			ans = max(tile[j][x], ans);

		}

		for (int j = x + 1; j < W; j++) {

			tile[y][j] = minSquare(tile, j, y);

			ans = max(tile[y][j], ans);

		}

		x++;

		y++;

	}



	cout << ans * ans << endl;

	return 0;

}