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

typedef pair<ll, ll> pll;

#define bit(x,v) ((ll)x << v)



const ll INF = 1000000007;

const ll MAX = 1000010;

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



struct cell {

	int x, y;

	int deep;

	cell(int x, int y, int deep) : x(x), y(y), deep(deep) {}

};



int dx[] = { -1,1,0,0 };

int dy[] = { 0,0,-1,1 };



int W, H, N;

int X1[500], X2[500], Y1[500], Y2[500];



bool fld[500 * 6][500 * 6];

int compress(int* x1, int* x2, int w) {

	vector<int> xs;

	for (int i = 0; i < N; i++)

	{

		for (int d = -1; d <= 1; d++)

		{

			int tx1 = x1[i] + d, tx2 = x2[i] + d;

			if (1 <= tx1 && tx1 <= W) xs.push_back(tx1);

			if (1 <= tx2 && tx2 <= W) xs.push_back(tx2);

		}

	}



	sort(xs.begin(), xs.end());

	xs.erase(unique(xs.begin(), xs.end()), xs.end());



	for (size_t i = 0; i < N; i++)

	{

		x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();

		x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();

	}

	return xs.size();

}

const int MAX_N = 1 << 17;

//

//int n,dat[2 * MAX_N - 1];

//

//void init(int n_) {

//	n = 1;

//	while (n < n_)

//	{

//		n *= 2;

//	}

//	for (size_t i = 0; i < 2 * n - 1; i++)

//	{

//		dat[i] = INT_MAX;

//	}

//}

//

//void update(int k, int a) {

//	k += n - 1;

//	dat[k] = a;

//	while (k > 0) {

//		k = (k - 1) / 2;

//		dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);

//	}

//}

//int query(int a, int b, int k, int l, int r) {

//	if (r <= a || b <= 1) return INT_MAX;

//

//	if (a <= l && r <= b) return dat[k];

//	else {

//		int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);

//		int vr = query(a, b, k * 2 + 1, (l + r) / 2, r);

//		return min(vl, vr);

//	}

//	

//	auto p = tie(a,b,k);

//}

ll fmemo[1000010];

ll fact(ll x) {

	if (fmemo[x] > 0) return fmemo[x];

	if (x == 0) return 1;

	fmemo[x] = (x * fact(x - 1));

	fmemo[x] %= INF;

	return fmemo[x];

}



struct edge {

	int to, cap, rev;

	edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}

};

vector<edge> es[110];

void addedge(int f, int t, int cap) {

	es[f].push_back(edge(t, cap, es[t].size()));

	es[t].push_back(edge(f, 0, es[f].size() - 1));

}

void addedge2(int f, int t, int cap) {

	es[f].push_back(edge(t, cap, es[t].size()));

	es[t].push_back(edge(f, cap, es[f].size() - 1));

}

int lev[110];

int iter[110];

void bfs(int s) {

	memset(lev, -1, sizeof(lev));

	queue<int> q;

	lev[s] = 0;

	q.push(s);

	while (!q.empty())

	{

		int p = q.front();

		q.pop();

		for (size_t i = 0; i < es[p].size(); i++)

		{

			edge ed = es[p][i];

			if (lev[ed.to] < 0 && ed.cap > 0) {

				lev[ed.to] = lev[p] + 1;

				q.push(ed.to);

			}

		}

	}

}

int dfs(int v, int t, int f) {

	if (v == t) return f;

	for (int &i = iter[v]; i < es[v].size(); i++)

	{

		edge &ed = es[v][i];

		if (ed.cap > 0 && lev[ed.to] > lev[v]) {

			int r = dfs(ed.to, t, min(ed.cap, f));

			if (r > 0) {

				ed.cap -= r;

				es[ed.to][ed.rev].cap += r;

				return r;

			}

		}

	}

	return 0;

}



int dinic(int s, int t) {

	int flow = 0;

	while (true)

	{

		bfs(s);

		if (lev[t] < 0) break;

		memset(iter, 0, sizeof(iter));

		int f;

		while ((f = dfs(s, t, INF)) > 0) {

			flow += f;

		}



	}

	return flow;

}

int p[110];

int d[100010];

void dij(int s) {



	d[s] = 0;

	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;

	q.push({0,0,s});

	while (!q.empty())

	{

		auto p = q.top();

		q.pop();

		int cou = p[0];

		int cur = p[2];

		int dis = p[1];

		if (cou > d[cur]) continue;

		for (auto v : es[cur])

		{

			int val = v.cap != dis;

			if (cou + val < d[v.to]) {

				d[v.to] = cou + val;

				q.push({ d[v.to],v.cap,v.to });

			}

		}

	}

}

void solv() {

	ll n, k;

	cin >> n >> k;

	string s;

	cin >> s;



	int st[100010];



	int rv[100010];

	memset(st, -1, sizeof(st));

	memset(rv, -1, sizeof(rv));

	int stc = 0;

	int rvc = 0;

	int sti = 0;

	int rvi = 0;

	if (s[0] == '0') {

		rv[rvi++] = 0;

	}

	for (size_t i = 0; i < s.size(); i++)

	{

		if (s[i] == '0') {

			stc++;

			if (rvc != 0) {

				rv[rvi++] = rvc;

				rvc = 0;

			}



		}

		else {

			rvc++;

			if (stc != 0) {

				st[sti++] = stc;

				stc = 0;

			}

		}

	}



	if (s[s.size() - 1] == '0') {

		st[sti++] = stc;

		rv[rvi++] = 0;

	}

	else {

		rv[rvi++] = rvc;

	}



	int std[100010];

	memset(std, 0, sizeof(std));

	for (size_t i = 0; i < sti; i++)

	{

		if (i > 0) std[i] = std[i - 1];

		std[i] += st[i];

	}



	int rvd[100010];

	memset(rvd, 0, sizeof(rvd));

	for (size_t i = 0; i < rvi; i++)

	{

		if (i > 0) rvd[i] = rvd[i - 1];

		rvd[i] += rv[i];

	}

	if (rvi <= k) {

		cout << s.size() << endl;

		return;

	}

	int res = 0;

	for (int i = 0; i < rvi - k; i++)

	{

		int p = rvd[i + k] - (i > 0 ? rvd[i - 1] : 0) 

			+ std[i + k - 1] - (i > 0 ? std[i - 1] : 0);

		res = max(res, p);

	}

	cout << res << endl;

}



int main() {

	//COMinit();

	solv();



	return 0;

}
