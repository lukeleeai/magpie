 #define _CRT_SECURE_NO_WARNINGS

#include "stdc++.h"

#define ll long long

#define pb  push_back

#define f first

#define s second

#define mp make_pair

#define EPS 1e-6

#define all(x) x.begin(),x.end()

using namespace std;

const int mod = 1000 * 1000 * 1000 + 7;

int n , m , s;

vector<vector<int> > g(200000);

vector<int> path;

int cnt1;

int visited[200000];

void dfs(int u)

{

	//cout << u << endl;

	visited[u] = 1;



	for(int i = 0; i < g[u].size(); i++)

	{

		int v = g[u][i];

		if(!visited[v])

			dfs(v);

	}

}



int main()

{

	scanf("%d %d" , &n , &m);

	for(int i = 0; i < m; i++)

	{

		int u , v;

		scanf("%d %d" , &u , &v);

		u--;v--;

		g[u * 2].pb(v * 2 + 1);

		g[u * 2 + 1].pb(v * 2);

		g[v * 2].pb(u * 2 + 1);

		g[v * 2 + 1].pb(u * 2);

	}

	dfs(0);

	ll ans = 0;

	bool bipatride = false;

	for(int i = 0; i < 2 * n; i++)

	{

		if(!visited[i])

		{

			bipatride = true;

		}

	}

	if(!bipatride)

	{

		ans = (ll)n * (n - 1)/ 2;

		cout << ans - m;

		return 0;

	}

	else

	{

		ll ans = 0;

		ll cnt1 = 0;

		for(int i = 0; i < n; i++)

		{

			if(visited[2 * i])

			{

				cnt1++;

			}

		}

		ans = cnt1 * (n - cnt1);

		//cout << cnt1 << endl;

		for(int i = 0; i < n; i++)

		{

			if(visited[2 * i])

			{

				ans -= g[2 * i].size();

			}



		}

		cout << ans;

	}





	return 0;

}


