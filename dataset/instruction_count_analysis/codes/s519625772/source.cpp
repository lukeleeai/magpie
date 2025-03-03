

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#include <vector>

#include <string>

#include <iostream>

#include <algorithm>

#include <map>

#include <iterator>

#include <functional>

#include <set>

#include <stack>

#include <queue>

#include <deque>

#include <fstream>

#include <iomanip>

#include <unordered_map>

#include <unordered_set>

#include <numeric>

#include <cmath>

#include <list>

#include <sstream>

#include <tuple>

#include <complex>

#include <stdio.h>

using namespace std;

#pragma GCC optimize("O3")

#pragma GCC target("sse4")



typedef double LD;

typedef long long LL;

typedef pair<int, int> PII;

typedef pair<LD, LD> PDD;

typedef pair<LL, LL> PLL;

typedef vector<int> VI;

typedef vector<LL> VLL;

typedef vector<char> VCH;

typedef vector<LD> VLD;

typedef vector<VI> VVI;

typedef vector<VLL> VVLL;

typedef vector<VCH> VVCH;

typedef vector<PII> VPII;

typedef vector<PLL> VPLL;

typedef vector<PDD> VPDD;

#define MP make_pair

#define PB push_back

#define X first

#define Y second

#define next fake_next

#define prev fake_prev

#define left fake_left

#define right fake_right



#define FOR(i,a,b) for(int i = (a); i < (b); ++i)

#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)

#define REP(i, t) FOR(i,0,t)

#define ALL(a) a.begin(), a.end()

#define SZ(a) (int)((a).size())



const LD PI = acos(-1.0);

const LL mod = 1000000007;

const LL INF = 1e9;

const LL MAXN = 100001;



int n;

VI a;

VI b;



bool can(int x)

{

	a = b;

	FOR(i, 0, n)

		if (a[i] < x)

			a[i] = 0;

		else

			a[i] = 1;



	if (a[n / 2] == a[n / 2 - 1])

		return a[n/2];



	VI ok;

	FOR(i, 0, n - 1)

		if (a[i] == a[i + 1])

			ok.push_back(i);

	

	if (SZ(ok) == 0)

		return a[0];



	VI dist(SZ(ok));

	FOR(i, 0, SZ(ok))

		if (ok[i] >= n / 2)

			dist[i] = ok[i] - n / 2;

		else

			dist[i] = n / 2 - 1 - ok[i];

	

	int best = dist[0];

	FOR(i, 1, SZ(ok))

		best = min(best, dist[i]);



	FOR(i, 0, SZ(ok))

		if (best == dist[i])

			return a[ok[i]];



	throw - 1;

}



int main()

{

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	//freopen("In.txt", "r", stdin);



	cin >> n;

	n = 2 * n - 1;

	a.assign(n, 0);

	FOR(i, 0, n)

		cin >> a[i];



	b = a;

	int L = 0, R = n, M;

	while (R - L > 1)

	{

		M = (L + R) / 2;

		if (can(M))

			L = M;

		else

			R = M;

	}

	if (can(L))

		cout << L;

	else

		cout << R;



	//cin >> n;

	return 0;

}