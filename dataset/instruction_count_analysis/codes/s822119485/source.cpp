#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <cmath>

#include <vector>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

#include <queue>

#include <ctime>

#include <cassert>

#include <complex>

#include <string>

#include <cstring>

#include <chrono>

#include <random>

#include <queue>

#include <bitset>

#include <stack>



using namespace std;



typedef long long ll;

typedef pair<ll, ll> ii;

typedef pair<ll, ll> pli;

typedef pair<ll, ll> pll;

typedef long double ld;



#define FOR(i, a, b) for (ll i = (a), _b = (b); i <= _b; i++)

#define FORD(i, b, a) for (ll i = (b), _a = (a); i >= _a; i--)

#define REP(i, n) for (ll i = 0, _n = (n); i < _n; i++)

#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

#define fi   first

#define se   second

#define all(a) a.begin(), a.end()

#define MASK(i) (1LL << (i))

#define BIT(x, i) (((x) >> (i)) & 1)

#define endl '\n'



const ll N = 3005, MOD = 1e9 + 7, H = 2e5 + 5;

ll dp[N], h, w, fac[H], n;

ii a[N];



void add(ll &a, ll b) {

	a = (a + b) % MOD;

	return;

}



void sub(ll &a, ll b) {

	a = (a - b + MOD) % MOD;

	return;

}



void mult(ll &a, ll b) {

	a = 1LL * a * b % MOD;

	return;

}



ll mul(ll a, ll b) {

	return 1LL * a * b % MOD;

}



ll modPow(ll a, ll x) {

	ll res = 1;

	while (x) {

		if (x & 1) mult(res, a);

		mult(a, a);

		x >>= 1;

	}

	return res;

}



ll inv(ll a) {

	return modPow(a, MOD - 2);

}



ll C(ll k, ll n) {

	ll ret = fac[n];

	mult(ret, inv(mul(fac[n - k], fac[k])));

	return ret;

}



int main(int argc, char const *argv[])

{

    //freopen("Y.inp","r",stdin);

	ios_base::sync_with_stdio(0); cin.tie(0);

	clock_t tStart = clock();



	cin >> h >> w >> n;

	FOR(i, 1, n) cin >> a[i].first >> a[i].second;

	fac[0] = 1;

	FOR(i, 1, H - 3) {

		fac[i] = fac[i - 1];

		mult(fac[i], i);

	}



	sort(a + 1, a + 1 + n);

	FOR(i, 1, n) {

		dp[i] = C(a[i].first - 1, a[i].second + a[i].first - 2);

		FOR(j, 1, i - 1) if (a[j].second <= a[i].second)

			sub(dp[i], mul(dp[j], C(a[i].first - a[j].first, a[i].first + a[i].second - a[j].first - a[j].second)));

	}



	ll res = C(h - 1, h + w - 2);

	FOR(i, 1, n) sub(res, mul(dp[i], C(h - a[i].first, h + w - a[i].first - a[i].second)));

	cout << res << endl;



	fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

	return 0;

}
