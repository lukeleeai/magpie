#include <iostream>

#include <vector>

#include <algorithm>

#include <map>

#include <string>

#include <queue>

#include <fstream>

#include <string>

#include <math.h>

#include <set>

#include <string>

#include <bitset>

#include <fstream>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<ll, ll> P;

//typedef pair<ll, P> T;



#define rep(i, n) for (ll i = 0; i < (n); i++)

#define revrep(i, n) for (ll i = (n) - 1; i >= 0; i--)

#define f first

#define s second

#define pb push_back



ll mod = 1000000007;

const ll INF = 100000000000010000;

//const ull B = 998244353;

//ll kai[3010];



//void pres(double A, ll x = 20) { printf("%.20f\n", x); }



vector<ll> dx = { 0, 1, 0, -1, 1, -1, 1, -1, 0};

vector<ll> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0};



void chmin(double& x, double y) {

	x = min(x, y);

}



void chmax(double& x, double y) {

	x = max(x, y);

}



ll pow_long(ll x, ll y) {

	ll res = 1;

	while (y > 0) {

		if (y % 2 == 1) res *= x;

		x *= x;

		y /= 2;

	}

	return res;

}



void test() {

	cout << "888888888888888888888888" << endl;

}



ll gcd(ll x, ll y) {

	if (y == 0) return x;

	return gcd(y, x % y);

}



ll pow_mod(ll x, ll k) {

	x %= mod;

	ll res = 1;

	while (k > 0) {

		if (k % 2) {

			res *= x; res %= mod;

		}

		x *= x; x %= mod;

		k /= 2;

	}

	return res;

}



ll div_mod(ll x) {

	return pow_mod(x, mod - 2);

}



//コンビネーション

const int MAXcomb = 1000010;

ll fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];

//facはn!,finvは1/n!

//invは逆元

void COMinit() {

	fac[0] = fac[1] = 1;

	finv[0] = finv[1] = 1;

	inv[1] = 1;

	for (int i = 2; i < MAXcomb; i++) {

		fac[i] = fac[i - 1] * i % mod;

		inv[i] = mod - inv[mod%i] * (mod / i) % mod;

		finv[i] = finv[i - 1] * inv[i] % mod;

	}

}

ll comb(int n, int k) {

	if (n < k) return 0;

	if (n < 0 || k < 0) return 0;

	return fac[n] * finv[k] % mod * finv[n - k] % mod;

}



ll N;

ll A[100010];

multiset<ll> S;



void solve() {

	cin >> N;

	rep(i, N) {

		cin >> A[i];

		auto itr = S.lower_bound(A[i]);

		if (itr != S.begin()) {

			itr--;

			S.erase(itr);

		}

		S.insert(A[i]);

	}

	cout << S.size() << endl;

}



int main() {

	cin.tie(0);

	ios::sync_with_stdio(false);

	ll T = 1;

	//cin >> T;

	rep(i, T) solve();

}
