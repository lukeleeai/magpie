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

int score;

int next_num;

const int Way = 26;

const int Nest = 0;

/*void dfs(int nest, int d) {

	int M = 0, temp = score;

	int prev, n;

	vector<pair<int, int>> kouho(26);

	rep(j, 0, 26) {

		score = temp;

		score += s[d - 1][j];

		prev = last[j];

		last[j] = d;

		rep(k, 0, 26)score -= c[k] * (d - last[k]);

		kouho[j].first = score;

		kouho[j].second = j;

		last[j] = prev;

	}

	//sort(all(kouho), greater<pair<int, int>>());

	rep(j, 0, Way) {

		//prev = last[kouho[j].second];

		//last[kouho[j].second] = d;

		score = kouho[j].first;

		if (nest && d < D)dfs(nest - 1, d + 1);

		if (M < score)M = score, n = kouho[j].second;

		printf("j:%2d score:%d\n", j, score);

		//last[kouho[j].second] = prev;

	}

	score = M;

	next_num = n;

}*/

int main()

{

	input();

	/*rep(i, 1, D + 1) {

		//score = 0;

		dfs(Nest, i);

		printf("%d\n", next_num + 1);

		last[next_num] = i;

		printf("%d\n", score);

	}*/

	ll score = 0, M = 0, temp;

	int prev, p;

	rep(i, 1, D + 1) {

		M = 0;

		temp = score;

		rep(j, 0, 26) {

			score = temp + s[i - 1][j];

			prev = last[j];

			last[j] = i;

			rep(k, 0, 26)score -= c[k] * (i - last[k]);

			last[j] = prev;

			if (M < score)M = score, p = j;

		}

		last[p] = i;

		score = M;

		printf("%d\n", p + 1);

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