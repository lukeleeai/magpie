#include<stdio.h>

#include<algorithm>

#include<functional>

#include<cmath>

using namespace std;

long long  mod = 1000000007;

long long a[100000];

int main()

{

	int N;

	int count = 1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {

		scanf("%lld", &a[i]);

	}

	sort(a, a + N);

	long long number = a[0];

	long long bit;

	int count0 = 1;

	int count1 = 0;

	int count2 = 0;

	if (N % 3 == 0) {

		if (a[0] == 0) {

			for (int i = 1; i < N; i++) {

				if (a[i] == 0) {

					count0++;

				}

				if (a[i] != number) {

					number = a[i];

					count++;

				}

			}

			if (count == 2 && count0 == N / 3) {

				printf("Yes");

				return 0;

			}

		}

		else {

			for (int i = 1; i < N; i++) {

				if (a[i] == a[0]) {

					count0++;

				}

				if (a[i] == a[N / 3]) {

					count1++;

				}

				if (a[i] == a[N / 3 * 2]) {

					count2++;

				}

				if (a[i] != number) {

					number = a[i];

					count++;

				}

			}

			if (count == 3 && count0 == N / 3 && count1 == N / 3 && count2 == N / 3) {

				bit = a[0] ^ a[N / 3];

				if (bit == a[N / 3 * 2]) {

					printf("Yes");

					return 0;

				}

			}

		}

	}

	count0 = 0;

	for (int i = 0; i < N; i++) {

		if (a[i] == 0) {

			count0++;

		}

	}

	if (count0 == N) {

		printf("Yes");

	}

	else {

		printf("No");

	}

	return 0;

}
