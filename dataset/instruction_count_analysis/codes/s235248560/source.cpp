#include<cstdio>

const int MAX = 1e5;



long K;

long num[MAX + 1] = {0};



int main() {

	int a, b, N;

	scanf("%d %ld\n", &N, &K);



	for (int i = 0; i < N; i++) {

		scanf("%d %d", &a, &b);

		num[a] += b;

	}



	for (int i = 1; i <= MAX; i++) {

		if (K <= num[i]) {

			printf("%d\n", i);

			return 0;

		}

		K -= num[i];

	}

}
