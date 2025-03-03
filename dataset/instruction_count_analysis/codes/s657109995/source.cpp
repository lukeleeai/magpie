#include"stdc++.h"

#define rep(i,n)for(int i=0;i<(n);i++)

using namespace std;

#define nxt(i)((i+1)%n)

#define prv(i)((i+n-1)%n)



int n; string s;

int b[100000];

bool ok(int i, int j) {

	b[0] = i; b[prv(0)] = j;

	for (int i = 0; nxt(i) != prv(0); i = nxt(i)) {

		if ((b[i] && s[i] == 'o') || (!b[i] && s[i] == 'x'))b[nxt(i)] = b[prv(i)];

		else b[nxt(i)] = !b[prv(i)];

	}

	rep(i, n) {

		if (b[i]) {

			if (!((s[i] == 'o'&&b[prv(i)] == b[nxt(i)]) || (s[i] == 'x'&&b[prv(i)] != b[nxt(i)])))return false;

		}

		else {

			if (!((s[i] == 'o'&&b[prv(i)] != b[nxt(i)]) || (s[i] == 'x'&&b[prv(i)] == b[nxt(i)])))return false;

		}

	}

	return true;

}

signed main() {

	cin >> n >> s;

	rep(i, 2)rep(j, 2) {

		if (!ok(i, j))continue;

		rep(k, n) {

			if (b[k])printf("S");

			else printf("W");

		}

		printf("\n");

		return 0;

	}

	puts("-1");

}