#define _CRT_SECURE_NO_WARNINGS

#include <vector>

#include <iostream>

#include <string.h>

#include <set>

#include <algorithm>

#include <cmath>

#include <queue>

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

const int MAXN = 100007;

const LD EPS = 1e-7;



int A[MAXN], D[MAXN], Dep[MAXN], n, k;

vector <int> G[MAXN], G1[MAXN];

queue <int> Q;

bool used[MAXN];



void dfs(int v)

{

	used[v] = true;

	REP(i, SZ(G1[v]))

	{

		int to = G1[v][i];

		if (!used[to])

		{

			dfs(to);

			Dep[v] = max(Dep[v], (Dep[to] + 1) % k);

		}

	}

}



int main()

{

	ios_base::sync_with_stdio(0);

	//freopen("In.txt", "r", stdin);

	int ans = 0, e = 0;

	cin >> n >> k;

	REP(i, n)

	{

		cin >> A[i];

		--A[i];

	}

	if (A[0] != 0)

	{

		A[0] = 0;

		ans = 1;

	}

	FOR(i, 1, n)

		G[A[i]].push_back(i);

	used[0] = true;

	D[0] = 0;

	Q.push(0);

	while(!Q.empty())

	{

		int v = Q.front();

		Q.pop();

		e = max(e, D[v]);

		REP(i, SZ(G[v]))

		{

			int to = G[v][i];

			if (!used[to])

			{

				used[to] = true;

				D[to] = D[v] + 1;

				G1[v].push_back(to);

				Q.push(to);

			}

		}

	}

	memset(used, 0, MAXN);

	dfs(0);

	REP(i, n)

	{

		if (D[i] > 1 && Dep[i] == k - 1)

			++ans;

	}

	cout << ans;

	//cout << endl; system("pause");

	return 0;

}