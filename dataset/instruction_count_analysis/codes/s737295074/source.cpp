#include <cstdio>

#include <vector>

#include <algorithm>



int main(){

	int N;

	scanf("%d", &N);



	char* map[101];

	for (int i = 0; i < 101; i++) {

		map[i] = new char[N + 1];

		map[i][0] = 0;

	}



	int tmp;

	for (int i = 1; i < N + 1; i++) {

		scanf("%d", &tmp);

		for (int j = 0; j < 101; j++) {

			if (j < tmp)

				map[j][i] = 1;

			else 

				map[j][i] = 0;

		}



	}



	int count = 0;

	for (int i = 0; i < 101; i++) {

		for (int j = 0; j < N; j++) {

			if (map[i][j] == 0 && map[i][j + 1] == 1) count++;

		}

	}



	printf("%d\n", count);



	return 0;

}
