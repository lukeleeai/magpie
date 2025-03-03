#include <cstdio>

#include <cstring>



int main(){

	int N;

	scanf("%d", &N);



	char map[100][100+1];

	memset(map, 0, sizeof(map));



	int tmp;

	for (int i = 1; i < N + 1; i++) {

		scanf("%d", &tmp);

		for (int j = 0; j < 100; j++) {

			map[j][i] = (j < tmp) ? 1 : 0;

		}

	}



	int count = 0;

	for (int i = 0; i < 100; i++) {

		for (int j = 0; j < N; j++) {

			if (map[i][j] == 0 && map[i][j + 1] == 1) count++;

		}

	}



	printf("%d\n", count);



	return 0;

}
