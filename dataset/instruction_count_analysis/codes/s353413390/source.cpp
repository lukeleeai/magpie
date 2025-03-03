#include <cstdio>

int readint() {

	char ch = getchar_unlocked();

	int res = 0;

	while('0' <= ch && ch <= '9') {

		res = res * 10 + (ch - '0');

		ch = getchar_unlocked();

	}

	return res;

}

char buf[1024];

void writeint(int x, char endch) {

	int ptr = 0, g;

	while(x > 0) {

		g = x / 10;

		buf[ptr++] = x - g * 10;

		x = g;

	}

	if(ptr == 0) {

		buf[ptr++] = 0;

	}

	while(ptr--) {

		putchar_unlocked(buf[ptr] + '0');

	}

	putchar_unlocked(endch);

}

int g[] = { 1, 9, 46, 233, 1182, 5985, 30301, 153401 };

int N, A[1024000];

int main() {

	int N = readint();

	for(int i = 0; i < N; ++i) {

		A[i] = readint();

	}

	// https://oeis.org/A108870 modified

	int sz = sizeof(g) / sizeof(int), lim = 1;

	while(lim < sz && g[lim] < N) ++lim;

	int cnt = 0;

	for(int i = lim - 1; i >= 0; --i) {

		for(int j = g[i]; j < N; ++j) {

			int pos = j, pt = j - g[i], x = A[j];

			while(pt >= 0 && A[pt] > x) {

				A[pos] = A[pt];

				pos -= g[i];

				pt -= g[i];

				++cnt;

			}

			A[pos] = x;

		}

	}

	writeint(lim, '\n');

	for(int i = lim - 1; i >= 0; --i) {

		writeint(g[i], (i != 0 ? ' ' : '\n'));

	}

	writeint(cnt, '\n');

	for(int i = 0; i < N; ++i) {

		writeint(A[i], '\n');

	}

	return 0;

}


