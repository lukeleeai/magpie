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



ll dp[3005][3005];



int main(int argc, char* argv[])

{

    int n;

    scanf("%d", &n);



    int i,j;

    for(i=0; i<n; i++) {

        scanf("%d", &dp[i][1]);

    }

    for(j=2; j<=n; j++) {

        for(i=0; i<=n-j; i++) {

            dp[i][j]=MAX(-dp[i][j-1]+dp[i+j-1][1], -dp[i+1][j-1]+dp[i][1]);

        }

    }

    printf("%lld\n", dp[0][n]);



    return 0;

}
