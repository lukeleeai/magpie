#include<stdio.h>

#include<algorithm>

using namespace std;



const int MAX = 1400;



int main() {

	int H, W;

	int tile[MAX][MAX];

	int ans = 0;



	scanf("%d%d", &H, &W);

	for (int i = 0; i < H; i++) {

		for (int j = 0; j < W; j++) {

			scanf("%d", &tile[i][j]);

		}

	}



	for (int y = 0; y < H; y++) {

		for (int x = 0; x < W; x++) {

			if (tile[y][x] == 1) tile[y][x] = 0;

			else if (x < 1 || y < 1) tile[y][x] = 1;

			else tile[y][x] = min(tile[y - 1][x - 1], min(tile[y - 1][x], tile[y][x - 1])) + 1;

			ans = max(tile[y][x], ans);

		}

	}



	printf("%d\n", ans * ans);

	return 0;

}