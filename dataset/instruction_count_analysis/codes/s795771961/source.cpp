#include <stdio.h>

#include <string>

#include <cstring>

#include <stdlib.h>

#include <math.h>

#include <algorithm>

#include <vector>

#include <set>

#include <map>

#include <queue>

#include <list>

#include <iterator>

#include <assert.h>

#pragma warning(disable:4996) 



typedef long long ll;

#define MIN(a, b) ((a)>(b)? (b): (a))

#define MAX(a, b) ((a)<(b)? (b): (a))

#define LINF 9223300000000000000

#define INF 2140000000

const long long MOD = 1000000007;

using namespace std;



ll dp[1<<8][8];



int main(int argc, char* argv[])

{

    int n,m;

    scanf("%d%d", &n, &m);



    int g[8][8]={0};

    int i;

    for(i=0; i<m; i++) {

        int a,b;

        scanf("%d%d", &a, &b);

        g[a-1][b-1]=1;

        g[b-1][a-1]=1;

    }



    dp[1][0]=1;

    for(i=2; i<(1<<n); i++) {

        int k;

        for(k=0; k<n; k++) {

            if(i & (1<<k)) {

                int prev = (i & ~(1<<k));

                int j;

                for(j=0; j<n; j++) {

                    if(dp[prev][j] && (prev & (1<<j)) && g[k][j]) {

                        dp[i][k] += dp[prev][j];

                    }

                }

            }

        }

    }

    ll ans=0;

    for(i=1; i<n; i++) {

        ans += dp[(1<<n)-1][i];

    }

    printf("%lld\n", ans);



    return 0;

}
