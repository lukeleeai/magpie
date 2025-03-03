#include<cstdio>



using namespace std;



int h, w;



char s[110], a[110][110];



int Sum(int x, int y) {

	int res = 0;

	for (int i = -1; i <= 1; i++) {

		for (int j = -1; j <= 1; j++) {

			if (a[x + i][y + j] == '#') {

				res++;

			}

		}

	}

	return res;

}



int main() {

	scanf("%d %d", &h, &w);

	for (int i = 1; i <= h; i++) {

		scanf("%s", s);

		for (int j = 0; s[j]; j++) {

			a[i][j + 1] = s[j];

		}

	}

	for (int i = 1; i <= h; i++) {

		for (int j = 1; j <= w; j++) {

			if (a[i][j] == '#') {

				printf("#");

			}

			else {

				printf("%d", Sum(i, j));

			}

		}

		printf("\n");

	}

	return 0;

} 