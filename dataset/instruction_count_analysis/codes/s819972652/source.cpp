#include <cmath>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <set>

using std::min; using std::max;

using std::swap; using std::sort;

using std::set;

typedef long long ll;

typedef std::pair<int, int> pii;



template<typename T>

void read(T &x) {

	int flag = 1; x = 0; char ch = getchar();

	while(ch < '0' || ch > '9') { if(ch == '-') flag = -flag; ch = getchar(); }

	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();

	x *= flag;

}



const int _ = 2e5 + 10, P = 1e9 + 7;

int h, w, a, b, fac[_], ifac[_], now[_];



int qpow(int a, int b) {

	int r = 1;

	for(; b; b >>= 1, a = 1ll * a * a % P)

		if(b & 1) r = 1ll * r * a % P;

	return r;

}



int C(int n, int m) {

	if(m > n) return 0;

	return (int)(1ll * fac[n] * ifac[m] % P * ifac[n - m] % P);

}



int main () {

	read(h), read(w), fac[0] = 1;

	int mx = h + w;

	for(int i = 1; i <= mx; ++i) fac[i] = 1ll * fac[i - 1] * i % P;

	ifac[mx] = qpow(fac[mx], P - 2);

	for(int i = mx; i >= 1; --i) ifac[i - 1] = 1ll * ifac[i] * i % P;

	read(a), read(b);

	for(int y = b + 1; y <= w; ++y) {

		int x = h - a;

		now[y] = C(x - 1 + y - 1, x - 1);

	}

	ll ret = 0;

	for(int y = b + 1; y <= w; ++y)

		(ret += 1ll * now[y] * C(w - y + a - 1, a - 1) % P) %= P;

	printf("%lld\n", ret);

	return 0;

} 
