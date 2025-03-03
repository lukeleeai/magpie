#include "stdc++.h"

using namespace std;

#define N 100000



int n, f[N * 2 + 5], cx[N * 2 + 5], cy[N * 2 + 5];



int find(int x) {

    return x == f[x] ? x : f[x] = find(f[x]);

}



int main() {

#ifdef whyqx

    freopen("work.in", "r", stdin);

    freopen("work.out", "w", stdout);

#endif

    cin >> n;

    for (int i = 1; i <= N << 1; ++i)

        f[i] = i;

    for (int i = 1; i <= n; ++i) {

        int x, y;

        scanf("%d%d", &x, &y);

        f[find(x)] = find(y + N);

    }

    for (int i = N + 1; i <= N << 1; ++i)

        cy[find(i)]++;

    for (int i = 1; i <= N; ++i)

        cx[find(i)]++;

    long long ans = 0;

    for (int i = 1; i <= N << 1; ++i)

        ans += 1ll * cx[i] * cy[i];

    cout << ans - n;

    return 0;

}
