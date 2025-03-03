#include "stdc++.h"

using namespace std;



const int N = 3e5 + 10;

const int mod = 998244353;



int c[N];



int extgcd(int a, int b, int& x, int& y){

	int d = a;

	if (b != 0){

		d = extgcd(b, a % b, y, x);

		y -= (a / b) * x;

	}

	else{

		x = 1;

		y = 0;

	}

	return d;

}



int mod_inverse(int a){

	int x, y, m;

	m = mod;

	extgcd(a, m, x, y);

	return (m + x % m) % m;

}



int main(){

	int n, a, b, res, ans;

	long long k;

	scanf("%d %d %d %lld",&n,&a,&b,&k);

	c[0] = 1;

	for (int i = 1; i <= n; i++)

		c[i] = 1LL * c[i - 1] * (n - i + 1) % mod * mod_inverse(i) % mod;

	ans = 0;

	for (int i = 0; i <= min(k / a, 1LL * n); i++){

		res = (k - 1LL * a * i) / b;

		if ((k - 1LL * a * i) % b || res > n) continue;

		ans += 1LL * c[i] * c[res] % mod;

		ans %= mod;

	}

	printf("%d\n",ans);

	return 0;

} 