#include <cstdio>

#include <iostream>

#include <algorithm>

#include <cstring>

#define N 300010

#define ls (x << 1)

#define rs (x << 1 | 1)

using namespace std;



int x[N], y[N], list[N * 3], cnt;

int w, h, n, ans;



struct node {

	int val, lab;

}tr[N << 4];



inline void update(int x) {

	tr[x].val = max(tr[ls].val, tr[rs].val);

}



void build(int x, int l, int r) {

	tr[x].val = tr[x].lab = 0;

	if (l == r) {

		tr[x].val = -list[l - 1];

		return;

	}

	int mid = l + r >> 1;

	build(ls, l, mid);

	build(rs, mid + 1, r);

	update(x);

}



inline void push_down(int x) {

	if (!tr[x].lab) return;

	tr[ls].lab += tr[x].lab;

	tr[ls].val += tr[x].lab;

	tr[rs].lab += tr[x].lab;

	tr[rs].val += tr[x].lab;

	tr[x].lab = 0;

}



void modify(int x, int l, int r, int a, int b, int ad) {

	if (a <= l && r <= b) {

		tr[x].lab += ad;

		tr[x].val += ad;

		return;

	}

	push_down(x);

	int mid = l + r >> 1;

	if (a <= mid) modify(ls, l, mid, a, b, ad);

	if (b > mid) modify(rs, mid + 1, r, a, b, ad);

	update(x);

}



inline int queryMax() {

	return tr[1].val;

}



int s[2][N * 3], top[2];

int bound[N * 3][2];

void solve(int mid) {

//cout << endl;

	cnt = 0;

	for (int i = 1; i <= n; ++i) {

		if (0 < y[i] && y[i] < h) list[++cnt] = y[i];

		if (1 < y[i] && y[i] < h + 1) list[++cnt] = y[i] - 1;

		if (-1 < y[i] && y[i] < h - 1) list[++cnt] = y[i] + 1;

	}

	list[++cnt] = 1;

	list[++cnt] = h - 1;

	sort(list + 1, list + cnt + 1);

	cnt = unique(list + 1, list + cnt + 1) - list - 1;

	

	build(1, 1, cnt);

	

	for (int i = 1; i <= cnt; ++i) {

		bound[i][0] = mid;

		bound[i][1] = w - mid;

	}

	

	for (int i = 1; i <= n; ++i) {

		if (0 < y[i] && y[i] < h) {

			int p = lower_bound(list + 1, list + cnt + 1, y[i]) - list;

			if (x[i] <= mid) bound[p][0] = min(bound[p][0], mid - x[i]);

			else bound[p][1] = min(bound[p][1], x[i] - mid);

		}

	}

	

	top[0] = top[1] = 0;

	for (int i = 1; i <= cnt; ++i) {

//cout << "-------------" << endl;

//cout << list[i] << ' ' << bound[i][0] << ' ' << bound[i][1] << endl;		

		for (int k = 0; k < 2; ++k) {

			modify(1, 1, cnt, i, i, bound[i][k]);

			while (top[k] && bound[s[k][top[k]]][k] > bound[i][k]) {

				int l = s[k][top[k] - 1] + 1;

				int r = s[k][top[k]];

				modify(1, 1, cnt, l, r, bound[i][k] - bound[s[k][top[k]]][k]);

				top[k]--;

			}

			s[k][++top[k]] = i;

		}

		ans = max(ans, (queryMax() + list[i] + 1) * 2);

	}

}



int main() {

	scanf("%d%d%d", &w, &h, &n);

	for (int i = 1; i <= n; ++i) {

		scanf("%d%d", &x[i], &y[i]);

	}

	if (w == 1 || h == 1) {

		printf("%d\n", (w + h) * 2);

		return 0;

	}

	solve(w / 2);

	for (int i = 1; i <= n; ++i) {

		swap(x[i], y[i]);

	}

	swap(w, h);

	solve(w / 2);

	printf("%d\n", max(ans, max(w, h) * 2 + 2));

	return 0;

}