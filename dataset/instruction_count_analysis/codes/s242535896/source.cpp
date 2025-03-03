#include<iostream>

#include<vector>

#include<algorithm>

#include<utility>

#include<string>

#include<cmath>

#include<cstring>

#include<queue>

#include<map>

#include<climits>

#include<set>



using namespace std;

typedef pair<int, int> pii;

typedef long long int ll;

typedef pair<ll, ll> pll;

int dx[4] = { 1,0,0,-1 };

int dy[4] = { 0,1,-1,0 };

#define MOD 1000000007

#define ARRAY_MAX 100005



template<typename T> using Matrix = vector<vector<T> >;





const int INF = INT_MAX;





template< typename T >

void warshall_floyd(Matrix<T>& g, T inf) {



	for (int k = 0; k < g.size(); k++)

	{

		for (int i = 0; i < g.size(); i++)

		{

			for (int j = 0; j < g.size(); j++)

			{

				if (g[i][k] == inf || g[k][j] == inf)

				{

					//辺がない場合は最短になることはないので飛ばす

					continue;

				}

				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

			}

		}

	}

}





int main() {





	ios::sync_with_stdio(false);

	cin.tie(0);

	

	int V, E;

	cin >> V >> E;



	Matrix<int> mat(V, vector<int>(V, INF));



	for (int i = 0; i < V; i++) {

		mat[i][i] = 0;

	}



	for (int i = 0; i < E; i++)

	{

		int s, t, d;

		cin >> s >> t >> d;

		mat[s][t] = d;

	}



	warshall_floyd(mat, INF);



	for (int i = 0; i < V; i++)

	{

		if (mat[i][i] < 0)

		{

			//自分自身へのコストは始めは0

			//自身へのコストが負ならこれは途中で負のループができていることになる

			cout << "NEGATIVE CYCLE" << endl;

			return 0;

		}

	}





	for (int i = 0; i < V; i++)

	{

		for (int j = 0; j < V; j++)

		{

			if (j > 0) 

			{

				cout << " ";

			}

			if (mat[i][j] == INF)

			{

				cout << "INF";

			}

			else 

			{

				cout << mat[i][j];

			}

		}

		cout << endl;

	}  



	return 0;

}
