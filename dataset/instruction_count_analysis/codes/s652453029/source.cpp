#include <cmath>

#include <cstdio>

#include <cstring>

#include <algorithm>

using std::min; using std::max;

using std::swap; using std::sort;

using std::upper_bound;

typedef long long ll;



template<typename T>

void read(T &x) {

	int flag = 1; x = 0; char ch = getchar();

	while(ch < '0' || ch > '9') { if(ch == '-') flag = -flag; ch = getchar(); }

	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();

	x *= flag;

}



const int _ = 1e5 + 10, __ = 18;

int n, m, q, x[_], fa[__][_], Log[_], pw[_];



int main () {

	read(n), Log[0] = -1, pw[0] = 1;

	for(int i = 1; i <= n; ++i) read(x[i]);

	read(m), read(q);

	for(int i = 1; i <= n; ++i)

		Log[i] = Log[i >> 1] + 1, pw[i] = min(_, pw[i - 1] * 2);

	for(int i = 1; i <= n; ++i)

		fa[0][i] = upper_bound(x + 1, x + n + 1, x[i] + m) - x - 1;

	for(int i = 1; i <= Log[n]; ++i)

		for(int j = 1; j <= n; ++j)

			fa[i][j] = fa[i - 1][fa[i - 1][j]];

	for(int i = 1; i <= q; ++i) {

		int x, y; read(x), read(y);

		if(x > y) swap(x, y);

		if(x == y) { printf("%d\n", 0); continue; }

		int now = x, ret = 0;

		for(int j = Log[n]; j >= 0; --j)

			if(fa[j][now] < y) ret += pw[j], now = fa[j][now];

		printf("%d\n", ret + 1);

	}

	return 0;

} 
