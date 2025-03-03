#pragma once

#include <stdio.h>

#include <sstream>

#include <string.h>

#include <vector>

#include <map>

#include <algorithm>

#include <iostream>

#include <utility>

#include <set>

#include <cctype>

#include <queue>

#include <stack>

#include <cstdio>

#include <cstdlib>

#include <cmath>

#include <deque>

#include <limits>

#include <iomanip>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

#define bit(x,v) ((ll)x << v)



const ll INF = 1000000007;

const ll MAX = 210000;

const ll MOD = 1000000007;



long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {

	fac[0] = fac[1] = 1;

	finv[0] = finv[1] = 1;

	inv[1] = 1;

	for (int i = 2; i < MAX; i++) {

		fac[i] = fac[i - 1] * i % MOD;

		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;

		finv[i] = finv[i - 1] * inv[i] % MOD;

	}

}

ll gcd(ll a, ll b) {

	if (b == 0) return a;

	return gcd(b, a % b);

}

int pr[100010];

void uini(int n) {

	for (size_t i = 0; i <= n; i++)

	{

		pr[i] = i;

	}

}



int parent(int x) {

	if (x == pr[x]) return x;

	return pr[x] = parent(pr[x]);

}



bool unit(int x, int y) {

	int px = parent(x);

	int py = parent(y);



	if (px == py) return false;

	if (px < py) {

		pr[py] = px;

	}

	else {

		pr[px] = py;

	}

	return true;

}



// res[i][c] := i 文字目以降で最初に文字 c が登場する index (存在しないときは n)

vector<vector<int> > calcNext(const string & S) {

	int n = (int)S.size();

	vector<vector<int> > res(n + 1, vector<int>(26, n));

	for (int i = n - 1; i >= 0; --i) {

		for (int j = 0; j < 26; ++j) res[i][j] = res[i + 1][j];

		res[i][S[i] - 'a'] = i;

	}

	return res;

}

// mod 1000000007 の世界で a += b する関数

void add(long long& a, long long b) {

	a += b;

	if (a >= MOD) a -= MOD;

}

ll slide(vector<ll> & v, ll a, ll b) {

	ll azv = abs(v[0] - a);

	ll bzv = abs(v[0] - b);

	ll aov = abs(v[1] - a);

	ll bov = abs(v[1] - b);

	v[0] = a;

	v[1] = b;

	return max((azv + bov), (bzv + aov));

}





bool a[100010];

string gcs(string s, string t) {



	ll high = min(s.size(), t.size());

	ll low = 0;

	ll mid = -1;

	for (size_t i = 0; i < 20; i++)

	{

		mid = (high + low) / 2;

		string st = s.substr(0, mid);

		string tt = t.substr(0, mid);

		if (st == tt) {

			low = mid;

		}

		else high = mid;



		if (s.size() <= mid || t.size() <= mid) continue;

		st = s.substr(0, mid + 1);

		tt = t.substr(0, mid + 1);

		if (st == tt) {

			low = mid + 1;

			mid = mid + 1;

		}

	}

	return s.substr(0, mid);

}



ll dp[100010][6];

int pi[100010][6];

ll dist[7][7];



ll calc(ll now, ll b, int c, int p, int v) {



	if (b < 0) return INF;

	ll dis = now - b - 1LL;



	ll val = dp[b][p] + max(dis, dist[p][c]);

	if (v > val) {

		val = min(val, calc(now, pi[b][p], c, p, val));

	}

	return val;

}



struct bridge {

	int l, r;

};

bridge bs[100010];

bool cm(bridge& left, bridge& right) {

	return left.r < right.r;

}

struct edge {

	int t;

	ll cost;

	edge(int t, ll cost) : t(t), cost(cost) {}

};

vector<edge> es[100010];

int calc(int a, int b) {

	int rem = 24 - a;

	int tb = (b + rem) % 24;

	if (tb == 0) tb = 24;

	return min(tb, 24 - tb);



}



void solv() {

	

	int n, k;

	cin >> n >> k;

	string s;

	cin >> s;

	//s += '0';

	int j = 0;

	int i = 0;

	int c = 0;

	bool bz = false;

	int res = 0;

	for (; i < s.size(); i++)

	{

		if (s[i] == '1') {

			if (i > 0 && s[i - 1] == '0') {

				c--;

			}

		}

		for (; j < s.size(); j++)

		{

			if (s[j] == '1') {

				bz = false;

			}

			else {

				if (!bz) {

					if (c == k) {

						res = max(res, j - i);

						break;

					}

					c++;

					bz = true;

				}

			}

		}

		if (j == n) break;

	}



	if (c <= k) {

		res = max(res, j - i);

	}

	

	cout << res << endl;



}



int main() {

	//COMinit();

	solv();



	return 0;

}
