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





ll a[16][16];



int main(int argc, char* argv[])

{

    int n;

    scanf("%d", &n);



    int i,j;

    for(i=0; i<n; i++) {

        for(j=0; j<n; j++) {

            scanf("%lld", &a[i][j]);

        }

    }



    vector<ll> dp(1<<n);

    int k;

    for(k=0; k<(1<<n); k++) {

        vector<int> z;

        for(i=0; i<n; i++) {

            if(k & (1<<i)) z.push_back(i); 

        }

        int siz=(int)z.size();



        dp[k]=0;

        for(i=0; i<siz; i++) {

            for(j=i+1; j<siz; j++) {

                dp[k] += a[z[i]][z[j]];

            }

        }



        ll max=0;

        for(i=0; i<(1<<siz); i++) {

            int tmp0=0;

            for(j=0; j<siz; j++) {

                if(i & (1<<j)) tmp0 |= (1<<z[j]);

            }

            ll val = dp[tmp0]+dp[k^tmp0];

            max = MAX(max, val);

        }

        dp[k] = max;

    }

    printf("%lld\n", dp[(1<<n)-1]);



    return 0;

}
