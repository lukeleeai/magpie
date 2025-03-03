#include<cstdio>

using namespace std;

int a[105][105];

int b[10005];

int main() {

	int H, W, n;

	scanf("%d%d", &H, &W);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%d", b + i);

	}

	int x, y, temp;

	x = y = 0;

	bool right = true;

	for (int i = 1; i <= n; i++) {

		temp = b[i-1];

		while (temp--)

		{

			a[x][y] = i;

			if (right) {

				y++;

				if (y > W-1) {

					y = W-1;

					x++;

					right = false;

				}

			}

			else

			{

				y--;

				if (y < 0) {

					y = 0;

					x++;

					right = true;

				}

			}

		}

	}

	

	for (int i = 0; i < H; i++) {

		for (int j = 0; j < W; j++) {

				printf("%d", a[i][j]);

			if (j < W - 1)

				printf(" ");

		}

		printf("\n");

	}

	return 0;

}