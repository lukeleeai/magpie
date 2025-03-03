#include <stdio.h>

int n, m, p, an, bn, ans;

int x[100000];

int y[100000];

int a[100000];

int b[100000];

long long eans[100000];

int root(int c) {

	int t = 0;

	while (x[c] >= 0) {

		y[t] = c;

		c = x[c];

		t++;

	}

	for (int i = 0; i < t - 1; i++) {

		x[y[i]] = c;

	}

	return c;

}

void merge(int c, int d) {

	if (c == d)return;

	if (x[c] < x[d]) {

		x[c] += x[d];

		x[d] = c;

	}

	else if (x[c] == x[d]) {

		x[c] += x[d];

		x[d] = c;

	}

	else{

		x[d] += x[c];

		x[c] = d;

	}

}

int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {

		scanf("%d%d%d", a + i, b + i, &p);

		a[i]--, b[i]--;

	}

	for (int i = 0; i < n; i++)x[i] = -1;

	ans = n;

	for (int i = 0; i < m; i++) {

		an = root(a[i]);

		bn = root(b[i]);

		if (an != bn) {

			ans--;

			merge(an, bn);

		}

	}

	printf("%d\n", ans);

}