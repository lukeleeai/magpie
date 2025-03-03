#include <stdio.h>

#include "stdc++.h"

using namespace std;

#define pb(x) push_back(x)

#define mp(x, y) make_pair(x, y)

typedef long long ll;

typedef pair <int, int> pii;

typedef pair <long long, long long> pll;



int main() {

	int n, x, y, t, px = 0, py = 0, pt = 0, ok = 1;

	scanf("%d", &n);

	for (int i = 0; i < n && ok; i++) {

		scanf("%d %d %d", &t, &x, &y);

		int dis = abs(x-px) + abs(y-py);

		int tme = t-pt;

		if (dis > tme or dis%2 != tme%2) ok = 0;

		px = x;

		py = y;

		pt = t;

	}

	printf(ok ? "Yes\n" : "No\n");

	return 0;

}