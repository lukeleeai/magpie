#include <stdio.h> 



int main () {

	int n;

	scanf("%d", &n);

	

	int count = 0;

	for (int i = 1; i < 10; i++) {

		for (int j = 1; j < 10; j++) {

			if (i * j == n) {

				count++;

			}

		}

	}

	

	if (count == 0) {

		puts("No");

	}

	else {

		puts("Yes");

	}

	

	return 0;

}