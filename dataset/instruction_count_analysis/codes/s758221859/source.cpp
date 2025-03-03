#include <cstdio>

#include <algorithm>

const int MAXN = 1e5 + 10;



int N, K, X[MAXN];



namespace FastIO {

	template <typename T>

	void read(T & x) {

		x = 0; register char ch = getchar(); register int f = 0;

		for (; ch < '0' || ch > '9'; f |= ch == '-', ch = getchar());

		for (; ch >= '0' && ch <= '9'; x = (x << 3) + (x << 1) + (ch ^ '0'), ch = getchar());

		if (f) x = ~x + 1;

	}

}



int main() {

	using FastIO::read;

	read(N), read(K);

	int ans = 0x7f7f7f7f;

	for (int i = 0; i < N; i++) read(X[i]);

	for (int i = N - 1; i + 1 >= K; i--) {

		// printf("i=%d, i-K+1=%d\n", i, i-K+1);

		int l = X[i - K + 1], r = X[i];

		if (l <= 0 && r >= 0) ans = std::min(ans, std::min(-l * 2 + r, r * 2 - l));

		else ans = std::min(ans, std::max(std::abs(l), std::abs(r)));

	}

	printf("%d\n", ans);

	return 0;

}