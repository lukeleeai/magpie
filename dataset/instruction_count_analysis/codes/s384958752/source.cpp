#include <stdio.h>

#include <vector>

using namespace std;

int n, m;

int x, y, z;

int c;

vector<int> g[100000];

int s[100000];

void dfs(int a, int b) {

	s[a] = 1;

	for (int i = 0; i < g[a].size(); i++) {

		if (g[a][i] != b && s[g[a][i]] == 0)dfs(g[a][i], a);

	}

}

int main() {

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {

		scanf("%d%d%d", &x, &y, &z);

		x--; y--;

		g[x].push_back(y);

		g[y].push_back(x);

	}

	for (int i = 0; i < n; i++) {

		if (s[i] == 0) {

			c++;

			dfs(i, i);

		}

	}

	printf("%d\n", c);

}