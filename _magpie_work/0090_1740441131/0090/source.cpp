#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)

typedef long long ll;

int Q;
int dp[64][64][64];

int dfs(int c, int a, int n) {
    if (dp[c][a][n] >= 0) return dp[c][a][n];
    int res = 0;
    if (c > 0 && a > 0 && n > 0) res = max(res, dfs(c - 1, a - 1, n - 1) + 1);
    if (c > 1 && a > 0) res = max(res, dfs(c - 2, a - 1, n) + 1);
    if (c > 2) res = max(res, dfs(c - 3, a, n) + 1);
    return dp[c][a][n] = res;
}

int main() {
    scanf("%d", &Q);
    rep(i, Q) {
        memset(dp, -1, sizeof(dp));
        int c, a, n;
        scanf("%d %d %d", &c, &a, &n);
        int res = 0;
        while (c > 8 && a > 4 && n > 0) {
            res++;
            c--;
            a--;
            n--;
        }
        while (c > 8 && a > 4) {
            res++;
            c -= 2;
            a--;
        }
        while (c > 8) {
            res++;
            c -= 3;
        }
        res += dfs(c, a, n);
        printf("%d\n", res);
    }
    return 0;
}
