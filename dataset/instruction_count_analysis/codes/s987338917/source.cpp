#include <stdio.h>

#include <stdlib.h>

#pragma warning(disable:4996)



int main() {

	int N = 0, K = 0;

	scanf("%d %d", &N, &K);

	int price[1000] = { 0 };

	for (int i = 0; i < N; i++) {

		scanf("%d", &price[i]);

	}

	for (int i = 0; i < N-1; i++) {

		for (int j = 0; j < N-1; j++) {

			if (price[j] > price[j + 1]) {

				int temp = price[j];

				price[j] = price[j + 1];

				price[j + 1] = temp;

			}

		}

	}

	int m = 0;

	for (int i = 0; i < K; i++) {

		m += price[i];

	}

	printf("%d\n", m);

		return 0;

}