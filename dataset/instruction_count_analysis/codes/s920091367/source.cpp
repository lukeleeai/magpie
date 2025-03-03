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

using namespace std;

#pragma GCC optimize("O3")

#pragma GCC target("sse4")



typedef double LD;

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



#define FOR(i,a,b) for(int i = (a); i < (b); ++i)

#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)

#define REP(i, t) FOR(i,0,t)

#define ALL(a) a.begin(), a.end()

#define SZ(a) (int)((a).size())

#define FILL(a, value) memset(a, value, sizeof(a))



const LD PI = acos(-1.0);

const LD EPS = 0.5;

const LL INF = 1e9;

const LL mod = 1000003;

const LL LINF = 1e18 + 10;

const LL MAX = 1e5 + 1;



int n;

int k;

VLL a;

VLL s;

VLL best;



int main()

{

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	//freopen("In.txt", "r", stdin);



	cin >> n >> k;

	a.resize(n);

	s.resize(n);

	best.resize(n);

	FOR(i, 0, n)

		cin >> a[i];



	s[0] = a[0];

	FOR(i, 1, n)

		s[i] = s[i - 1] + a[i];



	best[0] = max(0LL, a[0]);

	FOR(i, 1, n)

		best[i] = best[i - 1] + max(0LL, a[i]);



	LL ans = 0;



	FOR(i, 0, n - k + 1)

	{

		LL curr = 0;

		LL x = s[i + k - 1];

		if (i)

			x -= s[i - 1];



		curr = max(curr, x);

		if (i)

			curr += best[i - 1];



		curr += best[n - 1] - best[i + k - 1];

		ans = max(ans, curr);

	}



	cout << ans;

	cin >> n;

	return 0;

}