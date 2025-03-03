#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int x, y, z;
    while (scanf("%d%d%d", &x, &y, &z), x|y|z) {
        double p = 1.0 / x;
        int v[4], e[51], a[51];
        for (int i = 0; i < x; ++i)
            scanf("%d", v + i);
        memset(e, 0, sizeof(e));
        for (int i = 0; i < z; ++i) {
            int t;
            scanf("%d", &t);
            scanf("%d%d", e + t, a + t);
        }

        static double dp[51][5001] = {};
        dp[0][0] = 1;

        for (int i = 1; i <= y; ++i)
            fill(dp[i], dp[i] + 5001, 0);

        for (int i = 0; i < y; ++i) {
            for (int j = 0; j <= 5000; ++j) {
                for (int k = 0; k < x; ++k) {
                    int to = min(y, i + v[k]);
                    int money = j;
                    if (e[to] == 1)
                        to = min(y, to + a[to]);
                    else if (e[to] == 2)
                        money = min(5000, money + a[to]);
                    else if (e[to] == 3)
                        money = max(0, money - a[to]);
                    dp[to][money] += dp[i][j] * p;
                }
            }
        }

        double res = 0;
        for (int i = 0; i <= 5000; ++i)
            res += i * dp[y][i];
        printf("%d\n", (int)res);
    }
    return 0;
}
