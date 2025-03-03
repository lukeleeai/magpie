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



#define FOR(i, a, b) for(int i = (a); i < (b); ++i)

#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)

#define REP(i, t) FOR(i, 0, t)

#define ALL(a) a.begin(), a.end()

#define SZ(a) (int)((a).size())

#define FILL(a, value) memset(a, value, sizeof(a))



const LD PI = acos(-1.0);

const LD EPS = 1e-6;

const LL INF = 1e9;

const LL LINF = 1e18;

const LL mod = 1000000007;

const LL MAX = 2000 + 7;



int n;

int m;

int f[MAX][MAX];

int s[MAX][MAX];

int hor[MAX][MAX];

int ver[MAX][MAX];

int sum_hor[MAX][MAX];

int sum_ver[MAX][MAX];



int main()

{

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	//freopen("In.txt", "r", stdin);



	int q;

	cin >> n >> m >> q;

	char ch;

	FOR(i, 0, n)

		FOR(j, 0, m)

	{

		cin >> ch;

		f[i][j] = ch - '0';

	}



	FOR(i, 0, n)

		FOR(j, 0, m - 1)

		if (f[i][j] && f[i][j + 1])

			hor[i][j] = 1;



	FOR(i, 0, n - 1)

		FOR(j, 0, m)

		if (f[i][j] && f[i + 1][j])

			ver[i][j] = 1;



	s[0][0] = f[0][0];

	FOR(i, 1, n)

		s[i][0] = f[i][0] + s[i - 1][0];

	FOR(i, 1, m)

		s[0][i] = f[0][i] + s[0][i - 1];



	FOR(i, 1, n)

		FOR(j, 1, m)

		s[i][j] = f[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];



	sum_hor[0][0] = hor[0][0];

	sum_ver[0][0] = ver[0][0];



	FOR(i, 1, n)

		sum_hor[i][0] = hor[i][0] + sum_hor[i - 1][0];

	FOR(i, 1, m - 1)

		sum_hor[0][i] = hor[0][i] + sum_hor[0][i - 1];

	FOR(i, 1, n)

		FOR(j, 1, m - 1)

		sum_hor[i][j] = hor[i][j] + sum_hor[i - 1][j] + sum_hor[i][j - 1] - sum_hor[i - 1][j - 1];



	FOR(i, 1, n - 1)

		sum_ver[i][0] = ver[i][0] + sum_ver[i - 1][0];

	FOR(i, 1, m)

		sum_ver[0][i] = ver[0][i] + sum_ver[0][i - 1];

	FOR(i, 1, n - 1)

		FOR(j, 1, m)

		sum_ver[i][j] = ver[i][j] + sum_ver[i - 1][j] + sum_ver[i][j - 1] - sum_ver[i - 1][j - 1];



	int x1, y1, x2, y2;

	REP(Q, q)

	{

		cin >> x1 >> y1 >> x2 >> y2;

		--x1, --x2;

		--y1, --y2;

		int blue = s[x2][y2];

		if (x1)

			blue -= s[x1 - 1][y2];

		if (y1)

			blue -= s[x2][y1 - 1];

		if (x1 && y1)

			blue += s[x1 - 1][y1 - 1];



		int edges_hor = 0, edges_ver = 0;

		

		if (y1 < y2)

		{

			--y2;

			edges_hor = sum_hor[x2][y2];

			if (x1)

				edges_hor -= sum_hor[x1 - 1][y2];

			if (y1)

				edges_hor -= sum_hor[x2][y1 - 1];

			if (x1 && y1)

				edges_hor += sum_hor[x1 - 1][y1 - 1];

			++y2;

		}



		if (x1 < x2)

		{

			--x2;

			edges_ver = sum_ver[x2][y2];

			if (x1)

				edges_ver -= sum_ver[x1 - 1][y2];

			if (y1)

				edges_ver -= sum_ver[x2][y1 - 1];

			if (x1 && y1)

				edges_ver += sum_ver[x1 - 1][y1 - 1];

			++x2;

		}



		cout << blue - edges_hor - edges_ver << endl;

	}



	cin >> n;

	return 0;

}