#include <algorithm>
#include <cstdio>

const int INF = 1 << 29;

int n, m;
int d[2][3000 * 3000];  // Use a single dimensional array

inline int index(int i, int j) {
    return i * n + j;  // Linearize the 2D index
}

int main() {
    while (scanf("%d %d", &n, &m), n | m) {
        std::fill(d[0], d[0] + n * n, INF);  // Initialize all to INF
        std::fill(d[1], d[1] + n * n, INF);

        for (int i = 0; i != n; ++i) {
            d[0][index(i, i)] = d[1][index(i, i)] = 0;  // Distance to self is 0
        }

        for (int i = 0; i != n; ++i) {
            int a, b, c, t;
            scanf("%d %d %d %d", &a, &b, &c, &t);
            d[0][index(a-1, b-1)] = d[0][index(b-1, a-1)] = c;
            d[1][index(a-1, b-1)] = d[1][index(b-1, a-1)] = t;
        }

        for (int k = 0; k != n; ++k)
            for (int i = 0; i != n; ++i)
                for (int j = 0; j != n; ++j) {
                    d[0][index(i, j)] = std::min(d[0][index(i, j)], d[0][index(i, k)] + d[0][index(k, j)]);
                    d[1][index(i, j)] = std::min(d[1][index(i, j)], d[1][index(i, k)] + d[1][index(k, j)]);
                }

        int k;
        scanf("%d", &k);
        while (k--) {
            int p, q, r;
            scanf("%d %d %d", &p, &q, &r);
            printf("%d\n", d[r][index(p-1, q-1)]);
        }
    }
    return 0;
}
