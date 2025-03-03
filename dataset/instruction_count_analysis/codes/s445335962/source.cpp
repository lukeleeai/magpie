#pragma once

#include <stdio.h>

#include <sstream>

#include <string>

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

const int MAX = 210000;

const int MOD = 1000000007;



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

vector<vector<int> > calcNext(const string& S) {

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

ll slide(vector<ll>& v, ll a, ll b) {

	ll azv = abs(v[0] - a);

	ll bzv = abs(v[0] - b);

	ll aov = abs(v[1] - a);

	ll bov = abs(v[1] - b);

	v[0] = a;

	v[1] = b;

	return max((azv + bov), (bzv + aov));

}





void solv() {



	int n, c;

	cin >> n >> c;



	int ta[3][35];

	memset(ta, 0, sizeof(ta));

	int col[31][31];

	for (size_t i = 1; i <= c; i++)

	{

		for (size_t j = 1; j <= c; j++)

		{

			cin >> col[i][j];

		}

	}



	for (size_t i = 1; i <= n; i++)

	{

		for (size_t j = 1; j <= n; j++)

		{

			int p;

			cin >> p;

			ta[(i + j) % 3][p]++;

		}

	}



	int tp[3][35];

	memset(tp, 0, sizeof(tp));

	for (size_t i = 0; i < 3; i++)

	{

		for (size_t j = 1; j <= c; j++)

		{

			for (size_t k = 1; k <= c; k++)

			{

				tp[i][j] += ta[i][k] * col[k][j];

			}

		}

	}



	int res = INF;

	for (size_t i = 1; i <= c; i++)

	{

		for (size_t j = 1; j <= c; j++)

		{

			for (size_t k = 1; k <= c; k++)

			{

				if (i == j) continue;

				if (j == k) continue;

				if (i == k) continue;

				res = min(res, tp[0][i] + tp[1][j] + tp[2][k]);

			}



		}



	}

	cout << res << endl;

}

int main(){

	solv();



	return 0;

}
