#include <cstdio>



struct Edge {

	int u, v, w;

	Edge(int a = 0, int b = 0, int c = 0) {

		u = a, v = b, w = c;

	}

} edge[100];



int main() {

	int n, ct = 0;

	scanf("%d", &n);

--n;

	int cur = 20;

	while (n) {

		edge[ct++] = Edge(cur - 1, cur, (n + 2) / 2);

		edge[ct++] = Edge(cur - 1, cur, 1 - n % 2);

		if (n % 2 == 0)

			edge[ct++] = Edge(1, cur, 0);

		n = (n - 1) / 2;

		--cur;

	}

	for (int i = 1; i < cur; ++i)

		edge[ct++] = Edge(i, i + 1, 0);

	printf("20 %d\n", ct);

	for (int i = 0; i < ct; ++i)

		printf("%d %d %d\n", edge[i].u, edge[i].v, edge[i].w);

	return 0;

}