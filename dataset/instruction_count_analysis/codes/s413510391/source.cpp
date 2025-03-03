#include <cstdio>

#include <vector>

using namespace std;

int n, m, a[200009], b[200009], e[400009], c[100009], s[100009], cnt, col[100009];

bool dfs(int pos) {

	bool ret = true; cnt++;

	for (int i = c[pos]; i < c[pos + 1]; i++) {

		if (col[e[i]] == col[pos]) ret = false;

		if (col[e[i]] == 0) {

			col[e[i]] = 3 - col[pos];

			if (!dfs(e[i])) ret = false;

		}

	}

	return ret;

}

void reader(int *x) {

	for (char c = getchar_unlocked(); 48 <= c && c <= 57; c = getchar()) *x = *x * 10 + c - 48;

}

int main() {

	reader(&n); reader(&m);

	for (int i = 0; i < m; i++) {

		reader(&a[i]); reader(&b[i]);

		c[--a[i]]++; c[--b[i]]++;

	}

	for (int i = 0; i < n; i++) s[i + 1] = s[i] + c[i]; c[0] = 0;

	for (int i = 0; i < n; i++) c[i + 1] = s[i + 1];

	for (int i = 0; i < m; i++) e[s[a[i]]++] = b[i], e[s[b[i]]++] = a[i];

	int c0 = 0, c1 = 0, c2 = 0;

	for (int i = 0; i < n; i++) {

		if (col[i] == 0) {

			col[i] = 1; cnt = 0;

			bool res = dfs(i);

			if (cnt == 1) c0++;

			else if (!res) c1++;

			else c2++;

		}

	}

	printf("%lld\n", 1LL * (c1 + c2) * (c1 + c2) + 1LL * c2 * c2 + 1LL * n * n - 1LL * (n - c0) * (n - c0));

	return 0;

}