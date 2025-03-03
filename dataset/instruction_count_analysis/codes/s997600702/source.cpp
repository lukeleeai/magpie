#include <cstdio>

#define maxn 100010

int cnt[2][maxn], M[2], Q[2], m[2], q[2];

int n;

int main() {

    scanf("%d", &n);

    for (int i = 1, x, p; i <= n; i++) {

        scanf("%d", &x); p = i % 2;

        cnt[p][x]++;

        if (M[p] < cnt[p][x]) M[p] = cnt[p][x], Q[p] = x;

    }

    if (Q[0] != Q[1]) {

        printf("%d\n", n - M[0] - M[1]);

        return 0;

    }

    for (int i = 1; i <= 100000; i++) {

        if (m[0] < cnt[0][i] && i != Q[0]) m[0] = cnt[0][i], q[0] = i;

        if (m[1] < cnt[1][i] && i != Q[1]) m[1] = cnt[1][i], q[1] = i;

    }

    if (M[0] - m[0] > M[1] - m[1]) printf("%d\n", n - M[0] - m[1]);

    else printf("%d\n", n - m[0] - M[1]);

    return 0;

}