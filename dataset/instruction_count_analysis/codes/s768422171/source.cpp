#pragma once

#include <sstream>

#include <string>

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

#include <numeric>

#include <iomanip>

#define M_PI acos(-1)

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const int INF = 1000000007;

const int MAX_V = 201;

int now = 0;



const int MAX = 510000;

const int MOD = 1000000007;



long long fac[MAX], finv[MAX], inv[MAX];



// テーブルを作る前処理

void COMinit() {

	fac[0] = fac[1] = 1;

	finv[0] = finv[1] = 1;

	inv[1] = 1;

	for (int i = 2; i < MAX; i++) {

		fac[i] = fac[i - 1] * i % MOD;

		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;

		finv[i] = finv[i - 1] * inv[i] % MOD;

	}

}



// 二項係数計算

long long COM(int n, int k) {

	if (n < k) return 0;

	if (n < 0 || k < 0) return 0;

	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;

}

struct edge {

	int t;

	edge(int _t) : t(_t) {}

};

bool use[100010];





vector<edge> te[100010];

vector<edge> fe[100010];



void Solve() {



	int n,c;

	cin >> n >> c;

	int ct[31][31];

	for (size_t i = 1; i <= c; i++)

	{

		for (size_t j = 1; j <= c; j++)

		{

			cin >> ct[i][j];

		}

	}



	vector<int> values[3];

	for (size_t i = 1; i <= n; i++)

	{

		for (size_t k = 1; k <= n; k++)

		{

			int v;

			cin >> v;

			values[(i + k) % 3].push_back(v);

		}

	}

	ll zerot[31];

	ll ont[31];

	ll tt[31];

	for (size_t i = 1; i <= c; i++)

	{

		zerot[i] = 0;

		for (size_t j = 0; j < values[0].size(); j++)

		{

			zerot[i] += ct[values[0][j]][i];

		}

		ont[i] = 0;

		for (size_t j = 0; j < values[1].size(); j++)

		{

			ont[i] += ct[values[1][j]][i];

		}

		tt[i] = 0;

		for (size_t j = 0; j < values[2].size(); j++)

		{

			tt[i] += ct[values[2][j]][i];

		}

	}



	ll best = zerot[1] + ont[2] + tt[3];

	for (size_t i = 1; i <= c; i++)

	{

		for (size_t j = 1; j <= c; j++)

		{

			for (size_t k = 1; k <= c; k++)

			{

				if (i == j) continue;

				if (i == k) continue;

				if (j == k) continue;

				best = min(best, zerot[i] + ont[j] + tt[k]);

			}

		}

	}

	cout << best << endl;

}





int main() {

	Solve();

	return 0;

}


