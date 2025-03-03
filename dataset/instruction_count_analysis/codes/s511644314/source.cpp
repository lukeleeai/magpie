#include"stdc++.h"

#define REP(x,y,z) for(int x=y;x<=z;x++)

#define MSET(x,y) memset(x,y,sizeof(x))

#define M 405

using namespace std;

using LL = long long;

int n,a[M];

bool vis[M][M];

LL dp[M][M],pre[M];



LL dfs(int x,int y) {

    if (x==y) return 0LL;

    if (vis[x][y]) return dp[x][y];

    vis[x][y] = true;

    LL &res = dp[x][y];



    LL sum = pre[y] - pre[x-1];

    res = (1LL << 61);

    REP(i,x,y-1) res = min(res, dfs(x,i) + dfs(i+1,y) + sum);

    return res;

}

int main()

{

    scanf("%d", &n);

    REP(i,1,n) scanf("%d", &a[i]);



    pre[0] = 0;

    REP(i,1,n) pre[i] = pre[i-1] + a[i];

    printf("%lld\n", dfs(1,n));

    return 0;

}
