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



// 二項係数計算

long long COM(int n, int k) {

	if (n < k) return 0;

	if (n < 0 || k < 0) return 0;

	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;

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

const ll ainf = 998244353;

string calc(string v, char in) {

	string res = v + in;

	sort(res.begin(), res.end(),greater<char>());

	return res;

}

ll calc(ll p, ll s1, ll s2, ll t1, ll t2) {

	ll dis1 = p - s1;

	ll dis2 = p - t1;

	ll dis3 = s2 - p;

	ll dis4 = t2 - p;

	ll res = min(dis1 * 2 + dis4,

		min(dis4 * 2 + dis1,

			min(dis2 * 2 + dis3, dis3 * 2 + dis2)));



	if (s1 < t1) {

		res = min(res, dis1);

	}

	else res = min(res, dis2);



	if (s2 > t2) {

		res = min(res, dis3);

	}

	else res = min(res, dis4);

	return res;

}

void solv() {

	int a, b, q;

	cin >> a >> b >> q;

	ll s[100010];

	s[0] = -(INF * 10);

	s[a + 1] = (INF * 10) * 2;

	for (size_t i = 1; i <= a; i++) cin >> s[i];

	sort(s, s + a + 2);

	ll t[100010];

	t[0] = -(INF * 10);

	t[b + 1] = (INF * 10) * 2;

	for (size_t i = 1; i <= b; i++)	cin >> t[i];

	sort(t, t + b + 2);

	ll x[100010];

	for (size_t i = 0; i < q; i++) cin >> x[i];



	for (size_t i = 0; i < q; i++)

	{

		ll *sp1 = lower_bound(s, s + a + 2, x[i]);

		ll *tp1 = lower_bound(t, t + b + 2, x[i]);

		ll sp1v = *sp1;

		sp1--;

		ll tp1v = *tp1;

		tp1--;

		cout << calc(x[i], *sp1, sp1v, *tp1, tp1v) << endl;

	}

}



int main() {

	//COMinit();

	solv();



	return 0;

}
