#include "stdc++.h"



#define MAXN 100005

#define ls x << 1

#define rs x << 1 | 1

#define INF 0x3f3f3f3f3f3f3f3f



typedef long long lint;



using namespace std;



int n, m, k; 

lint a[MAXN], suma[MAXN], b[MAXN], l[MAXN], r[MAXN], ele[MAXN << 1];

lint f[MAXN << 1];



struct segment {

	int l, r, v;

}t[MAXN << 3];



int read() {

	char c = getchar();

	int x = 0;

	while (!isdigit(c))

		c = getchar();

	while (isdigit(c)) {

		x = (x << 3) + (x << 1) + c - '0';

		c = getchar();

	}

	return x;

}



void build(int l = 1, int r = m, int x = 1) {

	t[x].l = l;

	t[x].r = r;

	t[x].v = 0;

	if (l == r)

		return ;

	int mid = (l + r) >> 1;

	build(l, mid, ls);

	build(mid + 1, r, rs);

}



void pushdown(int x) {

	if (t[x].v) {

		t[ls].v = t[rs].v = t[x].v;

		t[x].v = 0;

	}

}



void modify(int l, int r, int v, int x = 1) {

	if (l > r)

		return ;

	if (l <= t[x].l && t[x].r <= r) {

		t[x].v = v;

		return ;

	}

	pushdown(x);

	int mid = (t[x].l + t[x].r) >> 1;

	if (l <= mid)

		modify(l, r, v, ls);

	if (r > mid)

		modify(l, r, v, rs);

}



int query(int p, int x = 1) {

	if (t[x].l == t[x].r)

		return t[x].v;

	pushdown(x);

	int mid = (t[x].l + t[x].r) >> 1;

	if (p <= mid)

		return query(p, ls);

	return query(p, rs);

}



int dis(int x, int y) {

	return (ele[y] - ele[x] + k) % k;

}



int main() {

	// freopen("s.txt", "r", stdin);

	// freopen("a.out", "w", stdout);

	n = read();

	k = read();

	for (int i = 1; i <= n; ++i) {

		a[i] = read();

		b[i] = read();

		if (b[i] == 1 && a[i] * 2 > k) {

			puts("-1");

			return 0;

		}

		suma[i] = suma[i - 1] + a[i];

	}

	for (int i = 1; i <= n; ++i) {

		if (b[i] == 1) {

			l[i] = (-suma[i - 1] * 2 % k + k) % k;

			r[i] = (-suma[i] * 2 % k + k) % k;

		}

		else {

			l[i] = 0;

			r[i] = k - 1;

		}

		ele[++m] = l[i];

		ele[++m] = r[i];

	}

	sort(ele + 1, ele + m + 1);

	m = unique(ele + 1, ele + m + 1) - ele - 1;

	build();

	for (int i = 1; i <= n; ++i) {

		l[i] = lower_bound(ele + 1, ele + m + 1, l[i]) - ele;

		r[i] = lower_bound(ele + 1, ele + m + 1, r[i]) - ele;

	}

	for (int i = n; i >= 1; --i) {

		int j = query(l[i]);

		if (!j)

			f[i] = 0;

		else 

			f[i] = f[j] + dis(l[i], l[j]);

		// cout << i << " " << f[i] << " " << l[i] << " " << r[i] << endl;

		if (l[i] <= r[i]) {

			modify(1, l[i] - 1, i);

			modify(r[i] + 1, m, i);

		}

		else 

			modify(r[i] + 1, l[i] - 1, i);

	}

	lint ans = f[1];

	for (int i = 1; i <= m; ++i) {

		int j = query(i);

		if (!j)

			ans = 0;

		ans = min(ans, f[j] + dis(i, l[j]));

	}

	printf("%lld\n", ans + suma[n] * 2);

}