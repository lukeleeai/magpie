#include <iostream>



#include <vector>



#include <queue>



using namespace std;



const int N = 1000 * 1000 * 1000 + 7;

vector<int> adj[200005];

int dis[200005];

queue<int> q;

int main()

{

	int n, m;

	cin >> n;

	cin >> m;

	for(int i = 0; i < m; i ++)

	{

		int x, y;

		cin >> x;

		cin >> y;

		adj[x].push_back(y);

		adj[y].push_back(x);

	}

	for(int i = 2; i <= n; i ++)

	{

		dis[i] = N;

	}

	dis[1] = 0;

	q.push(1);

	while(q.size())

	{

		int v = q.front();

		q.pop();

		for(int i = 0; i < adj[v].size(); i ++)

		{

			if(dis[adj[v][i]] == N)

			{

				dis[adj[v][i]] = dis[v] + 1;

				q.push(adj[v][i]);

			}

		}

	}

	if(dis[n] == 2)

	{

		cout << "POSSIBLE";

	}

	else

	{

		cout << "IMPOSSIBLE";

	}

	return 0;

}