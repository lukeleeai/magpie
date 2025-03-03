#include <stdio.h>

#include <string.h>

#include <algorithm>



using namespace std;



const int MAXN = 60;

int n;

int l[MAXN], t[MAXN], r[MAXN], b[MAXN];

int x[MAXN * 2], w;

int y[MAXN * 2], h;

bool c[MAXN * 4][MAXN * 4];

int ans;

const int dx[] = {0, -1, 0, 1};

const int dy[] = {-1, 0, 1, 0};



void init()

{

	w = h = 0;

	for (int i = 0; i < n; ++i) {

		scanf("%d%d%d%d", &l[i], &t[i], &r[i], &b[i]);

		x[w++] = l[i];

		x[w++] = r[i];

		y[h++] = t[i];

		y[h++] = b[i];

	}

	sort(x, x + w);

	w = unique(x, x + w) - x;

	sort(y, y + h);

	h = unique(y, y + h) - y;

}



void build()

{

	memset(c, 0, sizeof(c));

	for (int i = 0; i < n; ++i) {

		int x1 = (lower_bound(x, x + w, l[i]) - x) * 2 + 1;

		int x2 = (lower_bound(x, x + w, r[i]) - x) * 2 + 1;

		int y1 = (lower_bound(y, y + h, b[i]) - y) * 2 + 1;

		int y2 = (lower_bound(y, y + h, t[i]) - y) * 2 + 1;

		for (int x = x1; x <= x2; ++x) c[x][y1] = c[x][y2] = true;

		for (int y = y1; y <= y2; ++y) c[x1][y] = c[x2][y] = true;

	}

}



bool inrange(int x, int y)

{

	return x >= 0 && x <= w && y >= 0 && y <= h;

}



void dfs(int x, int y)

{

	c[x][y] = true;

	for (int i = 0; i < 4; ++i) {

		int nx = x + dx[i], ny = y + dy[i];

		if (inrange(nx, ny) && !c[nx][ny]) dfs(nx, ny);

	}

}



void solve()

{

	ans = 0;

	w *= 2, h *= 2;

	// for (int j = h; j >= 0; --j) {

	// 	for (int i = 0; i <= w; ++i) {

	// 		putchar(c[i][j] ? '*' : ' ');

	// 	}

	// 	puts("");

	// }

	for (int i = 0; i <= w; ++i) {

		for (int j = 0; j <= h; ++j) {

			if (!c[i][j]) dfs(i, j), ++ans;

		}

	}

}



int main()

{

	while (scanf("%d", &n) != EOF && n) {

		init();

		build();

		solve();

		printf("%d\n", ans);

	}

}