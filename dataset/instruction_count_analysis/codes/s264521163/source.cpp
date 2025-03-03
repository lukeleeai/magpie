#include <cmath>

#include <cstdio>

#include <cstring>

#include <algorithm>

using std::min; using std::max;

using std::swap; using std::sort;

typedef long long ll;



template<typename T>

void read(T &x) {

	int flag = 1; x = 0; char ch = getchar();

	while(ch < '0' || ch > '9') { if(ch == '-') flag = -flag; ch = getchar(); }

	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();

	x *= flag;

}



const int _ = 42, __ = 1.5e5 + 10, P = 1e9 + 7;

int n, x, y, z, f[_][__], lim, Q;



int main () {

	read(n), read(x), read(y), read(z);

	lim = (1 << (x + y + z)) - 1;

	Q = 1 << (z - 1) | 1 << (y + z - 1) | 1 << (x + y + z - 1);

	f[0][0] = 1; int ret = 1;

	for(int i = 0; i < n; ++i) {

		ret = 1ll * ret * 10 % P;

		for(int s = 0; s <= lim; ++s)

			for(int j = 1; j <= 10; ++j) {

				int t = (s << j | (1 << (j - 1))) & lim;

				if(!f[i][s] || (t & Q) == Q) continue;

				(f[i + 1][t] += f[i][s]) %= P;

			}

	}

	for(int s = 0; s <= lim; ++s) (ret += P - f[n][s]) %= P;

	printf("%d\n", ret);

	return 0;

} 
