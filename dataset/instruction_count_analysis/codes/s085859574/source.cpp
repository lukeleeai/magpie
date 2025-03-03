#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include<vector>

#include<functional>

#include<algorithm>

#include<stdlib.h>

#include<string>

#include<string.h>

#define _USE_MATH_DEFINES

#include<math.h>

#include<deque>

#include<set>

#include<map>

#include<queue>

#include<list>

#include<iostream>

#include <bitset>

using namespace std;

typedef long long ll;

#define rep(i,a,b) for(auto i=a;i<b;i++)

#define all(_x) _x.begin(), _x.end()

#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())

#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))

#define vec_unique(_a) _a.erase(std::unique(all(_a)), _a.end());

#define vvec vector<vector<ll>>

ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

#define INF 1 << 30

const int mod = 1000000007;

ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }

ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }

ll ac(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }

ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }

int D;

vector<int> c(26);

vector<int> last(26, 0);

vector<vector<int>> s(365, vector<int>(26));

void input();

ll score;

int next_num;

void dfs(int nest, int d) {

	ll M = 0, temp = score;

	int prev, n;

	rep(j, 0, 26) {

		score = temp;

		score += s[d - 1][j];

		prev = last[j];

		last[j] = d;

		rep(k, 0, 26)score -= c[k] * (d - last[k]);

		if (nest && d < D)dfs(nest - 1, d + 1);

		if (M < score)M = score, n = j;

		last[j] = prev;

		//printf("%lld %d\n", *score, *next);

	}

	score = M;

	next_num = n;

}

int main()

{

	input();

	rep(i, 1, D + 1) {

		//score = 0;

		dfs(2, i);

		printf("%d\n", next_num + 1);

		//printf("%d\n", score);

	}

	return 0;

}

void input() {

	cin >> D;

	rep(i, 0, 26)cin >> c[i];

	rep(i, 0, D) {

		rep(i2, 0, 26)cin >> s[i][i2];

	}

}
