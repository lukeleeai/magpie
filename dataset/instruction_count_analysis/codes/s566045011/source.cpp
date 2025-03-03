#define _CRT_SECURE_NO_WARNINGS

#include <vector>

#include <iostream>

#include <string.h>

#include <set>

#include <algorithm>

#include <cmath>

#include <string>

using namespace std;



typedef double LD;

typedef long long LL;

typedef pair<int, int> PII;

#define MP make_pair

#define PB push_back

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)

#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)

#define REP(i, t) FOR(i,0,t)

#define ALL(a) a.begin(), a.end()

#define SZ(a) (int)((a).size())



const LL MOD = 1000000007;

const int INF = 1e9;

const LL LINF = 1LL * INF * INF;

const int MAXN = 2007;

const LD EPS = 1e-7;



int n, A[MAXN];

bool used[MAXN];

vector <int> B[MAXN];

bool G[MAXN][MAXN];



int gcd(int a, int b)

{

	if (a == 0) return b;

	return gcd(b % a, a);

}



void dfs(int v)

{

	vector <int> C, P;

	used[v] = true;

	REP(i, n)

	{

		if (G[v][i] && !used[i])

		{

			C.push_back(i);

			dfs(i);

		}

	}

	P.resize(SZ(C));

	B[v].push_back(A[v]);

	while (true)

	{

		int mx = 0, c;

		REP(i, SZ(C))

		{

			if (P[i] < SZ(B[C[i]]) && B[C[i]][P[i]] > mx)

			{

				mx = B[C[i]][P[i]];

				c = i;

			}

		}

		if (mx == 0) break;

		B[v].push_back(mx);

		++P[c];

	}

}



int main()

{

	ios_base::sync_with_stdio(0);

	//freopen("In.txt", "r", stdin);

	cin >> n;

	REP(i, n) cin >> A[i];

	sort(A, A + n);

	REP(i, n)

	{

		REP(j, i)

			if (gcd(A[i], A[j]) > 1)

				G[i][j] = G[j][i] = true;

		G[i][n] = G[n][i] = true;

	}

	dfs(n);

	FOR(i, 1, n + 1)

		cout << B[n][i] << ' ';

	//cout << endl; system("pause");

	return 0;

}