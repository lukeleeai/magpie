#include <cstdio>

#include <iostream>

#include <algorithm>

#include <cmath>

#include <queue>

#include <cstdlib>

#include <cstring>

#include <vector>

#include <set>

#include <map>

using namespace std;

#define ll long long

#define maxn 100005

vector<int> tree[maxn];

vector<int> query[maxn];

int father[maxn];

int depth[maxn];

ll ans = 0;

int findSet(int x)//路径??

{

	if (x == father[x])

		return x;

	else

		return father[x] = findSet(father[x]);

}

void unionSet(int x, int y)//把y并到x中去

{

	int fx = findSet(x);

	int fy = findSet(y);

	if (fy == fx)

		return;

	father[fy] = fx;

}

void bfs()

{

	queue<int> Q;

	Q.push(1);

	int last = 0;

	int t;

	while (!Q.empty())

	{

		t = Q.front();

		if (last != 0)

		{

			query[last].push_back(t);

		}

		last = t;

		Q.pop();

		for (unsigned int i = 0; i < tree[t].size(); ++i)

		{

			Q.push(tree[t][i]);

		}

	}

}

void Tarjan_LCA(int u)

{

	father[u] = u;

	int t;

	for (unsigned int i = 0; i < tree[u].size(); ++i)

	{

		t = tree[u][i];

		depth[t] = depth[u] + 1;

		Tarjan_LCA(t);

		unionSet(u, t);

	}

	for (unsigned int i = 0; i < query[u].size(); ++i)

	{

		t = query[u][i];

		if (father[t] != 0)

		{

			//printf("sum %d %d\n", u, t);

			ans += (ll)depth[u] + (ll)depth[t] - 2 * (ll)depth[findSet(t)];

		}

		else

		{

			query[t].push_back(u);

		}

	}

}

int main()

{

	//freopen("input.txt", "r", stdin);

	//freopen("output.txt", "w", stdout);

	int n;

	scanf("%d", &n);

	int tmp;

	for (int i = 2; i <= n; ++i)

	{

		scanf("%d", &tmp);

		tree[tmp].push_back(i);

	}

	bfs();

	/*for (int i = 1; i <= n; ++i)

	{

		for (unsigned int j = 0; j < query[i].size(); ++j)

			printf("%d ", query[i][j]);

		printf("\n");

	}*/

	Tarjan_LCA(1);

	/*for (int i = 1; i <= n; ++i)

		printf("%d ", depth[i]);

	printf("\n");*/

	printf("%lld\n", ans);

	//system("pause");

	//while (1);

	return 0;

}