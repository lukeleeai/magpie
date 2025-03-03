#include "stdc++.h"

using namespace std;



const int MAXN = 50;

char mat[MAXN][MAXN];

int mark[MAXN][MAXN];

int adj[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};



int bfs(int yi, int xi){

	memset(mark, -1, sizeof(mark));

	queue<pair<int, int>> Q;

	Q.push({yi, xi});

	mark[yi][xi] = 0;

	int resp = -1;

	while(!Q.empty()){

		pair<int, int> v = Q.front();

		//cout << "---> " << "( " << v.first << " , " << v.second << " )   " << mark[v.first][v.second] << "\n";

		Q.pop();



		for (int k = 0; k < 4; k++){

			int y = v.first + adj[0][k];

			int x = v.second + adj[1][k];



			if (mark[y][x] == -1 && mat[y][x] == '.'){

				Q.push({y, x});

				mark[y][x] = mark[v.first][v.second] + 1;

				resp = mark[y][x];

			}

		}

	}

	return resp;

}



int main(){

	int h, w;

	memset(mat, 0, sizeof(mat));

	scanf("%d %d%*c", &h, &w);

	for (int i = 1; i <= h; i++){

		for (int j = 1; j <= w; j++)

			scanf("%c", &mat[i][j]);

		scanf("%*c");

	}

	

	int ans = -1;

	for (int i = 1; i <= h; i++){

		for (int j = 1; j <= w; j++){

			if (mat[i][j] == '.'){

				ans = max(ans, bfs(i, j));

				//cout << "( " << i << " , " << j << " )\n";

			}

		}

	}

	printf("%d\n", ans);

	return 0;

}