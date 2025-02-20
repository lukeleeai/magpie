#include <cstdio>
using namespace std;

int a[1001][1001], b[1001][1001], c[1001][1001];

int main() {
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);

    for(int i = 0; i < m; ++i) {
        a[i][0] = b[i][0] = c[i][0] = 0;
        for(int j = 0; j < n; ++j) {
            char p;
            scanf(" %c", &p);
            a[i][j + 1] = a[i][j] + (p == 'J');
            b[i][j + 1] = b[i][j] + (p == 'O');
            c[i][j + 1] = c[i][j] + (p == 'I');
        }
    }

    while(k--) {
        int p, q, r, s;
        scanf("%d%d%d%d", &p, &q, &r, &s);
        --p; --q;
        int d = 0, e = 0, f = 0;

        for(int j = p; j < r; ++j) {
            d += a[j][s] - a[j][q];
            e += b[j][s] - b[j][q];
            f += c[j][s] - c[j][q];
        }

        printf("%d %d %d\n", d, e, f);
    }

    return 0;
}
