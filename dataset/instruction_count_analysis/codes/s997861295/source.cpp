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

#include <stack>

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

//const long long MOD = 998244353;



using namespace std;



ll a[505][505];

ll c[505][505];



void solve()

{

    int n,m,Q;

    scanf("%d%d%d", &n, &m, &Q);

    int i,j;

    for(i=0; i<m; i++) {

        int l,r;

        scanf("%d%d", &l, &r); l--; r--;

        a[l][r]++;

    }

    for (i = 0; i < n; i++) {

        for(j = 0; j< n; j++) {

            c[i+1][j+1] = c[i][j+1]+c[i+1][j]-c[i][j]+a[i][j];

        }

    }



    for (i = 0; i < Q; i++) {

        int p,q;

        scanf("%d%d", &p, &q); p--;

        printf("%lld\n", c[q][q]- c[p][q] - c[q][p] +c[p][p]);

    }



    return;

}





int main(int argc, char* argv[])

{

#if 1

	solve();

#else

	int T; scanf("%d", &T);

	while (T--) {

		solve();

	}

#endif

	return 0;

}
