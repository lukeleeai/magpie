#include <stdio.h>

#include <string.h>

#include <algorithm>



using namespace std;



#define N 220

#define INF 0x3f3f3f3f



int d[N][N];

int a[N];



void floyd(int n) {

    for (int k = 1; k <= n; ++k) {

        for (int i = 1; i <= n; ++i) {

            for (int j = 1; j <= n; ++j) {

                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

            }

        }

    }

}



int main() {

    int n, m, r;

    while (scanf("%d%d%d", &n, &m, &r) != EOF) {

        for (int i = 0; i < r; ++i) scanf("%d", &a[i]); sort(a, a + r);

        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) d[i][j] = (i == j ? 0 : INF);

        for (int i = 0; i < m; ++i) {

            int u, v, w; scanf("%d%d%d", &u, &v, &w); d[u][v] = d[v][u] = w;

        }

        int res = INF;

        floyd(n);

        do {

            int tmp = 0;

            for (int i = 1; i < n; ++i) tmp += d[a[i - 1]][a[i]];

            res = min(res, tmp);

        } while (next_permutation(a, a + r));

        printf("%d\n", res);

    }

    return 0;

}
