#include <stdio.h>

#include <string.h>

#include <algorithm>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define INF (1<<28)



int N, M, C, u[2000], v[2000];

int g[128][128], dp[1024][128];



int main() {

    for(;;) {

        scanf("%d%d%d", &N, &M, &C);

        if(N==0) return 0;

        memset(g, -1, sizeof(g));

        rep(i, N) g[i][i] = 0;

        rep(i, M) {

            int w;

            scanf("%d%d%d", u+i, v+i, &w);

            u[i]--, v[i]--;

            g[u[i]][v[i]] = w;

        }

        rep(k, N) rep(i, N) if(g[i][k]!=-1) rep(j, N) if(g[k][j]!=-1) {

            if(g[i][j]==-1 || g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];

        }

        memset(dp, -1, sizeof(dp));

        rep(i, N) dp[0][i] = g[0][i];

        rep(k, M+1) {

            if(dp[k][N-1]<=C) {

                printf("%d\n", k);

                break;

            }

            rep(i, M) if(dp[k][u[i]]!=-1) rep(j, N) if(g[v[i]][j]!=-1) {

                if(dp[k+1][j]==-1 || dp[k+1][j]>dp[k][u[i]]+g[v[i]][j]) {

                    dp[k+1][j] = dp[k][u[i]]+g[v[i]][j];

                }

            }

        }

    }

}