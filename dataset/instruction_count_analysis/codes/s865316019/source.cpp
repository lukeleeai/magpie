#include<cstdio>

int n, m;

int deg[100100];

int main()

{

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= m; i++)

	{

		int u, v;

		scanf("%d%d", &u, &v);

		deg[u]++; deg[v]++;

	}

	bool flag = false;

	for (int i = 1; i <= n; i++)

	{

		if (deg[i] & 1) { flag = true; break; }

	}

	if (flag) printf("NO\n");

	else printf("YES\n");

	return 0;

}
