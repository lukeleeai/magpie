// vjudge 259381 B

#include <cstdio>



int H, W, flag1[110], flag2[110];

char map[110][100];



int main() {

	scanf("%d%d", &H, &W);

	for (int i = 0; i < H; i++) {

		scanf("%s", map[i]);

		for (int j = 0; j < W; j++)

			if (map[i][j] == '#') flag1[i] = flag2[j] = 1;

	}

	for (int i = 0; i < H; i++) {

		int out = 0;

		for (int j = 0; j < W; j++) 

			if (flag1[i] && flag2[j]) putchar(map[i][j]), out = 1;

		if (out) putchar('\n');

	}

	return 0;

}