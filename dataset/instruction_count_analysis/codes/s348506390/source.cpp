#include "stdc++.h"

using namespace std;



const int N = 2123;

int resp[N];



int dist(int a, int b) {

	return abs(a - b);

}



int dist(int a, int b, int x, int y) {

	return min({

		dist(a, b),

		dist(a, x) + dist(b, y) + 1,

		dist(a, y) + dist(b, x) + 1

	});

}



int main() {

	int n, x, y; scanf("%d %d %d", &n, &x, &y);

	for (int i = 0; i < n; i++) {

		for (int j = i+1; j < n; j++) {

			resp[dist(i+1, j+1, x, y)]++;

		}

	}

	for (int i = 1; i < n; i++) {

		printf("%d\n", resp[i]);

	}

}