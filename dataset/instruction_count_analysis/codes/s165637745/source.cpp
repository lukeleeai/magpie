#include <stdio.h>

#include <vector>

#include <queue>

using namespace std;



queue<int> Q;

vector<int> v[111111], p[111111];

int parent[111111], visit[111111], group[111111];



void bfs(int start)

{

	int i;



	Q.push(start);

	visit[start] = 1;

	parent[start] = start;

	while (!Q.empty())

	{

		int t = Q.front(); Q.pop();



		for (i = 0; i < p[t].size(); i++)

		{

			int next = p[t][i];



			if (!visit[next])

			{

				parent[next] = start;

				visit[next] = 1;

				Q.push(next);

			}

		}

	}

}



int main(void)

{

	int n, m, k, i, j;



	scanf("%d %d %d", &n, &m, &k);



	while (m--)

	{

		int a, b;



		scanf("%d %d", &a, &b);



		v[a].push_back(b);

		v[b].push_back(a);



		p[a].push_back(b);

		p[b].push_back(a);

	}

	while (k--)

	{

		int c, d;



		scanf("%d %d", &c, &d);



		v[c].push_back(d);

		v[d].push_back(c);

	}



	for (i = 1; i <= n; i++)

		if (!visit[i])

			bfs(i);



	for (i = 1; i <= n; i++)

		group[parent[i]]++;



	for (i = 1; i <= n; i++)

	{

		int cnt = group[parent[i]];

		

		for (j = 0; j < v[i].size(); j++)

			if (parent[v[i][j]] == parent[i])

				--cnt;

		

		printf("%d ", cnt - 1);

	}

	return 0;

}