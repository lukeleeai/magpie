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



string s;

int n;



string n9;



string add(string& x, string& y)

{

	int sz1 =  max(SZ(x), SZ(y));

	int sz2 = min(SZ(x), SZ(y));



	string z;

	int carry = 0;

	int dx = sz1 - SZ(x);

	int dy = sz1 - SZ(y);



	RFOR(i, sz1, max(dx, dy))

	{

		int now = 0;

		now += (x[i - dx] - '0');

		now += (y[i - dy] - '0');



		if (now + carry > 9)

		{

			z.push_back('0' + (now + carry) % 10);

			carry = 1;

		}

		else

		{

			z.push_back('0' + (now + carry) % 10);

			carry = 0;

		}

	}



	RFOR(i, max(dx, dy), 0)

	{

		int now = 0;

		if (SZ(x) > SZ(y))

			now += (x[i - dx] - '0');

		else

			now += (y[i - dy] - '0');



		if (now + carry > 9)

		{

			z.push_back('0' + (now + carry) % 10);

			carry = 1;

		}

		else

		{

			z.push_back('0' + (now + carry) % 10);

			carry = 0;

		}

	}



	if (carry)

		z.push_back('1');



	reverse(ALL(z));

	return z;

}



bool can(int k)

{

	k *= 9;

	string res;

	string K = to_string(k);

	res = add(n9, K);

	int ans = 0;

	FOR(i, 0, SZ(res))

		ans += (res[i] - '0');

	return ans <= k;

}



int main()

{

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	//freopen("In.txt", "r", stdin);



	cin >> s;

	n = SZ(s);

	n9 = s;

	string rr = n9;

	FOR(i, 0, 8)

		n9 = add(n9, s);



	//cout << n9 << endl;

	int L = 1, R = n, M;

	while (R - L > 1)

	{

		M = (L + R) >> 1;

		if (can(M))

			R = M;

		else

			L = M;

	}



	if (can(L))

		M = L;

	else

		M = R;



	cout << M << endl;

	cin >> n;

	return 0;

}