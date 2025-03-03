#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/stack:16777216")

#include <string>

#include <vector>

#include <map>

#include <list>

#include <iterator>

#include <cassert>

#include <set>

#include <queue>

#include <iostream>

#include <sstream>

#include <stack>

#include <deque>

#include <cmath>

#include <memory.h>

#include <cstdlib>

#include <cstdio>

#include <cctype>

#include <algorithm>

#include <utility>

#include <time.h>

#include <complex>

using namespace std;



#define FOR(i,a,b) for(int i = (a); i < (b); i++)

#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)

#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

#define FILL(a, value) memset(a, value, sizeof(a))



#define SZ(a) (int) a.size()

#define ALL(a) a.begin(),a.end()

#define PB push_back

#define MP make_pair



typedef long long LL;

typedef vector<int> VI;

typedef pair<int, int> PII;



const double PI = acos(-1.0);

const LL INF = 1000 * 1000 * 1000 + 7;

const LL LINF = INF * (LL)INF;



const int MOD = 1000 * 1000 * 1000 + 7;



typedef vector<VI> matr;



matr get(int n)

{

	return matr(n, VI(n, 0));

}



matr mul(matr a, matr b)

{

	int n = SZ(a);

	matr res = get(n);

	FOR (i, 0, n)

	{

		FOR (j, 0, n)

		{

			FOR (k, 0, n)

			{

				res[i][j] = (res[i][j] + a[i][k] * (LL)b[k][j]) % MOD;

			}

		}

	}



	return res;

}



matr bpow(matr a, LL b)

{

	matr res = get(SZ(a));

	FOR (i, 0, SZ(a))

	{

		res[i][i] = 1;

	}



	while(b)

	{

		if (b & 1) res = mul(res, a);

		a = mul(a, a);

		b /= 2;

	}

	return res;

}



const int MAX = 1010;



string S[MAX];



int main()

{

	//freopen("in.txt","r", stdin);

	//ios::sync_with_stdio(false); cin.tie(0);



	int h, w;

	LL n;

	cin>>h>>w>>n;



	int k = 0;

	int hh = 0;

	int v = 0;



	int a = 0;

	int b = 0;



	FOR (i, 0, h)

	{

		cin>>S[i];

	}



	FOR (i, 0, h)

	{

		FOR (j, 0, w)

		{

			if (S[i][j] == '#') k++;

			if (j + 1 < w && S[i][j] == '#' && S[i][j+1] == '#') hh++;

			if (i + 1 < h && S[i][j] == '#' && S[i+1][j] == '#') v++;

		}

	}



	FOR (i, 0, h)

	{

		if (S[i][0] == '#' && S[i][w-1] == '#') a++;

	}



	FOR (j, 0, w)

	{

		if (S[0][j] == '#' && S[h-1][j] == '#') b++;

	}



	if (a > 0 && b > 0)

	{

		cout<<1<<endl;

		return 0;

	}



	if (a == 0 && b == 0)

	{

		matr a = get(1);

		a[0][0] = k;

		a = bpow(a, n - 1);

		cout<<a[0][0]<<endl;

		return 0;

	}



	if (a == 0)

	{

		swap(a, b);

		swap(hh, v);

	}



	matr A = get(2);

	A[0][0] = k;

	A[1][0] = hh;

	A[1][1] = a;



	A = bpow(A, n-1);

	int res = A[0][0] - A[1][0];

	if (res < 0) res += MOD;

	res %= MOD;

	cout<<res<<endl;







}
