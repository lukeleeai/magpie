#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>

using namespace std;



#define N 105

#define eps 1e-8

#define INF 1e30



inline double sqr(double x) {

    return x * x;

}



int n, m;

double a[N][N], b[N][N], d[N][N];



double gao(int p, int q) {

    double s1 = 0, s2 = 0;

    for (int i = 1; i <= m; ++i) {

        s1 += a[p][i] * a[q][i];

        s2 += sqr(a[q][i]);

    }

    if (abs(s2) < eps) {

        double s = 0;

        for (int i = 1; i <= m; ++i)

            s += sqr(a[p][i]);

        return s;

    }

    double k = s1 / s2;

    double ret = 0;

    for (int i = 1; i <= m; ++i)

        ret += sqr(k * a[q][i] - a[p][i]);

    return ret;

}



double f[N];

bool vis[N];

double g[N][N];



int pre[N];

bool del[N], vst[N];

double solve(int v) {

    double res = 0;

    int num = n;

    memset(del, false, sizeof(del));

    while(1) {

        int i;

        //æ´æ°preæ°ç»

        for (i = 1; i <= n; ++i) {

            if (del[i] || i == v) continue;

            pre[i] = i;

            g[i][i] = INF;

            for (int j = 1; j <= n; ++j) {

                if (del[j]) continue;

                if (g[j][i] < g[pre[i]][i])

                    pre[i] = j;

            }

        }

        for (i = 1; i <= n; ++i) {

            //æ¾ç¯

            if (del[i] || i == v) continue;

            int j = i;

            memset(vst, 0, sizeof(vst));

            while (!vst[j] && j != v) {

                vst[j] = true;

                j = pre[j];

            }

            if (j == v) continue;

            i = j;

            //æ´æ°resï¼æåç¯ç¼©ç¹

            res += g[pre[i]][i];

            for(j = pre[i]; j != i; j = pre[j]) {

                res += g[pre[j]][j];

                del[j] = true;

            }

            for(j = 1; j <= n; ++j) {

                if(del[j]) continue;

                if(g[j][i] != INF)

                    g[j][i] -= g[pre[i]][i];

            }

            //æ´æ°ç¼©ç¹ä»¥åçæåç¯åå¶ä»ç¹çè¾¹æ

            for(j = pre[i]; j != i; j = pre[j]) {

                for(int k = 1; k <= n; ++k) {

                    if(del[k])continue;

                    g[i][k] = min(g[i][k], g[j][k]);

                    if(g[k][j] != INF)

                        g[k][i] = min(g[k][i], g[k][j] - g[pre[j]][j]);

                }

            }

            //å®æç¼©ç¹

            break;

        }

        //ä¸å­å¨æåç¯æ¶ï¼åæ­¢å¾ªç¯ï¼å¾åºresæç»å¼

        if(i > n) {

            for(int i = 1; i <= n; ++i) {

                if(del[i] || i == v) continue;

                res += g[pre[i]][i];

            }

            break;

        }

    }

    return res;

}



int main() {

    scanf("%d %d", &m, &n);

    for (int i = 1; i <= n; ++i)

        for (int j = 1; j <= m; ++j)

            scanf("%lf", &a[i][j]);

    for (int i = 1; i <= n; ++i)

        for (int j = 1; j <= n; ++j)

            d[i][j] = gao(j, i);

    double ans = INF;/*

    for (int i = 1; i <= n; ++i, puts(""))

        for (int j = 1; j <= n; ++j)

            printf(" %.3f", d[i][j]);*/

    for (int i = 1; i <= n; ++i) {

        double s = 0;

        for (int j = 1; j <= m; ++j)

            s += sqr(a[i][j]);

        for (int j = 1; j <= n; ++j)

            memcpy(g[j], d[j], sizeof(d[j]));

        ans = min(ans, s + solve(i));

    }

    printf("%.8f\n", ans);

    return 0;

}