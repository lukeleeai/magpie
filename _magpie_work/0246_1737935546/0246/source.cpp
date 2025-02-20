#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int C, D, W, X;
int E[15][30], F[15][30];
int dp[31][51][15][6];

int dfs(int day, int cost, int place, int two) {
    if(dp[day][cost][place][two] >= 0) return dp[day][cost][place][two];
    if(day == D) return 0;

    int ret = 0;
    for(int i = 0; i < C; ++i) ret = max(ret, dfs(day + 1, cost, i, two));

    if(E[place][day] > 0) {
        if(cost + F[place][day] <= W) {
            for(int i = 0; i < C; ++i) ret = max(ret, dfs(day + 1, cost + F[place][day], i, two) + E[place][day]);
        }
        if(two < X) {
            int tcost = cost + F[place][day];
            int tE = E[place][day];
            for(int now = place - 1; now >= 0; --now) {
                if(E[now][day] == 0 || tcost + F[now][day] > W) break;
                tcost += F[now][day];
                tE += E[now][day];
                for(int i = 0; i < C; ++i) ret = max(ret, dfs(day + 1, tcost, i, two + 1) + tE);
            }
            tcost = cost + F[place][day];
            tE = E[place][day];
            for(int now = place + 1; now < C; ++now) {
                if(E[now][day] == 0 || tcost + F[now][day] > W) break;
                tcost += F[now][day];
                tE += E[now][day];
                for(int i = 0; i < C; ++i) ret = max(ret, dfs(day + 1, tcost, i, two + 1) + tE);
            }
        }
    }
    dp[day][cost][place][two] = ret;
    return ret;
}

int main() {
    while(scanf(" %d %d %d %d", &C, &D, &W, &X), C) {
        for(int i = 0; i < C; ++i)
            for(int j = 0; j < D; ++j) scanf(" %d", &E[i][j]);
        for(int i = 0; i < C; ++i)
            for(int j = 0; j < D; ++j) scanf(" %d", &F[i][j]);

        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < C; ++i) ans = max(ans, dfs(0, 0, i, 0));
        printf("%d\n", ans);
    }
    return 0;
}
