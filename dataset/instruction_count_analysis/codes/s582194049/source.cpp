# include <iostream>

# include <algorithm>

# include <vector>

# include <string>

# include <set>

# include <map>

# include <cmath>

# include <iomanip>

# include <functional>

# include <utility>

# include <stack>

# include <queue>

# include <list>

# include <bitset>

# include <complex>

#include<limits.h>

#include<unordered_map>

#include<unordered_set>

#include<deque>

#include<cstdio>

using namespace std;

typedef long long int ll;

const int N = 1000000;

const int mod = 1000000007;

const int INF = 1 << 30;

#define rep(i,n) for(int i=(ll)0;i<(ll)n;++i)

#define ALL(x) x.begin(),x.end()

#define pp pair<ll,ll>

#define fi first

#define se second

#define pb push_back

ll ppow(ll x, ll n) {

	ll ans = 1;

	while (n > 0) {

		if ((n & 1) == 1)ans = ans * x;

		x = x * x;

		n >>= 1;

		x %= mod;

		ans %= mod;

	}

	return ans;

}

string YN(bool b) { return(b ? "YES" : "NO"); }

string yn(bool b) { return(b ? "Yes" : "No"); }

ll sz, fact[N], inv[N];

void setinv() {

	fact[0] = 1; inv[0] = 1;

	for (int i =1; i <= sz; i++) {

		fact[i] = (fact[i - 1] * i) % mod;  //階乗を求める

		inv[i] = ppow(fact[i], (ll)mod - 2) % mod; // フェルマーの小定理で逆元を求める

	}

}

ll conv(ll r) {//nCr

	return fact[sz] * inv[r] % mod * inv[sz - r] % mod;

}

int a,b,c,x,v[1000000];

int main() {

	cin >> a >> b >> c >> x;

	rep(i, a+1)rep(j, b+1)rep(k, c+1) {

		v[i * 500 + j * 100 + k * 50]++;

	}

	cout << v[x] << endl;

	return 0;

}