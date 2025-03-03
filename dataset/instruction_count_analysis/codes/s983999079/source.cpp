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

#include <numeric>

#include <cmath>

#include <list>

#include <sstream>

#include <cstring>

#include <stdio.h>

#include <complex>

using namespace std;

#pragma GCC optimize("O3")

#pragma GCC target("sse4")



typedef long double LD;

typedef long long LL;

typedef unsigned long long ULL;

typedef pair<int, int> PII;

typedef pair<LD, LD> PDD;

typedef pair<LL, LL> PLL;

typedef vector<int> VI;

typedef vector<LL> VLL;

typedef vector<char> VCH;

typedef vector<LD> VLD;

typedef vector<string> VS;

typedef vector<VS> VSS;

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



#define FOR(i, a, b) for(LL i = (a); i < (b); ++i)

#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)

#define REP(i, t) FOR(i, 0, t)

#define ALL(a) a.begin(), a.end()

#define SZ(a) (int)((a).size())

#define FILL(a, value) memset(a, value, sizeof(a))



const LD PI = acos(-1.0);

const LD EPS = 1e-9;

const LL INF = 1e9;

const LL LINF = 1e18;

const LL mod = 1000000007;

const LL MAXN = 1e5 + 47;

const LL MAX = 1e5 + 47;



LL n;

VI g[MAX];

char used[MAX];

bool dw;



void dfs(int v, char color = 1)

{

	used[v] = color;

	for (auto i : g[v])

	{

		if (used[i] == 0)

			dfs(i, 3 - color);



		if (used[i] == used[v])

			dw = 0;

	}

}



int main()

{

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	//freopen("In.txt", "r", stdin);



	LL u, v, m;

	cin >> n >> m;

	FOR(i, 0, m)

	{

		cin >> u >> v;

		--u; --v;

		g[u].push_back(v);

		g[v].push_back(u);

	}



	LL l = 0, k = 0;

	LL ans = 0;

	m = n;

	FOR(i,0,n)

		if (SZ(g[i]) == 0)

		{

			ans += 2LL * m - 1;

			--m;

		}

		else

		{

			if (used[i])

				continue;

		

			dw = 1;

			dfs(i, 1);

			if (dw)

				++k;

			else

				++l;

		}



	ans += 2 * k*k;

	ans += l * l;

	ans += 2 * k*l;

	cout << ans;

	cin >> n;	

	return 0;

}