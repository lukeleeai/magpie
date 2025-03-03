#include "stdc++.h"

using namespace std;

typedef long long LL;

const LL Mod = 1e9 + 7;

LL n, a, b, ans;



LL qwe(LL a, LL n) { //快速幂

	LL res = 1LL;

	while(n) {

		if(n & 1) res = res * a % Mod;

		a = a * a % Mod;

		n >>= 1LL;

	}

	return res % Mod;

}



LL C(LL n, LL m) { //组合数

	if(m < n - m) m = n - m;

	LL x = 1LL;

	for(LL i = m + 1; i <= n; i++) x = x * i % Mod;

	LL y = 1LL;

	for(LL i = 1; i <= n - m; i++) y = y * i % Mod;

	return x * qwe(y, Mod - 2) % Mod;

	//除法取模只需将除法变乘法即可, 也就是用被除数去乘以除数的乘法逆元

	//求乘法逆元用费马小定理: 当模Mod为素数, x的逆元为qwe(x, Mod - 2)

}



int main() {

	cin >> n >> a >> b;

	ans = ((qwe(2LL, n) - C(n, a) - C(n, b) - 1) % Mod + Mod) % Mod;

	cout << ans << endl;

    return 0;

}



/*

c(n, 1) + ... + c(n, n)

c(n, 0) + ... + c(n, n) = 2 ^ n

=> ans = (2 ^ n) - C(n, a) - C(n, b) - 1

减去一束也不选的情况

*/