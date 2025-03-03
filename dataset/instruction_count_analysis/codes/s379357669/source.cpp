#include <set>

#include <vector>

#include <iostream>

#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int n, x, b[500029], r = 1, sum;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%d", &x);

		if (b[0]) puts("No");

		else if (x >= 500020) puts("Yes");

		else {

			while (b[r]) r++;

			if (r <= x) {

				puts("Yes");

				int z = x; b[z]++, sum++;

				while (b[z] == 2) b[z] = 0, b[--z]++, sum--;

				r = min(r, z + 1);

			}

			else {

				if (sum == x) puts("Yes"), b[0] = 1;

				else puts("No");

			}

		}

	}

	return 0;

}