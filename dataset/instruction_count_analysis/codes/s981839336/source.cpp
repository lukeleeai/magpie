#include <cstdio>

#include <iostream>

#include <algorithm>

using namespace std;



inline int nextInt(void) {

	register int ret = 0;

	register int neg = false;

	register int bit = getchar();

	

	for (; bit < '0'; bit = getchar())

		if (bit == '-')neg ^= true;

	

	for (; bit >= '0'; bit = getchar())

		ret = ret * 10 + bit - '0';

	

	return neg ? -ret : ret;

}



#define inf 2147483647



int n, m, mini[400005];



int find(int t, int l, int r, int x, int y) {

	if (x <= l && r <= y)

		return mini[t];

	int mid = (l + r) >> 1;

	if (y <= mid)

		return find(t << 1, l, mid, x, y);

	if (x > mid)

		return find(t << 1 | 1, mid + 1, r, x, y);

	else

		return min(

			find(t << 1, l, mid, x, mid),

			find(t << 1 | 1, mid + 1, r, mid + 1, y)

		);

}



void update(int t, int l, int r, int x, int y) {

	if (l == r)mini[t] = y;

	else {

		int mid = (l + r) >> 1;

		if (x <= mid)

			update(t << 1, l, mid, x, y);

		else

			update(t << 1 | 1, mid + 1, r, x, y);

		mini[t] = min(mini[t << 1], mini[t << 1 | 1]);

	}

}



signed main(void) {

	n = nextInt();

	m = nextInt();



	for (int i = 0; i <= (n << 2); ++i)mini[i] = inf;



	for (int i = 1; i <= m; ++i) {

		int c = nextInt();

		int x = nextInt();

		int y = nextInt();

		if (c)	// find(x, y)

			printf("%d\n", find(1, 1, n, x + 1, y + 1));

		else	// update(x, y)

			update(1, 1, n, x + 1, y);

	}



//	system("pause");

}