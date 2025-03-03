#include<iostream>

#include<vector>

#include<string>

#include<algorithm>

#include<stdio.h>

#include<queue>

#include<list>

using namespace std;

#define LL long long

#define INF 20001

struct e{

	int cost, to;

};

int main(){

	int n, m, c, s, g;

	while (1){

		cin >> n >> m >> c >> s >> g;

		if (n + m + c + s + g == 0)return 0;



		vector<vector<vector<int>>> edge(c + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INF)));

		for (auto &i : edge)

		{

			for (int j = 1; j <= n; j++)

				i[j][j] = 0;

		}

		for (int i = 0; i < m; i++)

		{

			int x, y, d, cc;

			cin >> x >> y >> d >> cc;

			edge[cc][x][y] = edge[cc][y][x] = min(edge[cc][x][y], d);

		}

		for (int cc = 1; cc <= c; cc++)

		{

			for (int k = 1; k <= n; k++)for (int j = 1; j <= n; j++)for (int i = 1; i <= n; i++)edge[cc][i][j] = min(edge[cc][i][j], edge[cc][i][k] + edge[cc][k][j]);

		}

		vector<vector<int>> cost(c + 1, vector<int>(20002, 0));

		vector<int> p(c + 1);

		for (int i = 1; i <= c; i++)

		{

			cin >> p[i];

		}

		vector<vector<int>> q(c + 1);

		vector<vector<int>> r(c + 1);

		for (int cc = 1; cc <= c; cc++){

			q[cc].resize(p[cc]);

			q[cc][0] = 0;

			for (int i = 1; i < p[cc]; i++)

				cin >> q[cc][i];

			r[cc].resize(p[cc] + 1);

			for (int i = 1; i <= p[cc]; i++){

				cin >> r[cc][i];

			}

			q[cc].push_back(20000);



			

		}

		for (int cc = 1; cc <= c; cc++){

			for (int i = 1; i <= p[cc]; i++)

			for (int j = q[cc][i - 1] + 1; j <= q[cc][i]; j++)

				cost[cc][j] = cost[cc][j - 1] + r[cc][i];

			cost[cc][INF] = INF*INF;



		}

		vector<vector<int>> d(n + 1, vector<int>(n + 1));

		for (int i = 1; i <= n; i++)

		for (int j = 1; j <= n; j++){

			if (i == j){

				d[i][j] = 0;

				continue;

			}

			d[i][j] = INF*INF;

			for (int cc = 1; cc <= c; cc++)

				d[i][j] = min(d[i][j], cost[cc][edge[cc][i][j]]);



		}

		for (int k = 1; k <= n; k++)for (int j = 1; j <= n; j++)for (int i = 1; i <= n; i++)d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

		if (d[s][g] >= INF*INF)cout << -1 << endl;

		else cout << d[s][g] << endl;

		

	}



}