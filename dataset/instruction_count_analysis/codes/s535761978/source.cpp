#include <stdio.h>

#include <string.h>



#define N 110



int col[N], row[N];

char ma[N][N];



int main() {

    int m, n;

    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; ++i) scanf("%s", ma[i]);

    for (int i = 0; i < m; ++i) {

        int ok = 1;

        for (int j = 0; j < n; ++j) if (ma[i][j] != '.') { ok = 0; break; }

        if (ok) row[i] = 1;

    }

    for (int j = 0; j < n; ++j) {

        int ok = 1;

        for (int i = 0; i < m; ++i) {

            if (row[i]) continue;

            if (ma[i][j] != '.') { ok = 0; break; }

        }

        if (ok) col[j] = 1;

    }

    for (int i = 0; i < m; ++i) {

        if (row[i]) continue;

        for (int j = 0; j < n; ++j) {

            if (col[j]) continue;

            putchar(ma[i][j]);

        }

        puts("");

    }

    return 0;

}
