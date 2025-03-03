#include "stdc++.h"



using namespace std;



int n, m;

const int N = 100005;

vector<int> a[N];

bool d[N][2];

int vis[N][2];



void dfs(int pos)

{

	d[pos][0] = true;

	queue< pair<int, int> > q;

	q.push({pos, 0});

	vis[pos][0] = 1;

	while (q.size())

	{

		int u = q.front().first, l = q.front().second;

		q.pop();

		for (int i = 0; i < a[u].size(); i++)

		{

			int v = a[u][i];

			if (!vis[v][(l+1)%2])

			{

				vis[v][(l+1)%2] = 1;

				d[v][(l+1)%2] = true;

				q.push({v, (l+1)%2});

			}

		}

	}

}



signed main()

{

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++)

	{

		int x, y;

		scanf("%d%d", &x, &y);

		a[x].push_back(y);

		a[y].push_back(x);

	}

	for (int i = 1; i <= n; i++)

	{

		d[i][0] = d[i][1] = false;

	}

	memset(vis, 0, sizeof(vis));

	dfs(1);

	int cn1, cn2, cn3;

	cn1 = cn2 = cn3 = 0;

	for (int i = 1; i <= n; i++)

	{

		if (d[i][0] & d[i][1])

		{

			cn1 ++;

		} 

		else

		{

			if (d[i][0])

			{

				cn2 ++;

			}

			else

			{

				cn3 ++;

			}

		}

	}

	long long ans = 1ll*cn2*cn3 + 1ll*cn1*cn2 + 1ll*cn1*cn3 + 1ll*cn1*(cn1-1)/2;

	cout << ans - m;

}