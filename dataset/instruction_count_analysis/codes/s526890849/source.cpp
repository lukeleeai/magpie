#include<cstdio>

#include<algorithm>

#include<queue>

using namespace std;

int n;

struct edge

{

	int e, nxt;

};

edge a[200200]; int m;

int sp[100100];

int minv[100100], maxv[100100];

int dep[100100], par[100100];

const int inf = 1000000000;

int q[100100], hd, tl;

int val[100100];

int main()

{

	int i;

	scanf("%d", &n);

	for (int i = 1; i < n; i++)

	{

		int u, v;

		scanf("%d%d", &u, &v);

		a[++m].e = v; a[m].nxt = sp[u]; sp[u] = m;

		a[++m].e = u; a[m].nxt = sp[v]; sp[v] = m;

	}

	for (int i = 1; i <= n; i++) {

		minv[i] = -inf; maxv[i] = inf;

	}

	par[1] = -1; dep[1] = 0;

	hd = 1; tl = 2;

	q[1] = 1;

	while (hd < tl)

	{

		int cur = q[hd++];

		for (int j = sp[cur]; j; j = a[j].nxt)

		{

			if (par[a[j].e]) continue;

			par[a[j].e] = cur;

			dep[a[j].e] = dep[cur] + 1;

			q[tl++] = a[j].e;

		}

	}

	scanf("%d", &m);

	bool parity_flags[2][2] = { {false, false}, {false, false} };

	for (int i = 1; i <= m; i++)

	{

		int v, p;

		scanf("%d%d", &v, &p);

		minv[v] = maxv[v] = p;

		parity_flags[dep[v] & 1][p & 1] = true;

	}

	// nodes at same depth must have same parity

	// nodes with different depth parity must have different value parity

	if ((parity_flags[0][0] && parity_flags[0][1])

		|| (parity_flags[1][0] && parity_flags[1][1])

		|| (parity_flags[0][0] && parity_flags[1][0])

		|| (parity_flags[0][1] && parity_flags[1][1]))

	{

		printf("No\n");

		return 0;

	}

	for (int i = n; i > 1; i--) // bottom up

	{

		int cur = q[i];

		if (minv[cur] > maxv[cur]) // unsatisfiable

		{

			printf("No\n");

			return 0;

		}

		if (minv[cur] != -inf)

			minv[par[cur]] = max(minv[par[cur]], minv[cur] - 1);

		if (maxv[cur] != inf)

			maxv[par[cur]] = min(maxv[par[cur]], maxv[cur] + 1);

	}

	for (int i = 1; i <= n; i++)

	{

		int cur = q[i];

		if (minv[cur] > maxv[cur]) // unsatisfiable

		{

			printf("No\n");

			return 0;

		}

		val[cur] = minv[cur]; // parity is guaranteed to be ok

		for (int j = sp[cur]; j; j = a[j].nxt)

		{

			if (a[j].e == par[cur]) continue;

			minv[a[j].e] = max(minv[a[j].e], val[cur] - 1);

			maxv[a[j].e] = min(maxv[a[j].e], val[cur] + 1);

		}

	}

	printf("Yes\n");

	for (int i = 1; i <= n; i++) printf("%d\n", val[i]);

	return 0;

}
