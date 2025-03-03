#include "stdio.h"

#include "climits"



int n, m;

int edge[101][101];

int dis[101];

bool flag[101];

int box;

int s, e, p;



int main() {

	scanf("%d %d", &n, &m);

	while (n != 0) {

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= n; j++) {

				edge[i][j] = 200000000;

			}

		}

		for (int i = 0; i < m; i++) {

			scanf("%d", &box);

			if (box == 1) {

				scanf("%d %d %d", &s, &e, &p);

				if (edge[s][e] > p) {

					edge[s][e] = p;

					edge[e][s] = p;

				}

			}

			else {

				scanf("%d %d", &s, &e);

				for (int j = 1; j <= n; j++) {

					flag[j] = true;

					dis[j] = 200000000;

				}

				dis[s] = 0;

				box = s;

				while (flag[e]) {

					flag[box] = false;

					for (int j = 1; j <= n; j++) {

						if (dis[box] + edge[box][j] < dis[j]) {

							dis[j] = dis[box] + edge[box][j];

						}

					}

					for (int j = 1; j <= n; j++) {

						if (flag[j]) {

							box = j;

							break;

						}

					}

					for (int j = box; j <= n; j++) {

						if (flag[j]) {

							if (dis[box] > dis[j])box = j;

						}

					}

				}

				if (dis[e] == 200000000)printf("-1\n");

				else printf("%d\n", dis[e]);

			}

		}

		scanf("%d %d", &n, &m);

	}

	return 0;

}