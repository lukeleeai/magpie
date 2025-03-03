#include <cstdio>

int main() {

	int n, m;

	const int mmax = 50, nmax = 50;

	char A[nmax][nmax], B[mmax][mmax];

	scanf("%d%d", &n, &m);

	for (int y = 0; y < n; y++)scanf("%s", &A[y]);

	for (int y = 0; y < m; y++)scanf("%s", &B[y]);

	bool exist = false;

	for (int ly = 0; ly < n; ly++)for (int lx = 0; lx < n; lx++) {

		if (lx + m - 1 >= n or ly + m - 1 >= n) continue;

		bool flag = true;

		for (int y = 0; y < m; y++)for (int x = 0; x < m; x++) {

			if (A[ly + y][lx + x] != B[y][x]) flag = false;

		}

		if (flag)exist = true;

	}

	if (exist) printf("Yes\n");

	else printf("No\n");

	return 0;

}