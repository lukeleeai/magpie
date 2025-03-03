#include "stdc++.h"

#define N 10



using namespace std;

typedef long long ll;



template <class T> inline void read(T &x) {

	char ch; bool flag = false;

	while (!isdigit(ch = getchar())) flag |= ch == '-';

	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));

	if (flag) x = -x;

}



inline int input() {

	int x; char ch; bool flag = false;

	while (!isdigit(ch = getchar())) flag |= ch == '-';

	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));

	return flag ? -x : x;

}



const int mod = 1e9 + 7;

inline int add(int x, int y) { x += y; return x >= mod ? x - mod : x; }

inline void inc(int &x, int y) { x += y; x -= x >= mod ? mod : 0; }



inline int Power(int x, int y) {

	int res = 1;

	while (y) {

		if (y & 1) res = (ll) res * x % mod;

		x = (ll) x * x % mod, y >>= 1;

	} return res;

}



template <class T> void chkmax(T &x, T y) { x = x > y ? x : y; }

template <class T> void chkmin(T &x, T y) { x = x < y ? x : y; }

template <class T> T gcd(T x, T y) { return !y ? x : gcd(x % y, y); }



int n, c;

int len[N];

ll f[50][500];

int p[N];



ll calc() {

	memset(f, 0, sizeof f);

	f[0][len[n] * n] = 1;

	for (int i = 0; i < n * c; ++i) {

		if (!(i % n)) continue;

		int x = p[i % n];

		for (int S = 0; S < (1 << (n - 1)); ++S) {

			if (S & (1 << x - 1)) continue;

			for (int j = i; j <= n * c; ++j)

				f[S | (1 << x - 1)][min(n * c, max(j, i + n * len[x]))] += f[S][j];

		}

	}

	return f[(1 << (n - 1)) - 1][n * c];

}



int main() {

	cin >> n >> c;

	for (int i = 1; i <= n; ++i) cin >> len[i];

	sort(len + 1, len + n + 1);

	for (int i = 1; i < n; ++i) p[i] = i;

	long double ans = 0;

	do { ans += calc(); } while (next_permutation(p + 1, p + n));

	for (int i = 1; i < n; ++i) ans /= 1.0L * i * c;

	printf("%.12Lf\n", ans);

	return 0;

}