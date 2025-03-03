#include "stdc++.h"

using namespace std;



#define FOR(i,a,b) for (int i = (a); i < (b); i++)

#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)

#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)

#define FILL(a,value) memset(a, value, sizeof(a))



#define SZ(a) (int)a.size()

#define ALL(a) a.begin(), a.end()

#define PB push_back

#define MP make_pair



typedef long long LL;

typedef vector<int> VI;

typedef pair<int, int> PII;



const double PI = acos(-1.0);

const int INF = 1000 * 1000 * 1000 + 7;

const LL LINF = INF * (LL) INF;



const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX = 16;



VI g[MAX];

int DP[(1<<MAX) + 47];

int n;



int get(int mask)

{

	if (mask == 0) return 1;

	if (DP[mask] != -1) return DP[mask];



	int res = 0;

	int m = mask;

	while(true)

	{

		if (m == 0) break;

		int v1 = (m & 1) > 0;

		int v2 = (m & 2) > 0;

		if (v1 == v2)

		{

			int cur = 1;

			FOR (i, 0, n)

			{

				if (!(mask & (1<<i))) continue;

				if (m & (1<<i)) continue;



				int cnt = 0;

				FOR (j, 0, SZ(g[i]))

				{

					int to = g[i][j];

					if (m & (1<<to)) cnt++;

				}



				cur = (cur * (LL)((1 << cnt) - 1)) % MOD;

			}



			FOR (i, 0, n)

			{

				if (!(m & (1<<i))) continue;



				int cnt = 0;

				FOR (j, 0, SZ(g[i]))

				{

					int to = g[i][j];

					if (mask & (1<<to))

					{

						if (!(m & (1<<to))) cnt++;

					}

				}



				cur = (cur * (LL)(1<<cnt)) % MOD;

			}



			cur = (cur * (LL)get(mask ^ m)) % MOD;



			res = (res + cur) % MOD;

		}



		m = (m - 1) & mask;

	}



	return DP[mask] = res;

}



int main()

{

	//freopen("in.txt", "r", stdin);

	//ios::sync_with_stdio(false); cin.tie(0);



	int m;

	scanf("%d%d", &n, &m);

	FOR (i, 0, m)

	{

		int x, y;

		scanf("%d%d", &x, &y);

		x--;

		y--;



		g[x].PB(y);

	}



	FILL(DP, -1);



	int res = get((1<<n) - 1);



	int p2 = 1;

	FOR (i, 0, m)

	{

		p2 *= 2;

		p2 %= MOD;

	}



	res = p2 - res + MOD;

	res %= MOD;



	cout<<res<<endl;

}


