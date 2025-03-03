#include "stdc++.h"

using namespace std;



int a, b, c, d, len, k;



int cal(int a, int b) {

	if (!a || !b) return a + b;

	if (a < b) swap(a, b);

	return (a - 1) / (b + 1) + 1;

}



bool check(int mid) {

	int l = mid / (k + 1) * k + mid % (k + 1), r = mid / (k + 1) - (mid % (k + 1) == 0);

	if (l > a) return 0;

	return cal(a - l, b - r) <= k;

}



void workleft(int l, int r) {

	for (int i = l; i <= r; i++)

		putchar(i % (k + 1) ? 'A' : 'B');

}



void workright(int l, int r) {

	for (int i = l; i <= r; i++)

		putchar((a + b - i + 1) % (k + 1) ? 'B' : 'A');

}



int main() {

	int T;

	scanf("%d", &T);

	while (T--) {

		scanf("%d%d%d%d", &a, &b, &c, &d);

		len = a + b;

		k = cal(a, b);

		int l = 0, r = len + 1;

		while (l < r) {

			int mid = l + r >> 1;

			if (check(mid)) l = mid + 1;

			else r = mid;

		}

		l--;

		if (d <= l) workleft(c, d);

		else if (c > l) workright(c, d);

		else workleft(c, l), workright(l + 1, d);

		puts("");

	}

	return 0;

}