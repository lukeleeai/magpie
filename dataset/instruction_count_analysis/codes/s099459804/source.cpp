#include <cstdio>

#include <vector>

#pragma warning(disable : 4996)

using namespace std;

int n, id, c, p[100009], d[100009]; vector<int> child[100009]; bool vis[100009];

void rec(int pos) {

	vis[pos] = true;

	for (int i : child[pos]) rec(i);

}

void solve(int pos) {

	for (int i : child[pos]) {

		d[i] = d[pos] + 1;

		p[i] = pos;

		solve(i);

	}

}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		scanf("%d%d", &id, &c);

		child[id].resize(c);

		for (int j = 0; j < c; j++) {

			scanf("%d", &child[id][j]);

		}

	}

	int root = -1;

	for (int i = 0; i < n; i++) {

		if (!vis[i]) {

			root = i;

			rec(i);

		}

	}

	solve(root); p[root] = -1;

	for (int i = 0; i < n; i++) {

		printf("node %d: parent = %d, depth = %d, %s, [", i, p[i], d[i], (i == root ? "root" : (child[i].size() ? "internal node" : "leaf")));

		for (int j = 0; j < child[i].size(); j++) {

			if (j) printf(", ");

			printf("%d", child[i][j]);

		}

		printf("]\n");

	}

	return 0;

}