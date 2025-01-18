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



const int MAX = 1010;



VI g[MAX];

int IN[MAX];

int OUT[MAX];

bool U[MAX];



int L, R;



void no()

{

	cout<<"NO"<<endl;

	exit(0);

}



void dfs(int x)

{

	U[x] = true;



	if (x & 1)

	{

		if (IN[x] > OUT[x]) no();

		R += IN[x] - OUT[x];

	}

	else

	{

		if (OUT[x] > IN[x]) no();

		L += OUT[x] - IN[x];

	}



	FOR (i, 0, SZ(g[x]))

	{

		int to = g[x][i];

		if (U[to]) continue;

		dfs(to);

	}

}



int main()

{

	//freopen("in.txt", "r", stdin);

	//ios::sync_with_stdio(false); cin.tie(0);



	int n, m;

	scanf("%d%d", &n, &m);

	FOR (i, 0, n)

	{

		int a, b, c, d;

		scanf("%d%d%d%d", &a, &b, &c, &d);



		int x, y;

		if (d == 0) y = b * 2;

		else y = d * 2 + 1;



		if (c == 0) x = a * 2 + 1;

		else x = c * 2;



	//	cout<<x<<' '<<y<<endl;

	//	cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;



		g[x].PB(y);

		g[y].PB(x);

		OUT[x]++;

		IN[y]++;

	}



	int c1 = 0, c2 = 0;

	FOR (i, 0, MAX)

	{

		if (U[i]) continue;

		if (SZ(g[i]) == 0) continue;

		L = R = 0;



		dfs(i);



		c1++;

		if (L == 0) c2++;

	}

	//cout<<"*"<<endl;

	if (c2) no();

	cout<<"YES"<<endl;



}


