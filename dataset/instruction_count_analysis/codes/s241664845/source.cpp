#include <cstdio>

#include <algorithm>

#include <vector>

#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)



inline int read()

{

	int data = 0, w = 1; char ch = getchar();

	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();

	if (ch == '-') w = -1, ch = getchar();

	while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();

	return data * w;

}



const int N(1e5 + 10), LogN(17);

int n, L, Q, A[N], f[LogN][N], stk[N], H, T;



int main()

{

	n = read(), H = 1, T = 0;

	for (int i = 1; i <= n; i++) A[i] = read();

	L = read(), Q = read(), f[0][n] = n;

	for (int i = n; i; i--)

	{

		while (H <= T && A[stk[H]] - A[i] > L) ++H;

		if (H <= T) f[0][i] = stk[H];

		stk[++T] = i;

	}

	for (int i = 1; i < LogN; i++)

		for (int j = 1; j <= n; j++) f[i][j] = f[i - 1][f[i - 1][j]];

	for (int a, b, ans; Q--; )

	{

		a = read(), b = read(), ans = 0; if (a > b) std::swap(a, b);

		for (int i = LogN - 1; ~i; i--) if (f[i][a] && f[i][a] < b)

			ans += (1 << i), a = f[i][a];

		printf("%d\n", ans + 1);

	}

	return 0;

}
